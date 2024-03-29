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

#include "efi_st.h"
#include "efi_rs.h"
#include "efi_bs.h"

#include "protocols/boot_manager_policy.h"
#include "protocols/device_path.h"
#include "protocols/file.h"
#include "protocols/loaded_image.h"
#include "protocols/simple_file_system.h"
#include "protocols/simple_text_input.h"
#include "protocols/simple_text_output.h"
#include "protocols/uefi_driver_model.h"

#define EFI_ERROR(Status)								(((INTN)(EFI_STATUS)(Status)) < 0)

#endif /* EFI_H */
