#include <cstdint>

#ifndef BINARYPARSER_EXPORTDIRECTORYTABLE_HPP
#define BINARYPARSER_EXPORTDIRECTORYTABLE_HPP

namespace binary_parser::models::pe {
#pragma pack(2)
    struct export_directory_table {
        uint32_t export_flags;
        uint32_t time_date_stamp;
        uint16_t major_version;
        uint16_t minor_version;
        uint32_t name_rva;
        uint32_t ordinal_base;
        uint32_t address_table_entries;
        uint32_t number_of_name_pointers;
        uint32_t export_address_table_rva;
        uint32_t name_pointer_rva;
        uint32_t ordinal_table_rva;
    };
}

#endif //BINARYPARSER_EXPORTDIRECTORYTABLE_HPP
