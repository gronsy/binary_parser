#ifndef BINARYPARSER_ADDRESS_CALCULATOR_HPP
#define BINARYPARSER_ADDRESS_CALCULATOR_HPP

#include <cstdint>

namespace binary_parser::utils {
    class address_calculator {
        uint32_t pointer_to_raw_data, section_base_rva;
    public:
        address_calculator(const uint32_t pointer_to_raw_data, const uint32_t section_base_rva);

        uint32_t rva_to_raw_address(const uint32_t rva);
        uint32_t raw_to_rva_address(const uint32_t raw);
    };
}

#endif //BINARYPARSER_ADDRESS_CALCULATOR_HPP
