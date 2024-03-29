#ifndef EFI_RUNTIME_SERVICES_H
#define EFI_RUNTIME_SERVICES_H

#include "efi_types.h"

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

typedef struct _EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

typedef struct {
	UINT16 Year;
	UINT8 Month;
	UINT8 Day;
	UINT8 Hour;
	UINT8 Minute;
	UINT8 Second;
	UINT8 Pad1;
	UINT32 Nanosecond;
	INT16 TimeZone;
	UINT8 Daylight;
	UINT8 Pad2;
} EFI_TIME;

typedef struct {
	UINT32 Resolution;
	UINT32 Accuracy;
	BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

typedef struct {
	EFI_GUID CapsuleGuid;
	UINT32 HeaderSize;
	UINT32 Flags;
	UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;

typedef struct {
	UINT32 CapsuleArrayNumber;
	VOID *CapsulePtr[1];
} EFI_CAPSULE_TABLE;

typedef struct {
	UINT64 Length;
	union {
		EFI_PHYSICAL_ADDRESS DataBlock;
		EFI_PHYSICAL_ADDRESS ContinuationPointer;
	} Union;
} EFI_CAPSULE_BLOCK_DESCRIPTOR;

typedef struct {
	EFI_PHYSICAL_ADDRESS Address;
	UINT64 Length;
} EFI_MEMORY_RANGE;

typedef struct {
	EFI_CAPSULE_HEADER Header;
	UINT32 OsRequestedMemoryType;
	UINT64 NumberOfMemoryRanges;
	EFI_MEMORY_RANGE MemoryRanges[];
} EFI_MEMORY_RANGE_CAPSULE;

typedef struct {
	UINT64 FirmwareMemoryRequirement;
	UINT64 NumberOfMemoryRanges;
} EFI_MEMORY_RANGE_CAPSULE_RESULT;

typedef struct {
	UINT32 VariableTotalSize;
	UINT32 Reserved;
	EFI_GUID CapsuleGuid;
	EFI_TIME CapsuleProcessed;
	EFI_STATUS CapsuleStatus;
} EFI_CAPSULE_RESULT_VARIABLE_HEADER;

typedef struct {
	UINT16 Version;
	UINT8 PayloadIndex;
	UINT8 UpdateImageIndex;
	EFI_GUID UpdateImageTypeId;
	//CHAR16 CapsuleFileName[];
	//CHAR16 CapsuleTarget[];
} EFI_CAPSULE_RESULT_VARIABLE_FMP;

typedef struct {
	UINT32 Version;
	UINT32 CapsuleId;
	UINT32 RespLength;
	UINT8 Resp[];
} EFI_CAPSULE_RESULT_VARIABLE_JSON;

typedef
EFI_STATUS
(EFIAPI *EFI_GET_TIME)(
	OUT EFI_TIME *Time,
	OUT EFI_TIME_CAPABILITIES *Capabilities OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_TIME)(
	IN EFI_TIME *Time
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_WAKEUP_TIME)(
	OUT BOOLEAN *Enable,
	OUT BOOLEAN *Pending,
	OUT EFI_TIME *Time
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_WAKEUP_TIME)(
	IN BOOLEAN Enable,
	IN EFI_TIME *Time
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP)(
	IN UINTN MemoryMapSize,
	IN UINTN DescriptorSize,
	IN UINT32 DescriptorVersion,
	IN EFI_MEMORY_DESCRIPTOR *VirtualMap
);

typedef
EFI_STATUS
(EFIAPI *EFI_CONVERT_POINTER)(
	IN UINTN DebugDisposition,
	IN VOID **Address
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_VARIABLE)(
	IN CHAR16 *VariableName,
	IN EFI_GUID *VendorGuid,
	OUT UINT32 *Attributes OPTIONAL,
	IN OUT UINTN *DataSize,
	OUT VOID *Data OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_VARIABLE_NAME)(
	IN OUT UINTN *VariableNameSize,
	IN OUT CHAR16 *VariableName,
	IN OUT EFI_GUID *VendorGuid
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_VARIABLE)(
	IN CHAR16 *VariableName,
	IN EFI_GUID *VendorGuid,
	IN UINT32 Attributes,
	IN UINTN DataSize,
	IN VOID *Data
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_HIGH_MONOTONIC_COUNT)(
	OUT UINT32 *HighCount
);

typedef
EFI_STATUS
(EFIAPI *EFI_RESET_SYSTEM)(
	IN EFI_RESET_TYPE ResetType,
	IN EFI_STATUS ResetStatus,
	IN UINTN DataSize,
	IN VOID *ResetData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_UPDATE_CAPSULE)(
	IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
	IN UINTN CapsuleCount,
	IN EFI_PHYSICAL_ADDRESS ScatterGatherList OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_QUERY_CAPSULE_CAPABILITIES)(
	IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
	IN UINTN CapsuleCount,
	OUT UINT64 *MaximumCapsuleSize,
	OUT EFI_RESET_TYPE *ResetType
);

typedef
EFI_STATUS
(EFIAPI *EFI_QUERY_VARIABLE_INFO)(
	IN UINT32 Attributes,
	OUT UINT64 *MaximumVariableStorageSize,
	OUT UINT64 *RemainingVariableStorageSize,
	OUT UINT64 *MaximumVariableSize
);

// EFI Runtime Services
typedef struct _EFI_RUNTIME_SERVICES {
	EFI_TABLE_HEADER Hdr;

	// Time Services
	EFI_GET_TIME GetTime; 
	EFI_SET_TIME SetTime; 
	EFI_GET_WAKEUP_TIME GetWakeupTime; 
	EFI_SET_WAKEUP_TIME SetWakeupTime; 

	// Virtual Memory Services
	EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
	EFI_CONVERT_POINTER ConvertPointer;

	// Variable Services
	EFI_GET_VARIABLE GetVariable;
	EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
	EFI_SET_VARIABLE SetVariable;

	// Miscellaneous Services
	EFI_GET_NEXT_HIGH_MONOTONIC_COUNT GetNextHighMonotonicCount;
	EFI_RESET_SYSTEM ResetSystem;

	// UEFI 2.0 Capsule Services
	EFI_UPDATE_CAPSULE UpdateCapsule;
	EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;

	// Miscellaneous UEFI 2.0 Service
	EFI_QUERY_VARIABLE_INFO QueryVariableInfo; 
} EFI_RUNTIME_SERVICES;

#endif /* EFI_RUNTIME_SERVICES_H */
