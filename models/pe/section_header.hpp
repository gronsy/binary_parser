#ifndef BINARYPARSER_SECTIONTABLE_HPP
#define BINARYPARSER_SECTIONTABLE_HPP

#include <cstdint>

namespace binary_parser::models {
#pragma pack(2)
    struct section_header {
        uint64_t name;
        uint32_t virtual_size;
        uint32_t virtual_address;
        uint32_t size_of_raw_data;
        uint32_t pointer_to_raw_data;
        uint32_t pointer_to_relocations;
        uint32_t pointer_to_line_numbers;
        uint16_t number_of_relocations;
        uint16_t number_of_line_numbers;
        uint32_t characteristics;
    };
}

#endif //BINARYPARSER_SECTIONTABLE_HPP
