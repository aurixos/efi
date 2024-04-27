#ifndef EFI_EFILIB_H
#define EFI_EFILIB_H

#include "efi.h"
#include "efi_st.h"

#define EFI_ERROR(status) (((INTN)(status)) < 0)

static EFI_HANDLE g_ImageHandle;
static EFI_SYSTEM_TABLE *g_SystemTable;
static EFI_BOOT_SERVICES *g_BootServices;

static inline void EfiLibInitialize(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	g_ImageHandle = ImageHandle;
	g_SystemTable = SystemTable;
	g_BootServices = SystemTable->BootServices;
}

#endif /* EFI_EFILIB_H */

