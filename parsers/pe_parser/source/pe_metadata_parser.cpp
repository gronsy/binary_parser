#include "../headers/pe_metadata_parser.hpp"

binary_parser::parsers::pe_metadata_parser::pe_metadata_parser(const std::string &file_path) : base_classes::base_metadata_extractor(file_path) {
    map_optional_header_offsets();
}

const binary_parser::models::pe::pe_header_info &binary_parser::parsers::pe_metadata_parser::get_header_info() const {
    return header_info;
}

void binary_parser::parsers::pe_metadata_parser::map_optional_header_offsets() {
    signature_offset = reader.read_data<uint16_t>(utils::constants::pe_signature_offset);

    header_offsets.insert({header_types::coff_header, signature_offset + sizeof(uint32_t)});
    header_offsets.insert({header_types::standard_fields, header_offsets[header_types::coff_header] + sizeof(models::pe::coff_header)});
    header_offsets.insert({header_types::windows_specific, header_offsets[header_types::standard_fields] + sizeof(models::pe::optional_header_standard_fields)});
    magic = reader.read_data<uint16_t>(header_offsets[header_types::standard_fields], true);

    if(magic == utils::constants::optional_header_magic_pe32) {
        header_offsets[header_types::windows_specific] += sizeof(uint32_t);
        header_offsets.insert({header_types::data_directories, header_offsets[header_types::windows_specific] + sizeof(models::pe::optional_header_windows_specific32)});
    } else {
        header_offsets.insert({header_types::data_directories, header_offsets[header_types::windows_specific] + sizeof(models::pe::optional_header_windows_specific64)});
    }

    header_offsets.insert({header_types::section_headers, header_offsets[header_types::data_directories] + sizeof(models::pe::optional_header_data_directories)});
}

binary_parser::models::pe::optional_header_standard_fields* binary_parser::parsers::pe_metadata_parser::extract_standard_fields() {
    models::pe::optional_header_standard_fields standard_fields;
    standard_fields = reader.read_data<models::pe::optional_header_standard_fields>(
            header_offsets[header_types::standard_fields]);

    uint32_t base_of_data;
    models::pe::optional_header_standard_fields* standard_fields_ptr;
    if(magic == utils::constants::optional_header_magic_pe32) {
        base_of_data = reader.read_data<uint32_t>(header_offsets[header_types::windows_specific] - sizeof(uint32_t), true);
        standard_fields_ptr = new models::pe::optional_header_standard_fields32(standard_fields, base_of_data);
        return standard_fields_ptr;
    }

    standard_fields_ptr = new models::pe::optional_header_standard_fields(standard_fields);
    return standard_fields_ptr;
}

binary_parser::models::pe::optional_header_windows_specific_base* binary_parser::parsers::pe_metadata_parser::extract_windows_specific_optional_header() {
    models::pe::optional_header_windows_specific_base *windows_specific_fields = nullptr;

    switch(header_info.optional_header_standard->magic) {
        case utils::constants::optional_header_magic_pe32: {
            auto windows_fields32 = reader.read_data<models::pe::optional_header_windows_specific32>(
                    header_offsets[header_types::windows_specific]);
            windows_specific_fields = new models::pe::optional_header_windows_specific32(windows_fields32);
            break;
        }
        case utils::constants::optional_header_magic_pe64: {
            auto windows_fields64 = reader.read_data<models::pe::optional_header_windows_specific64>(
                    header_offsets[header_types::windows_specific]);
            windows_specific_fields = new models::pe::optional_header_windows_specific64(windows_fields64);
            break;
        }
        default: {
            break;
        }
    }

    return windows_specific_fields;
}

void binary_parser::parsers::pe_metadata_parser::extract_optional_headers() {
    header_info.optional_header_standard = extract_standard_fields();
    header_info.optional_header_windows = extract_windows_specific_optional_header();
    header_info.data_directories = reader.read_data<models::pe::optional_header_data_directories>(header_offsets[header_types::data_directories]);
}

void binary_parser::parsers::pe_metadata_parser::extract_section_headers() {
    for(int i = 0; i < header_info.coff.number_of_sections; ++i) {
        auto section_header = reader.read_data<models::section_header>(header_offsets[header_types::section_headers]);
        header_info.section_table.push_back(section_header);
    }
}

void binary_parser::parsers::pe_metadata_parser::check_pe_signature() {
    header_info.pe_signature = reader.read_data<uint32_t>(signature_offset);

    if(header_info.pe_signature != utils::constants::pe_signature) {
        throw exceptions::invalid_signature_exception { header_info.pe_signature };
    }
}

void binary_parser::parsers::pe_metadata_parser::extract_metadata() {
    check_pe_signature();
    header_info.coff = extract_header<models::pe::coff_header>(header_types::coff_header);

    extract_optional_headers();
    extract_section_headers();
}
