#ifndef BINARYPARSER_BASE_PARSER_HPP
#define BINARYPARSER_BASE_PARSER_HPP

#include "../interfaces/i_parser.hpp"
#include "../utils/headers/binary_reader.hpp"

namespace binary_parser::base_classes {
    class base_parser : public interfaces::i_parser {
    protected:
        utils::binary_reader reader;
    public:
        explicit base_parser(const std::string& file_path) : reader(file_path){}
        virtual ~base_parser() = default;
    };
}

#endif //BINARYPARSER_BASE_PARSER_HPP
