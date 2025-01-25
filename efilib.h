#ifndef EFI_EFILIB_H
#define EFI_EFILIB_H

#include "efi.h"

#define EFI_ERROR(status) (((EFI_INTN)(status)) < 0)

/* AxBoot-specific stuff */
#ifdef AXBOOT_UEFI

extern EFI_HANDLE gImageHandle;
extern EFI_SYSTEM_TABLE *gSystemTable;
extern EFI_BOOT_SERVICES *gBootServices;

#endif

#endif /* EFI_EFILIB_H */

