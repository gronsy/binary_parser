cmake_minimum_required(VERSION 3.22)
project(BinaryParser)
set(Boost_INCLUDE_DIR C:\\boost_1_55_0)

set(CMAKE_CXX_STANDARD 20)
find_package(Boost 1.55.0 COMPONENTS REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(BinaryParser main.cpp interfaces/i_parser.hpp models/pe/coff_header.hpp models/pe/optional_header.hpp models/pe/section_header.hpp models/pe/export_directory_table.hpp models/pe/import_directory_table.hpp utils/headers/binary_reader.hpp utils/source/binary_reader.cpp parsers/pe_parser/headers/pe_parser.hpp parsers/pe_parser/source/pe_parser.cpp utils/headers/constants.hpp exceptions/headers/invalid_signature_exception.hpp utils/headers/binary_parser_factory.hpp utils/source/binary_parser_factory.cpp exceptions/source/invalid_signature_exception.cpp parsers/elf_parser/headers/elf_parser.hpp parsers/elf_parser/source/elf_parser.cpp interfaces/i_metadata_parser.hpp base_classes/base_metadata_parser.hpp base_classes/base_parser.hpp parsers/pe_parser/headers/pe_metadata_parser.hpp parsers/pe_parser/source/pe_metadata_parser.cpp parsers/pe_parser/headers/header_types.hpp models/pe/pe_report.hpp models/pe/pe_header_info.hpp interfaces/i_data_parser.hpp base_classes/base_data_parser.hpp utils/headers/address_calculator.hpp utils/source/address_calculator.cpp exceptions/headers/invalid_reserved_value.hpp exceptions/source/invalid_reserved_value.cpp parsers/pe_parser/headers/pe_data_parser.hpp parsers/pe_parser/source/pe_data_parser.cpp parsers/pe_parser/headers/section_types.hpp)

