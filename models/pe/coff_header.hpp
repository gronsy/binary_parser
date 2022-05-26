#pragma once
#include <cstdint>
#include <string>

#ifndef BINARYPARSER_COFF_HEADER_HPP
#define BINARYPARSER_COFF_HEADER_HPP

namespace binary_parser::models::pe {
#pragma pack(2)
    struct coff_header {
        uint16_t machine;
        uint16_t number_of_sections;
        uint32_t time_date_stamp;
        uint32_t pointer_to_symbol_table;
        uint32_t number_of_symbols;
        uint16_t size_of_optional_header;
        uint16_t characteristics;
    };
}

#endif //BINARYPARSER_COFF_HEADER_HPP
