namespace binary_parser::parsers {
    enum class header_types {
        coff_header,
        standard_fields,
        windows_specific,
        data_directories,
        section_headers
    };
}
