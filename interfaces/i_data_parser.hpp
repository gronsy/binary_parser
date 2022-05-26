#ifndef BINARYPARSER_I_DATA_PARSER_HPP
#define BINARYPARSER_I_DATA_PARSER_HPP

namespace binary_parser::interfaces {
    class i_data_parser {
    public:
        virtual void parse_data() = 0;
    };
}

#endif //BINARYPARSER_I_DATA_PARSER_HPP
