#include "../headers/pe_parser.hpp"

binary_parser::parsers::pe_parser::pe_parser(const std::string &file_path) :
base_classes::base_parser(file_path), metadata_parser(file_path)
{}

void binary_parser::parsers::pe_parser::parse_binary() {
    parse_metadata();
    parse_data();
}

void binary_parser::parsers::pe_parser::parse_metadata() {
    metadata_parser.extract_metadata();
}

void binary_parser::parsers::pe_parser::parse_data() {

}
