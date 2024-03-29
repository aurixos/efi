#ifndef EFI_H
#define EFI_H

#include "efi_types.h"

typedef struct {
	UINT64 Signature;
	UINT32 Revision;
	UINT32 HeaderSize;
	UINT32 CRC32;
	UINT32 Reserved;
} EFI_TABLE_HEADER;

#define EFI_GLOBAL_VARIABLE {0x8be4df61,0x93ca,0x11d2, {0xaa,0x0d,0x00,0xe0,0x98,0x03,0x2b,0x8c}}

// Variable-size array
#define ANYSIZE_ARRAY 1

// Event types

//

// Task Priority Levels
#define TPL_APPLICATION											4
#define TPL_CALLBACK											8
#define TPL_NOTIFY												16
#define TPL_HIGH_LEVEL											31
//

// Variable Attributes
#define EFI_VARIABLE_NON_VOLATILE								0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS							0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS								0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD						0x00000008
// NOTE: EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS is deprecated
// and should be considered reserved.
#define EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS					0x00000010
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS		0x00000020
#define EFI_VARIABLE_APPEND_WRITE								0x00000040
#define EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS				0x00000080

// EFI Open Protocol Attributes
#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL					0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL							0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL							0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER					0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER								0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE								0x00000020
//

// Memory Descriptor Version Number
#define EFI_MEMORY_DESCRIPTOR_VERSION							1

#include "efi_st.h"
#include "efi_rs.h"
#include "efi_bs.h"

#include "protocols/adapter_information.h"
#include "protocols/boot_manager_policy.h"
#include "protocols/bus_specific_driver_override.h"
#include "protocols/component_name2.h"
#include "protocols/device_path.h"
#include "protocols/driver_binding.h"
#include "protocols/driver_diagnostics2.h"
#include "protocols/driver_family_override.h"
#include "protocols/driver_health.h"
#include "protocols/driver_supported_efi_version.h"
#include "protocols/file.h"
#include "protocols/loaded_image.h"
#include "protocols/loaded_image_device_path.h"
#include "protocols/platform_driver_override.h"
#include "protocols/platform_to_driver_configuration.h"
#include "protocols/service_binding.h"
#include "protocols/simple_file_system.h"
#include "protocols/simple_text_input.h"
#include "protocols/simple_text_output.h"

#define EFI_ERROR(Status)								(((INTN)(EFI_STATUS)(Status)) < 0)

#endif /* EFI_H */
