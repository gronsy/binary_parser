#ifndef BINARYPARSER_BASEMETADATAREADER_HPP
#define BINARYPARSER_BASEMETADATAREADER_HPP

#include "../interfaces/i_metadata_parser.hpp"
#include "../utils/headers/binary_reader.hpp"

namespace binary_parser::base_classes {
    class base_metadata_extractor : public interfaces::i_metadata_parser {
    protected:
        utils::binary_reader reader;
    public:
        base_metadata_extractor(const std::string& file_path) : reader(file_path) {}
        virtual ~base_metadata_extractor() = default;
    };
}

#endif //BINARYPARSER_BASEMETADATAREADER_HPP
