#include "../headers/pe_data_parser.hpp"

binary_parser::parsers::pe_data_parser::pe_data_parser(const std::string &file_path, models::pe::data_directories& data_directories, std::vector<models::pe::section_header> section_table) :
base_classes::base_data_parser(file_path), data_directories(data_directories), section_table(section_table) {}

void binary_parser::parsers::pe_data_parser::read_sections() {
}

void binary_parser::parsers::pe_data_parser::extract_data() {}
