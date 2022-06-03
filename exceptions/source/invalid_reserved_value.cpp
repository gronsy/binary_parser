#include "../headers/invalid_reserved_value.hpp"

binary_parser::exceptions::invalid_reserved_value::invalid_reserved_value(const uint32_t virtual_address, const uint32_t size) :
real_virtual_address(virtual_address), real_size(size) {}

const char *binary_parser::exceptions::invalid_reserved_value::what() const noexcept {
    std::string message{ "Value found in reserved section of data directories is invalid. Both values should be 0, but provided values are: \nSize: " +
    std::to_string(real_size) + "\nVirtual Address: " + std::to_string(real_virtual_address) };

    return message.data();
}
