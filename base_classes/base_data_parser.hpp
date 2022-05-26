#pragma once
#include "../interfaces/i_data_parser.hpp"
#include "../utils/headers/binary_reader.hpp"

#ifndef BINARYPARSER_BASE_DATA_PARSER_HPP
#define BINARYPARSER_BASE_DATA_PARSER_HPP

namespace binary_parser::base_classes {
    class base_data_parser : public interfaces::i_data_parser {
    protected:
        utils::binary_reader reader;
    public:
        base_data_parser(const std::string& file_path) : reader(file_path) {}
        virtual ~base_data_parser() = default;

        virtual void read_sections() = 0;
        virtual void extract_data() = 0;
    };
}

#endif //BINARYPARSER_BASE_DATA_PARSER_HPP
