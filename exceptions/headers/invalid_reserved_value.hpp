#ifndef BINARYPARSER_INVALID_RESERVED_VALUE_HPP
#define BINARYPARSER_INVALID_RESERVED_VALUE_HPP

#include <exception>
#include <string>

namespace binary_parser::exceptions {
    class invalid_reserved_value : public std::exception {
        int real_virtual_address, real_size;
    public:
        explicit invalid_reserved_value(const uint32_t virtual_address, const uint32_t size);

        const char* what() const noexcept override;
    };
}

#endif //BINARYPARSER_INVALID_RESERVED_VALUE_HPP
