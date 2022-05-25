#include <cstdint>

#ifndef BINARYPARSER_OPTIONALHEADER_HPP
#define BINARYPARSER_OPTIONALHEADER_HPP

namespace binary_parser::models::pe {
#pragma pack(2)
    struct optional_header_standard_fields {
        uint16_t magic;
        uint8_t major_linker_version;
        uint8_t minor_linker_version;
        uint32_t size_of_code;
        uint32_t size_of_initialized_data;
        uint32_t size_of_uninitialized_data;
        uint32_t address_of_entry_point;
        uint32_t base_of_code;

        explicit optional_header_standard_fields(){}

        optional_header_standard_fields(const optional_header_standard_fields& standard_fields) :
                magic(standard_fields.magic), major_linker_version(standard_fields.major_linker_version),
                minor_linker_version(standard_fields.minor_linker_version), size_of_code(standard_fields.size_of_code),
                size_of_initialized_data(standard_fields.size_of_initialized_data), size_of_uninitialized_data(standard_fields.size_of_uninitialized_data),
                address_of_entry_point(standard_fields.address_of_entry_point), base_of_code(base_of_code)
        {}
    };

#pragma pack(2)
    struct optional_header_standard_fields32 : public optional_header_standard_fields {
        uint32_t base_of_data;

        optional_header_standard_fields32(const optional_header_standard_fields& optional_header_standard, uint32_t base_of_data) :
                optional_header_standard_fields(optional_header_standard), base_of_data(base_of_data) {}
    };

    struct optional_header_windows_specific_base {};

#pragma pack(2)
    struct optional_header_windows_specific32 : public optional_header_windows_specific_base {
        uint32_t image_base;
        uint32_t section_alignment;
        uint32_t file_alignment;
        uint16_t major_operating_system_version;
        uint16_t minor_operating_system_version;
        uint16_t major_image_version;
        uint16_t minor_image_version;
        uint16_t major_subsystem_version;
        uint16_t minor_subsystem_version;
        uint32_t win32_version_value;
        uint32_t size_of_image;
        uint32_t size_of_headers;
        uint32_t check_sum;
        uint16_t subsystem;
        uint16_t dll_characteristics;
        uint32_t size_of_stack_reserve;
        uint32_t size_of_stack_commit;
        uint32_t size_of_heap_reserve;
        uint32_t size_of_heap_commit;
        uint32_t loader_flags;
        uint32_t number_of_rva_and_sizes;
    };

#pragma pack(2)
    struct optional_header_windows_specific64 : public optional_header_windows_specific_base {
        uint64_t image_base;
        uint32_t section_alignment;
        uint32_t file_alignment;
        uint16_t major_operating_system_version;
        uint16_t minor_operating_system_version;
        uint16_t major_image_version;
        uint16_t minor_image_version;
        uint16_t major_subsystem_version;
        uint16_t minor_subsystem_version;
        uint32_t win32_version_value;
        uint32_t size_of_image;
        uint32_t size_of_headers;
        uint32_t check_sum;
        uint16_t subsystem;
        uint16_t dll_characteristics;
        uint64_t size_of_stack_reserve;
        uint64_t size_of_stack_commit;
        uint64_t size_of_heap_reserve;
        uint64_t size_of_heap_commit;
        uint32_t loader_flags;
        uint32_t number_of_rva_and_sizes;
    };

#pragma pack(2)
    struct optional_header_data_directories : public optional_header_windows_specific_base {
        uint64_t export_table;
        uint64_t import_table;
        uint64_t resource_table;
        uint64_t exception_table;
        uint64_t certificate_table;
        uint64_t base_relocation_table;
        uint64_t debug;
        uint64_t architecture;
        uint64_t global_ptr;
        uint64_t tls_table;
        uint64_t load_config_table;
        uint64_t bound_import;
        uint64_t iat;
        uint64_t delay_import_descriptor;
        uint64_t clr_runtime_header;
        uint64_t reserved_is_zero;
    };
}

#endif //BINARYPARSER_OPTIONALHEADER_HPP
