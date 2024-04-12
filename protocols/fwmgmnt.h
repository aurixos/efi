#ifndef EFI_PROTOCOLS_FWMGMNT_H
#define EFI_PROTOCOLS_FWMGMNT_H

////
// Firmware Management Protocol
///

#define EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GUID {0x86c77a67,0xb97,0x4633, {0xa1,0x87,0x49,0x10,0x4d,0x06,0x85,0xc7}}

// Image Attributes
#define IMAGE_ATTRIBUTE_IMAGE_UPDATABLE 0x0000000000000001
#define IMAGE_ATTRIBUTE_RESET_REQUIRED 0x0000000000000002
#define IMAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED 0x0000000000000004
#define IMAGE_ATTRIBUTE_IN_USE 0x0000000000000008
#define IMAGE_ATTRIBUTE_UEFI_IMAGE 0x0000000000000010
#define IMAGE_ATTRIBUTE_DEPENDENCY 0x0000000000000020

// Image Compatibility
#define IMAGE_COMPATIBILITY_CHECK_SUPPORTED 0x0000000000000001

// Descriptor Version exposed by GetImageInfo() function
#define EFI_FIRMWARE_IMAGE_DESCRIPTOR_VERSION 3

// ImageUpdatable
#define IMAGE_UPDATABLE_VALID 0x0000000000000001
#define IMAGE_UPDATABLE_INVALID 0x0000000000000002
#define IMAGE_UPDATABLE_INVALID_TYPE 0x0000000000000004
#define IMAGE_UPDATABLE_INVALID_OLD 0x0000000000000008
#define IMAGE_UPDATABLE_VALID_WITH_VENDOR_CODE 0x0000000000000010

// Package Attributes
#define PACKAGE_ATTRIBUTE_VERSION_UPDATABLE 0x0000000000000001
#define PACKAGE_ATTRIBUTE_RESET_REQUIRED 0x0000000000000002
#define PACKAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED 0x0000000000000004

#define CAPSULE_SUPPORT_AUTHENTICATION 0x0000000000000001
#define CAPSULE_SUPPORT_DEPENDENCY 0x0000000000000002

typedef struct _EFI_FIRMWARE_MANAGEMENT_PROTOCOL EFI_FIRMWARE_MANAGEMENT_PROTOCOL;

// typedef struct {
//	UINT8 Dependencies[];
// } EFI_FIRMWARE_IMAGE_DEP;

typedef struct {
	UINT64 MonotonicCount;
	//WIN_CERTIFICATE_UEFI_GUID AuthInfo;
} EFI_FIRMWARE_IMAGE_AUTHENTICATION;

typedef struct {
	UINT8 ImageIndex;
	EFI_GUID ImageTypeId;
	UINT64 ImageId;
	CHAR16 *ImageIdName;
	UINT32 Version;
	CHAR16 *VersionName;
	UINTN Size;
	UINT64 AttributesSupported;
	UINT64 AttributesSetting;
	UINT64 Compatibilities;
	//Introduced with DescriptorVersion 2+
	UINT32 LowestSupportedImageVersion; \
	//Introduced with DescriptorVersion 3+
	UINT32 LastAttemptVersion;
	UINT32 LastAttemptStatus;
	UINT64 HardwareInstance;
	//Introduced with DescriptorVersion 4+
	// EFI_FIRMWARE_IMAGE_DEP *Dependencies;
} EFI_FIRMWARE_IMAGE_DESCRIPTOR;

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE_INFO)(
	IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL *This,
	IN OUT UINTN *ImageInfoSize,
	IN OUT EFI_FIRMWARE_IMAGE_DESCRIPTOR *ImageInfo,
	OUT UINT32 *DescriptorVersion,
	OUT UINT8 *DescriptorCount,
	OUT UINTN *DescriptorSize,
	OUT UINT32 *PackageVersion,
	OUT CHAR16 **PackageVersionName
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE)(
	IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL *This,
	IN UINT8 ImageIndex,
	OUT VOID *Image,
	IN OUT UINTN *ImageSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_UPDATE_IMAGE_PROGRESS)(
	IN UINTN Completion
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_IMAGE)(
	IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL *This,
	IN UINT8 ImageIndex,
	IN CONST VOID *Image,
	IN UINTN ImageSize,
	IN CONST VOID *VendorCode,
	IN EFI_FIRMWARE_MANAGEMENT_UPDATE_IMAGE_PROGRESS Progress,
	OUT CHAR16 **AbortReason
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_CHECK_IMAGE)(
	IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL *This,
	IN UINT8 ImageIndex,
	IN CONST VOID *Image,
	IN UINTN ImageSize,
	OUT UINT32 *ImageUpdatable
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_PACKAGE_INFO)(
	IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL *This,
	OUT UINT32 *PackageVersion,
	OUT CHAR16 **PackageVersionName,
	OUT UINT32 *PackageVersionNameMaxLen,
	OUT UINT64 *AttributesSupported,
	OUT UINT64 *AttributesSetting
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_PACKAGE_INFO)(
	IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL *This,
	IN CONST VOID *Image,
	IN UINTN ImageSize,
	IN CONST VOID *VendorCode,
	IN UINT32 PackageVersion,
	IN CONST CHAR16 *PackageVersionName
) ;

