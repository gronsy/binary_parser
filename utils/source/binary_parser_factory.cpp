#include "../headers/binary_parser_factory.hpp"
#include "../../parsers/elf_parser/headers/elf_parser.hpp"

binary_parser::interfaces::i_parser* binary_parser::utils::binary_parser_factory::create_binary_parser(const std::string& file_path) {
    uint16_t magic_number = binary_reader::extract_magic_number(file_path);
    interfaces::i_parser* parser;

    switch (magic_number) {
        case constants::pe_magic_number:
            parser = new binary_parser::parsers::pe_parser(file_path);
            break;
        case constants::elf_magic_number:
            parser = new binary_parser::parsers::elf_parser(file_path);
            break;
        default:
            throw exceptions::invalid_signature_exception { magic_number };
    }

    return parser;
}

void binary_parser::utils::binary_parser_factory::delete_parser_object(interfaces::i_parser* parser) {
    delete parser;
    parser = nullptr;
}
