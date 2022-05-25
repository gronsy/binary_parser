#include "../headers/invalid_signature_exception.hpp"

//TODO: if it will be needed change to uint16_t
binary_parser::exceptions::invalid_signature_exception::invalid_signature_exception(
        const uint32_t faulty_signature): faulty_signature(faulty_signature) {}

const char *binary_parser::exceptions::invalid_signature_exception::what() const noexcept {
    return &"Signature  invalid, provided signature is: " [ faulty_signature ];
}
