#include "../headers/binary_reader.hpp"

binary_parser::utils::binary_reader::binary_reader(const std::string& file_path) : current_position(std::ios::beg) {
    binary_stream.open(file_path);
    binary_stream.seekg(0, std::ifstream::end);
    file_size=binary_stream.tellg();
    binary_stream.seekg(0, std::ifstream::beg);
}

binary_parser::utils::binary_reader::~binary_reader() {
    binary_stream.close();
}

const std::string& binary_parser::utils::binary_reader::extract_string_data(const int offset, const int length) {
    //TODO implement string extracting
    std::string s;
    return s;
}

uint16_t binary_parser::utils::binary_reader::extract_magic_number(const std::string &file_path) {
    std::ifstream file_stream;
    file_stream.open(file_path, std::ios::binary);
    uint16_t magic_number;
    file_stream.read(reinterpret_cast<char *>(&magic_number), sizeof(uint16_t));
    file_stream.close();

    return magic_number;
}
