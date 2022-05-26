#ifndef BINARYPARSER_ELFPARSER_H
#define BINARYPARSER_ELFPARSER_H

#include "../../../base_classes/base_parser.hpp"
#include "../../../interfaces/i_parser.hpp"

namespace binary_parser::parsers{
    class elf_parser : public base_classes::base_parser {
    public:
        elf_parser(const std::string& file_path);
        ~elf_parser() override = default;

        void parse_binary() override;
        virtual void parse_metadata() override;
        virtual void parse_data() override;
    };
}

#endif //BINARYPARSER_ELFPARSER_H
