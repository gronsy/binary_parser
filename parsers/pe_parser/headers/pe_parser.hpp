#pragma once
#include "../../../base_classes/base_parser.hpp"
#include "../../../interfaces/i_parser.hpp"
#include "../../../utils/headers/constants.hpp"
#include "../../../exceptions/headers/invalid_signature_exception.hpp"
#include "pe_metadata_parser.hpp"
#include <string>

#ifndef BINARYPARSER_PEPARSER_HPP
#define BINARYPARSER_PEPARSER_HPP

namespace binary_parser::parsers {
    class pe_parser : public base_classes::base_parser {
        pe_metadata_parser metadata_parser;

    private:
        std::string& extract_msdos_stub();
        std::string& extract_pe_signature();
    public:
        explicit pe_parser(const std::string& file_path);
        ~pe_parser() override = default;

        virtual void parse_binary() override;
        virtual void parse_metadata() override;
        virtual void parse_data() override;
    };
}

#endif //BINARYPARSER_PEPARSER_HPP
