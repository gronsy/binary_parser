#ifndef BINARYPARSER_IMETADATAREADER_HPP
#define BINARYPARSER_IMETADATAREADER_HPP

namespace binary_parser::interfaces {
    class i_metadata_parser {
    public:
        virtual void extract_metadata() = 0;
    };
}

#endif //BINARYPARSER_IMETADATAREADER_HPP
