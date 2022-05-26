#ifndef BINARYPARSER_BINARYREADER_HPP
#define BINARYPARSER_BINARYREADER_HPP

#include <fstream>
#include <string>

#include "../../exceptions/headers/invalid_signature_exception.hpp"

namespace binary_parser::utils {
    class binary_reader {
        std::ifstream binary_stream;
        std::streamoff file_size, current_position;
    public:
        explicit binary_reader(const std::string& file_path);
        ~binary_reader();

        template<typename T>
        const T& read_data(const unsigned offset, bool reverse_offset = false) {
            if(file_size < offset){
                throw std::out_of_range("Provided offset is bigger than file size.");
            }

            binary_stream.seekg(offset, std::ifstream::beg);

            T read_data;
            binary_stream.read(reinterpret_cast<char*>(&read_data), sizeof(T));
            current_position=binary_stream.tellg();

            if(reverse_offset) {
                binary_stream.seekg(-sizeof(T), std::ios_base::cur);
            }

            return read_data;
        }

        static uint16_t extract_magic_number(const std::string& file_path);

        const std::string& extract_string_data(const int offset,const int length);
    };
}
#endif //BINARYPARSER_BINARYREADER_HPP
