#ifndef BINARYPARSER_CONSTANTS_HPP
#define BINARYPARSER_CONSTANTS_HPP

#include <cstdint>

namespace binary_parser::utils::constants {
    // PE constants
    constexpr uint16_t pe_magic_number = 0x5A4D;
    constexpr uint8_t pe_signature_offset = 0x3C;
    constexpr uint16_t pe_signature = 0x4550;
    constexpr uint16_t optional_header_magic_pe32 = 0x10B;
    constexpr uint16_t optional_header_magic_pe64 = 0x20B;

    // ELF constants
    constexpr uint8_t elf_magic_number = 0x7f;
}

#endif //BINARYPARSER_CONSTANTS_HPP
