#pragma once
#include <vector>

#include "coff_header.hpp"
#include "optional_header.hpp"
#include "section_header.hpp"

#ifndef BINARYPARSER_PE_HEADER_INFO_HPP
#define BINARYPARSER_PE_HEADER_INFO_HPP

namespace binary_parser::models::pe {
    struct pe_header_info {
        uint32_t pe_signature;
        coff_header coff;
        optional_header_standard_fields* optional_header_standard;
        optional_header_windows_specific_base* optional_header_windows;
        optional_header_data_directories data_directories;
        std::vector<section_header> section_table;

        ~pe_header_info() {
            delete optional_header_standard;
            optional_header_standard = nullptr;
            delete optional_header_windows;
            optional_header_standard = nullptr;
        }
    };
}

#endif //BINARYPARSER_PE_HEADER_INFO_HPP
