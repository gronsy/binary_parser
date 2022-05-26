#pragma once
#include <cstdint>

#ifndef BINARYPARSER_OPTIONALHEADER_HPP
#define BINARYPARSER_OPTIONALHEADER_HPP

namespace binary_parser::models::pe {
#pragma pack(2)
    struct optional_header_standard_fields {
        uint16_t magic;
        uint8_t major_linker_version;
        uint8_t minor_linker_version;
        uint32_t size_of_code;
        uint32_t size_of_initialized_data;
        uint32_t size_of_uninitialized_data;
        uint32_t address_of_entry_point;
        uint32_t base_of_code;

        explicit optional_header_standard_fields(){}

        optional_header_standard_fields(const optional_header_standard_fields& standard_fields) :
                magic(standard_fields.magic), major_linker_version(standard_fields.major_linker_version),
                minor_linker_version(standard_fields.minor_linker_version), size_of_code(standard_fields.size_of_code),
                size_of_initialized_data(standard_fields.size_of_initialized_data), size_of_uninitialized_data(standard_fields.size_of_uninitialized_data),
                address_of_entry_point(standard_fields.address_of_entry_point), base_of_code(base_of_code)
        {}
    };

#pragma pack(2)
    struct optional_header_standard_fields32 : public optional_header_standard_fields {
        uint32_t base_of_data;

        optional_header_standard_fields32(const optional_header_standard_fields& optional_header_standard, uint32_t base_of_data) :
                optional_header_standard_fields(optional_header_standard), base_of_data(base_of_data) {}
    };

    struct optional_header_windows_specific_base {};

#pragma pack(2)
    struct optional_header_windows_specific32 : public optional_header_windows_specific_base {
        uint32_t image_base;
        uint32_t section_alignment;
        uint32_t file_alignment;
        uint16_t major_operating_system_version;
        uint16_t minor_operating_system_version;
        uint16_t major_image_version;
        uint16_t minor_image_version;
        uint16_t major_subsystem_version;
        uint16_t minor_subsystem_version;
        uint32_t win32_version_value;
        uint32_t size_of_image;
        uint32_t size_of_headers;
        uint32_t check_sum;
        uint16_t subsystem;
        uint16_t dll_characteristics;
        uint32_t size_of_stack_reserve;
        uint32_t size_of_stack_commit;
        uint32_t size_of_heap_reserve;
        uint32_t size_of_heap_commit;
        uint32_t loader_flags;
        uint32_t number_of_rva_and_sizes;
    };

#pragma pack(2)
    struct optional_header_windows_specific64 : public optional_header_windows_specific_base {
        uint64_t image_base;
        uint32_t section_alignment;
        uint32_t file_alignment;
        uint16_t major_operating_system_version;
        uint16_t minor_operating_system_version;
        uint16_t major_image_version;
        uint16_t minor_image_version;
        uint16_t major_subsystem_version;
        uint16_t minor_subsystem_version;
        uint32_t win32_version_value;
        uint32_t size_of_image;
        uint32_t size_of_headers;
        uint32_t check_sum;
        uint16_t subsystem;
        uint16_t dll_characteristics;
        uint64_t size_of_stack_reserve;
        uint64_t size_of_stack_commit;
        uint64_t size_of_heap_reserve;
        uint64_t size_of_heap_commit;
        uint32_t loader_flags;
        uint32_t number_of_rva_and_sizes;
    };

    struct data_directory {
        uint32_t virtual_address;
        uint32_t size;
    };

#pragma pack(2)
    struct optional_header_data_directories {
        data_directory export_table;
        data_directory import_table;
        data_directory resource_table;
        data_directory exception_table;
        data_directory certificate_table;
        data_directory base_relocation_table;
        data_directory debug;
        data_directory architecture;
        data_directory global_ptr;
        data_directory tls_table;
        data_directory load_config_table;
        data_directory bound_import;
        data_directory iat;
        data_directory delay_import_descriptor;
        data_directory clr_runtime_header;
        data_directory reserved_is_zero;
    };
}

#endif //BINARYPARSER_OPTIONALHEADER_HPP
