#ifndef BINARYPARSER_ADDRESS_CALCULATOR_HPP
#define BINARYPARSER_ADDRESS_CALCULATOR_HPP

#include <cstdint>

namespace binary_parser::utils {
    class address_calculator {
    public:
        static uint32_t rva_to_raw_address();
        static uint32_t raw_to_rva_address();
    };
}

#endif //BINARYPARSER_ADDRESS_CALCULATOR_HPP