typedef struct _EFI_FIRMWARE_MANAGEMENT_PROTOCOL {
	EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE_INFO GetImageInfo;
	EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE GetImage;
	EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_IMAGE SetImage;
	EFI_FIRMWARE_MANAGEMENT_PROTOCOL_CHECK_IMAGE CheckImage;
	EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_PACKAGE_INFO GetPackageInfo;
	EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_PACKAGE_INFO SetPackageInfo;
} EFI_FIRMWARE_MANAGEMENT_PROTOCOL;

////
// Delivering Capsules Containing Updates to Firmware Management Protocol
///

#define EFI_FIRMWARE_MANAGEMENT_CAPSULE_ID_GUID {0x6dcbd5ed,0xe82d,0x4c44, {0xbd,0xa1,0x71,0x94,0x19,0x9a,0xd9,0x2a}}

// Firmware Type Definitions
#define ESRT_FW_TYPE_UNKNOWN 0x00000000
#define ESRT_FW_TYPE_SYSTEMFIRMWARE 0x00000001
#define ESRT_FW_TYPE_DEVICEFIRMWARE 0x00000002
#define ESRT_FW_TYPE_UEFIDRIVER 0x00000003

// Last Attempt Status Values
#define LAST_ATTEMPT_STATUS_SUCCESS 0x00000000
#define LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL 0x00000001
#define LAST_ATTEMPT_STATUS_ERROR_INSUFFICIENT_RESOURCES 0x00000002
#define LAST_ATTEMPT_STATUS_ERROR_INCORRECT_VERSION 0x00000003
#define LAST_ATTEMPT_STATUS_ERROR_INVALID_FORMAT 0x00000004
#define LAST_ATTEMPT_STATUS_ERROR_AUTH_ERROR 0x00000005
#define LAST_ATTEMPT_STATUS_ERROR_PWR_EVT_AC 0x00000006
#define LAST_ATTEMPT_STATUS_ERROR_PWR_EVT_BATT 0x00000007
#define LAST_ATTEMPT_STATUS_ERROR_UNSATISFIED_DEPENDENCIES 0x00000008
// The LastAttemptStatus values of 0x1000 - 0x4000 are reserved for vendor usage.
#define LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL_VENDOR_RANGE_MIN 0x00001000
#define LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL_VENDOR_RANGE_MAX 0x00004000

#pragma pack(1)
typedef struct {
	UINT32 Version;
	UINT16 EmbeddedDriverCount;
	UINT16 PayloadItemCount;
	// UINT64 ItemOffsetList[];
} EFI_FIRMWARE_MANAGEMENT_CAPSULE_HEADER;

typedef struct {
	UINT32 Version;
	EFI_GUID UpdateImageTypeId;
	UINT8 UpdateImageIndex;
	UINT8 reserved_bytes[3];
	UINT32 UpdateImageSize;
	UINT32 UpdateVendorCodeSize;
	UINT64 UpdateHardwareInstance;
	UINT64 ImageCapsuleSupport;
} EFI_FIRMWARE_MANAGEMENT_CAPSULE_IMAGE_HEADER;
#pragma pack()

////
// EFI System Resource Table
///

#define EFI_SYSTEM_RESOURCE_TABLE_GUID {0xb122a263,0x3661,0x4f68, {0x99,0x29,0x78,0xf8,0xb0,0xd6,0x21,0x80}}

// Current Entry Version
#define EFI_SYSTEM_RESOURCE_TABLE_FIRMWARE_RESOURCE_VERSION 1

typedef struct {
	EFI_GUID FwClass;
	UINT32 FwType;
	UINT32 FwVersion;
	UINT32 LowestSupportedFwVersion;
	UINT32 CapsuleFlags;
	UINT32 LastAttemptVersion;
	UINT32 LastAttemptStatus;
} EFI_SYSTEM_RESOURCE_ENTRY;

typedef struct {
	UINT32 FwResourceCount;
	UINT32 FwResourceCountMax;
	UINT64 FwResourceVersion;
	//EFI_SYSTEM_RESOURCE_ENTRY Entries[];
} EFI_SYSTEM_RESOURCE_TABLE;

////
// Delivering Capsule Containing JSON payload
///

#define EFI_JSON_CAPSULE_ID_GUID {0x67d6f4cd,0xd6b8,0x4573, {0xbf,0x4a,0xde,0x5e,0x25,0x2d,0x61,0xae}}

typedef struct {
	UINT32 ConfigDataLength;
	UINT8 ConfigData[];
} EFI_JSON_CONFIG_DATA_ITEM;

#pragma pack(1)
typedef struct {
	UINT32 Version;
	UINT32 CapsuleId;
	UINT32 PayloadLength;
	UINT8 Payload[];
} EFI_JSON_CAPSULE_HEADER;

typedef struct {
	UINT32 Version;
	UINT32 TotalLength;
	// EFI_JSON_CONFIG_DATA_ITEM ConfigDataList[];
} EFI_JSON_CAPSULE_CONFIG_DATA;
#pragma pack ()

#endif /* EFI_PROTOCOLS_FWMGMNT_H */
