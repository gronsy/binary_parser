#include "../headers/address_calculator.hpp"

binary_parser::utils::address_calculator::address_calculator(const uint32_t pointer_to_raw_data, const uint32_t section_base_rva) :
pointer_to_raw_data(pointer_to_raw_data), section_base_rva(section_base_rva) {}

uint32_t binary_parser::utils::address_calculator::rva_to_raw_address(const uint32_t rva) {
    uint32_t raw_address = (rva - section_base_rva) + pointer_to_raw_data;

    return raw_address;
}

//TODO: change naming depending on looking for raw address
uint32_t binary_parser::utils::address_calculator::raw_to_rva_address(const uint32_t raw) {
    return 0;
}
