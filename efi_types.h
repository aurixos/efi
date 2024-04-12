#ifndef _SEL_EFITYPES_H
#define _SEL_EFITYPES_H

// ************************************ //
// Status codes                         //
// ************************************ //

//
// Success Codes
//
#define EFI_SUCCESS													(0x00)

//
// Warning Codes
//
#define EFI_WARN_UNKNOWN_GLYPH										(0x01)
#define EFI_WARN_DELETE_FAILURE										(0x02)
#define EFI_WARN_WRITE_FAILURE										(0x03)
#define EFI_WARN_BUFFER_TOO_SMALL									(0x04)
#define EFI_WARN_STALE_DATA											(0x05)
#define EFI_WARN_FILE_SYSTEM										(0x06)
#define EFI_WARN_RESET_REQUIRED										(0x07)

//
// Error Codes
//
#define EFI_LOAD_ERROR												(0x8000000000000001)
#define EFI_INVALID_PARAMETER										(0x8000000000000002)
#define EFI_UNSUPPORTED												(0x8000000000000003)
#define EFI_BAD_BUFFER_SIZE											(0x8000000000000004)
#define EFI_BUFFER_TOO_SMALL										(0x8000000000000005)
#define EFI_NOT_READY												(0x8000000000000006)
#define EFI_DEVICE_ERROR											(0x8000000000000007)
#define EFI_WRITE_PROTECTED											(0x8000000000000008)
#define EFI_OUT_OF_RESOURCES										(0x8000000000000009)
#define EFI_VOLUME_CORRUPTED										(0x800000000000000A)
#define EFI_VOLUME_FULL												(0x800000000000000B)
#define EFI_NO_MEDIA												(0x800000000000000C)
#define EFI_MEDIA_CHANGED											(0x800000000000000D)
#define EFI_NOT_FOUND												(0x800000000000000E)
#define EFI_ACCESS_DENIED											(0x800000000000000F)
#define EFI_NO_RESPONSE												(0x8000000000000010)
#define EFI_NO_MAPPING												(0x8000000000000011)
#define EFI_TIMEOUT													(0x8000000000000012)
#define EFI_NOT_STARTED												(0x8000000000000013)
#define EFI_ALREADY_STARTED											(0x8000000000000014)
#define EFI_ABORTED													(0x8000000000000015)
#define EFI_ICMP_ERROR												(0x8000000000000016)
#define EFI_TFTP_ERROR												(0x8000000000000017)
#define EFI_PROTOCOL_ERROR											(0x8000000000000018)
#define EFI_INCOMPATIBLE_VERSION									(0x8000000000000019)
#define EFI_SECURITY_VIOLATION										(0x800000000000001A)
#define EFI_CRC_ERROR												(0x800000000000001B)
#define EFI_END_OF_MEDIA											(0x800000000000001C)
#define EFI_END_OF_FILE												(0x800000000000001F)
#define EFI_INVALID_LANGUAGE										(0x8000000000000020)
#define EFI_COMPROMISED_DATA										(0x8000000000000021)
#define EFI_IP_ADDRESS_CONFLICT										(0x8000000000000022)
#define EFI_HTTP_ERROR												(0x8000000000000023)

// ************************************ //
// Function modifiers                   //
// ************************************ //

#define IN
#define OUT
#define OPTIONAL
#define CONST const
#define STATIC static

// ************************************ //
// Common data types                    //
// ************************************ //

//
// Include architecture-specific type definitions
//
#if EFI_ARCH_AARCH64 == 1
# include "arch/aarch64/types.h"
#elif EFI_ARCH_X86_64 == 1
# include "arch/x86_64/types.h"
#else
# error "No valid architecture specified!"
#endif

//
// BOOLEAN values
//
#define FALSE 0
#define TRUE 1

//
// BOOL type
//
typedef BOOLEAN BOOL;

//
// Status Code
//
typedef UINTN EFI_STATUS;

//
// Status Code
//
typedef VOID *EFI_HANDLE;

//
// Status Code
//
typedef VOID *EFI_EVENT;

//
// Logical Block Address
//
typedef UINT64 EFI_LBA;

//
// Task Priority Level
//
typedef UINTN EFI_TPL;

//
// GUID
//
typedef struct {
	UINT32 Data1;
	UINT16 Data2;
	UINT16 Data3;
	UINT8 Data4[8];
} EFI_GUID;

//
// MAC Address
//
typedef struct {
	UINT8 Addr[32];
} EFI_MAC_ADDRESS;

//
// IPv4 Address
//
typedef struct {
	UINT8 Addr[4];
} EFI_IPv4_ADDRESS;

//
// IPv6 Address
//
typedef struct {
	UINT8 Addr[16];
} EFI_IPv6_ADDRESS;

//
// IP Address
//
typedef union {
	UINT32 Addr[4];
	EFI_IPv4_ADDRESS v4;
	EFI_IPv6_ADDRESS v6;
} EFI_IP_ADDRESS;

#endif /* _SEL_EFITYPES_H */
