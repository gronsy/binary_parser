#ifndef BINARYPARSER_I_PARSER_HPP
#define BINARYPARSER_I_PARSER_HPP

namespace binary_parser::interfaces {
        class i_parser {
        public:
            virtual void parse_binary()=0;
            virtual void parse_metadata() = 0;
            virtual void parse_data() = 0;
        };
    }

#endif //BINARYPARSER_I_PARSER_HPP
