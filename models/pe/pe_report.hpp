#pragma once
#include "coff_header.hpp"
#include "export_directory_table.hpp"
#include "import_directory_table.hpp"
#include "optional_header.hpp"

#ifndef BINARYPARSER_PE_REPORT_HPP
#define BINARYPARSER_PE_REPORT_HPP

namespace binary_parser::models::pe {
    struct pe_report {
        coff_header coff;
        export_directory_table export_table;
        import_directory_table import_table;
        optional_header_windows_specific<T> optional_header_windows;
    };
}

#endif //BINARYPARSER_PE_REPORT_HPP
