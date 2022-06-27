#ifndef BINARYPARSER_PE_DATA_PARSER_HPP
#define BINARYPARSER_PE_DATA_PARSER_HPP

#include <string>
#include <vector>

#include "../../../base_classes/base_data_parser.hpp"
#include "../../../utils/headers/address_calculator.hpp"

#include "../../../models/pe/pe_header_info.hpp"
#include "../../../models/pe/export_directory_table.hpp"
#include "../../../models/pe/import_directory_table.hpp"

namespace binary_parser::parsers {
    class pe_data_parser : public base_classes::base_data_parser {
        models::pe::data_directories& data_directories;
        std::vector<models::pe::section_header>& section_table;

    public:
        explicit pe_data_parser(const std::string& file_path, models::pe::data_directories& data_directories, std::vector<models::pe::section_header> section_table);
        ~pe_data_parser() override = default;

        void read_sections() override;
        void extract_data() override;
    //TODO: finish implementing section reading method
//        template<typename T>
//        T read_section(const uint32_t virtual_address) {
//
//        }
    };
}

#endif //BINARYPARSER_PE_DATA_PARSER_HPP
