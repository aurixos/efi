#ifndef GUID_H
#define GUID_H

#include "efi_types.h"

// EFI GUID Definition
typedef struct EFI_GUID {
	UINT32 Data1;
	UINT16 Data2;
	UINT16 Data3;
	UINT8 Data4[8];
} EFI_GUID;

// Driver Signing
#define EFI_CERT_TYPE_RSA2048_SHA256_GUID {0xa7717414,0xc616,0x4977, {0x94,0x20,0x84,0x47,0x12,0xa7,0x35,0xbf}}
#define EFI_CERT_TYPE_PKCS7_GUID {0x4aafd29d,0x68df,0x49ee, {0x8a,0xa9,0x34,0x7d,0x37,0x56,0x65,0xa7}}

// Simple Text I/O Protocols
#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID {0x387477c1,0x69c7,0x11d2, {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}
#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID {0x387477c2,0x69c7,0x11d2, {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

// Simple File System Protocol
#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID {0x0964e5b22,0x6459,0x11d2, {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

// Boot Services
#define EFI_HII_PACKAGE_LIST_PROTOCOL_GUID {0x6a1ee763,0xd47a,0x43b4, {0xaa,0xbe,0xef,0x1d,0xe2,0xab,0x56,0xfc}}
#define EFI_DEVICE_PATH_PROTOCOL_GUID {0x09576e91,0x6d3f,0x11d2, {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

// Capsules
#define EFI_MEMORY_RANGE_CAPSULE_GUID {0xde9f0ec,0x88b6,0x428f, {0x97,0x7a,0x25,0x8f,0x1d,0xe,0x5e,0x72}}
#define EFI_CAPSULE_REPORT_GUID {0x39b68c46,0xf7fb,0x441b, {0xb6,0xec,0x16,0xb0,0xf6,0x98,0x21,0xf3}}

/**********************
 *    Global GUIDs    *
 **********************/
// EXTERN EFI_GUID gEfiCertTypeRsa2048Sha256Guid;
// EXTERN EFI_GUID gEfiCertTypePkcs7Guid;
// EXTERN EFI_GUID gSimpleTextInputProtocolGuid;
// EXTERN EFI_GUID gSimpleTextOutputProtocolGuid;
// EXTERN EFI_GUID gEfiSimpleFileSystemProtocolGuid;
// EXTERN EFI_GUID gEfiHiiPackageListProtocolGuid;
// EXTERN EFI_GUID gEfiDevicePathProtocolGuid;
// EXTERN EFI_GUID gEfiMemoryRangeCapsuleGuid;
// EXTERN EFI_GUID gEfiCapsuleReportGuid;
static EFI_GUID gEfiCertTypeRsa2048Sha256Guid = EFI_CERT_TYPE_RSA2048_SHA256_GUID;
static EFI_GUID gEfiCertTypePkcs7Guid = EFI_CERT_TYPE_PKCS7_GUID;
static EFI_GUID gSimpleTextInputProtocolGuid = EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID;
static EFI_GUID gSimpleTextOutputProtocolGuid = EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID;
static EFI_GUID gEfiSimpleFileSystemProtocolGuid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
static EFI_GUID gEfiHiiPackageListProtocolGuid = EFI_HII_PACKAGE_LIST_PROTOCOL_GUID;
static EFI_GUID gEfiDevicePathProtocolGuid = EFI_DEVICE_PATH_PROTOCOL_GUID;
static EFI_GUID gEfiMemoryRangeCapsuleGuid = EFI_MEMORY_RANGE_CAPSULE_GUID;
static EFI_GUID gEfiCapsuleReportGuid = EFI_CAPSULE_REPORT_GUID;

#endif /* GUID_H */
