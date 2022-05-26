#pragma once
#include <cstdint>

#ifndef BINARYPARSER_IMPORTDIRECTORYTABLE_HPP
#define BINARYPARSER_IMPORTDIRECTORYTABLE_HPP

namespace binary_parser::models::pe {
#pragma pack(2)
    struct import_directory_table {
        uint32_t import_lookup_table_rva;
        uint32_t time_date_stamp;
        uint32_t forwarder_chain;
        uint32_t name_rva;
        uint32_t import_address_table_rva_thunk;
    };
}

#endif //BINARYPARSER_IMPORTDIRECTORYTABLE_HPP
