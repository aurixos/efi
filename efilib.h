#ifndef EFI_EFILIB_H
#define EFI_EFILIB_H

#include "efi.h"

#define EFI_ERROR(status) (((EFI_INTN)(status)) < 0)

static inline const char *efi_status_to_str(EFI_STATUS s)
{
	switch (s) {
		case EFI_SUCCESS:
			return "Success";
		case EFI_LOAD_ERROR:
			return "Image failed to load";
		case EFI_INVALID_PARAMETER:
			return "Invalid parameter specified";
		case EFI_UNSUPPORTED:
			return "Operation not supported";
		case EFI_BAD_BUFFER_SIZE:
			return "Improper buffer size";
		case EFI_BUFFER_TOO_SMALL:
			return "Buffer is too small";
		case EFI_NOT_READY:
			return "No data pending";
		case EFI_DEVICE_ERROR:
			return "Device reported an error";
		case EFI_WRITE_PROTECTED:
			return "Device has write protection";
		case EFI_OUT_OF_RESOURCES:
			return "Out of resources";
		case EFI_VOLUME_CORRUPTED:
			return "File system is corrupted";
		case EFI_VOLUME_FULL:
			return "No more space on filesystem";
		case EFI_NO_MEDIA:
			return "No medium found";
		case EFI_MEDIA_CHANGED:
			return "Medium has changed";
		case EFI_NOT_FOUND:
			return "Item not found";
		case EFI_ACCESS_DENIED:
			return "Access denied";
		case EFI_NO_RESPONSE:
			return "Server was not found or did not respond";
		case EFI_NO_MAPPING:
			return "A mapping to a device doesn't exist";
		case EFI_TIMEOUT:
			return "Timeout";
		case EFI_NOT_STARTED:
			return "Protocol has not been started yet";
		case EFI_ALREADY_STARTED:
			return "Protocol has already been started";
		case EFI_ABORTED:
			return "Operation was aborted";
		case EFI_ICMP_ERROR:
			return "ICMP error";
		case EFI_TFTP_ERROR:
			return "TFTP error";
		case EFI_PROTOCOL_ERROR:
			return "Protocol error";
		case EFI_INCOMPATIBLE_VERSION:
			return "Incompatible version";
		case EFI_SECURITY_VIOLATION:
			return "Security violation";
		case EFI_CRC_ERROR:
			return "CRC error";
		case EFI_END_OF_MEDIA:
			return "End of media reached";
		case EFI_END_OF_FILE:
			return "End of file reached";
		case EFI_INVALID_LANGUAGE:
			return "Invalid language specified";
		case EFI_COMPROMISED_DATA:
			return "Security status of data is unknown or compromised";
		case EFI_IP_ADDRESS_CONFLICT:
			return "IP Address conflict";
		case EFI_HTTP_ERROR:
			return "HTTP Error";
		default:
			return "Unknown Error";
	}

	__builtin_unreachable();
	return "Unknown Error";
}

/* AxBoot-specific stuff */
#ifdef AXBOOT_UEFI

extern EFI_HANDLE gImageHandle;
extern EFI_SYSTEM_TABLE *gSystemTable;
extern EFI_BOOT_SERVICES *gBootServices;

#endif

#endif /* EFI_EFILIB_H */

