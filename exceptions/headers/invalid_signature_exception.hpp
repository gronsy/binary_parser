#ifndef BINARYPARSER_BAD_MAGIC_EXCEPTION_HPP
#define BINARYPARSER_BAD_MAGIC_EXCEPTION_HPP

#include <exception>
#include <cstdint>
#include <string>

namespace binary_parser::exceptions {
    class invalid_signature_exception : public std::exception {
        uint32_t faulty_signature;
    public:
        explicit invalid_signature_exception(const uint32_t faulty_signature);

        const char* what() const noexcept override;
    };
}

#endif //BINARYPARSER_BAD_MAGIC_EXCEPTION_HPP
