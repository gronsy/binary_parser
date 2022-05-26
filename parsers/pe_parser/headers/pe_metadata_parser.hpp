#pragma once
#include <map>

#include "../../../base_classes/base_metadata_parser.hpp"
#include "../../../models/pe/coff_header.hpp"
#include "../../../models/pe/optional_header.hpp"
#include "../../../models/pe/pe_header_info.hpp"
#include "../../../utils/headers/constants.hpp"
#include "../../../exceptions/headers/invalid_signature_exception.hpp"
#include "header_types.hpp"

#ifndef BINARYPARSER_PE_METADATA_PARSER_HPP
#define BINARYPARSER_PE_METADATA_PARSER_HPP

namespace binary_parser::parsers {
    class pe_metadata_parser : public base_classes::base_metadata_extractor {
        std::map<header_types, unsigned> header_offsets;
        models::pe::pe_header_info header_info;
        uint16_t magic, signature_offset;

    private:
        models::pe::optional_header_standard_fields* extract_standard_fields();
        models::pe::optional_header_windows_specific_base* extract_windows_specific_optional_header();
        void map_optional_header_offsets();
        void check_pe_signature();
    public:
        explicit pe_metadata_parser(const std::string& file_path);
        ~pe_metadata_parser() override = default;

        const models::pe::pe_header_info& get_header_info() const;

        void extract_metadata() override;
        void extract_optional_headers();
        void extract_section_headers();

        template<typename T>
        T extract_header(header_types header_type) {
            auto header = reader.read_data<T>(header_offsets[header_type]);

            return header;
        }
    };
}

#endif //BINARYPARSER_PE_METADATA_PARSER_HPP