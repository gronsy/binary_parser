#include <string>
#include "utils/headers/binary_parser_factory.hpp"

int main(int argc, char *argv[]) {
    std::string file_path{"test_files\\vs_installer.exe"};
    auto parser = binary_parser::utils::binary_parser_factory::create_binary_parser(file_path);
    parser->parse_binary();
    binary_parser::utils::binary_parser_factory::delete_parser_object(parser);
}
