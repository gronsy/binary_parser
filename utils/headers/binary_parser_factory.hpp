#pragma once
#include <cstdint>
#include <stdexcept>

#include "binary_reader.hpp"
#include "../../interfaces/i_parser.hpp"
#include "../../parsers/pe_parser/headers/pe_parser.hpp"
#include "constants.hpp"

#ifndef BINARYPARSER_BINARYPARSERFACTORY_HPP
#define BINARYPARSER_BINARYPARSERFACTORY_HPP

namespace binary_parser::utils {
    class binary_parser_factory {
    public:
        static interfaces::i_parser* create_binary_parser(const std::string& file_path);
        static void delete_parser_object(interfaces::i_parser* parser);
    };
}

#endif //BINARYPARSER_BINARYPARSERFACTORY_HPP
