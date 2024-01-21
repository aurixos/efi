#ifndef EFI_H
#define EFI_H

#include "guid.h"
#include "efi_types.h"

// Variable-size array
#define ANYSIZE_ARRAY 1

// Event types
#define EVT_TIMER												0x80000000
#define EVT_RUNTIME												0x40000000

#define EVT_NOTIFY_WAIT											0x00000100
#define EVT_NOTIFY_SIGNAL										0x00000200

#define EVT_SIGNAL_EXIT_BOOT_SERVICES							0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE						0x60000202
//

// Task Priority Levels
#define TPL_APPLICATION											4
#define TPL_CALLBACK											8
#define TPL_NOTIFY												16
#define TPL_HIGH_LEVEL											31
//

// EFI System Table Revisions
#define EFI_SYSTEM_TABLE_SIGNATURE								0x5453595320494249
#define EFI_2_100_SYSTEM_TABLE_REVISION							((2<<16) | (100))
#define EFI_2_90_SYSTEM_TABLE_REVISION							((2<<16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION							((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION							((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION							((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION							((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION							((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION							((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION							((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION							((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION							((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION							((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION							((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION							((1<<16) | (02))
#define EFI_SPECIFICATION_VERSION								EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION								EFI_2_100_SYSTEM_TABLE_REVISION
//

// OS Indications
#define EFI_OS_INDICATIONS_BOOT_TO_FW_UI						0x0000000000000001
#define EFI_OS_INDICATIONS_TIMESTAMP_REVOCATION					0x0000000000000002
#define EFI_OS_INDICATIONS_FILE_CAPSULE_DELIVERY_SUPPORTED		0x0000000000000004
#define EFI_OS_INDICATIONS_FMP_CAPSULE_SUPPORTED				0x0000000000000008
#define EFI_OS_INDICATIONS_CAPSULE_RESULT_VAR_SUPPORTED			0x0000000000000010
#define EFI_OS_INDICATIONS_START_OS_RECOVERY					0x0000000000000020
#define EFI_OS_INDICATIONS_START_PLATFORM_RECOVERY				0x0000000000000040
#define EFI_OS_INDICATIONS_JSON_CONFIG_DATA_REFRESH				0x0000000000000080
//

// Simple File System Protocol revisions
#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_REVISION				0x00010000
//

// File Protocol revisions
#define EFI_FILE_PROTOCOL_REVISION								0x00010000
#define EFI_FILE_PROTOCOL_REVISION2								0x00020000
#define EFI_FILE_PROTOCOL_LATEST_REVISION						EFI_FILE_PROTOCOL_REVISION2
//

// File Protocol modes and attributes
#define EFI_FILE_MODE_READ										0x0000000000000001
#define EFI_FILE_MODE_WRITE										0x0000000000000002
#define EFI_FILE_MODE_CREATE									0x8000000000000000

#define EFI_FILE_READ_ONLY										0x0000000000000001
#define EFI_FILE_HIDDEN											0x0000000000000002
#define EFI_FILE_SYSTEM											0x0000000000000004
#define EFI_FILE_RESERVED										0x0000000000000008
#define EFI_FILE_DIRECTORY										0x0000000000000010
#define EFI_FILE_ARCHIVE										0x0000000000000020
#define EFI_FILE_VALID_ATTR										0x0000000000000037
//

// Memory Attributes
#define EFI_MEMORY_UC											0x0000000000000001
#define EFI_MEMORY_WC											0x0000000000000002
#define EFI_MEMORY_WT											0x0000000000000004
#define EFI_MEMORY_WB											0x0000000000000008
#define EFI_MEMORY_UCE											0x0000000000000010
#define EFI_MEMORY_WP											0x0000000000001000
#define EFI_MEMORY_RP											0x0000000000002000
#define EFI_MEMORY_XP											0x0000000000004000
#define EFI_MEMORY_NV											0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE								0x0000000000010000
#define EFI_MEMORY_RO											0x0000000000020000
#define EFI_MEMORY_SP											0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO									0x0000000000080000
#define EFI_MEMORY_RUNTIME										0x8000000000000000
#define EFI_MEMORY_ISA_VALID									0x4000000000000000
#define EFI_MEMORY_ISA_MASK										0x0FFFF00000000000
//

// Capsule Flags
#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET						0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE						0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET							0x00040000
//

// Time
#define EFI_TIME_ADJUST_DAYLIGHT								0x01
#define EFI_TIME_IN_DAYLIGHT									0x02

#define EFI_UNSPECIFIED_TIMEZONE								0x07FF
//

// Optional Pointer
#define EFI_OPTIONAL_PTR										0x00000001
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

// EFI Simple Text Input Protocol
typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

// EFI Simple Text Output Protocol
typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// EFI Device Path Protocol;
typedef struct EFI_DEVICE_PATH_PROTOCOL EFI_DEVICE_PATH_PROTOCOL;

// EFI Simple File System Protocol
typedef struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL EFI_SIMPLE_FILE_SYSTEM_PROTOCOL;

// EFI File Protocol
typedef struct EFI_FILE_PROTOCOL EFI_FILE_PROTOCOL;

// EFI Runtime Services
typedef struct EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

// EFI Boot Services
typedef struct EFI_BOOT_SERVICES EFI_BOOT_SERVICES;

// EFI System Table
typedef struct EFI_SYSTEM_TABLE EFI_SYSTEM_TABLE;

// EFI Certificate RSA2048 SHA256 Block
typedef struct _EFI_CERT_BLOCK_RSA_2048_SHA256 {
	EFI_GUID HashType;
	UINT8 PublicKey[256];
	UINT8 Signature[256];
} EFI_CERT_BLOCK_RSA_2048_SHA256;

// EFI WinCertificate
typedef struct _WIN_CERTIFICATE {
	UINT32 dwLength;
	UINT16 wRevision;
	UINT16 wCertificateType;
	UINT8 bCertificate[ANYSIZE_ARRAY];
} WIN_CERTIFICATE;

typedef struct _WIN_CERTIFICATE_UEFI_GUID {
	WIN_CERTIFICATE Hdr;
	EFI_GUID CertType;
	UINT8 CertData[ANYSIZE_ARRAY];
} WIN_CERTIFICATE_UEFI_GUID;

// EFI Simple Text Output Mode
typedef struct {
	INT32 MaxNode;

	// Current settings
	INT32 Mode;
	INT32 Attribute;
	INT32 CursorColumn;
	INT32 CursorRow;
	BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

// Input Key
typedef struct {
	UINT16 ScanCode;
	CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

// EFI File I/O Token
typedef struct {
	EFI_EVENT Event;
	EFI_STATUS Status;
	UINTN BufferSize;
	VOID *Buffer;
} EFI_FILE_IO_TOKEN;

// EFI Time
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

// EFI Time Capabilities
typedef struct {
	UINT32 Resolution;
	UINT32 Accuracy;
	BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

// EFI HII Package List Header
typedef struct {
	EFI_GUID PackageListGuid;
	UINT32 PackagLength;
} EFI_HII_PACKAGE_LIST_HEADER;

// EFI Table Header
typedef struct {
	UINT64 Signature;
	UINT32 Revision;
	UINT32 HeaderSize;
	UINT32 CRC32;
	UINT32 Reserved;
} EFI_TABLE_HEADER;

// EFI Variable Authentication
typedef struct {
	UINT64 MonotonicCount;
	WIN_CERTIFICATE_UEFI_GUID AuthInfo;
} EFI_VARIABLE_AUTHENTICATION;

// EFI Memory Descriptor
typedef struct {
	UINT32 Type;
	EFI_PHYSICAL_ADDRESS PhysicalStart;
	EFI_VIRTUAL_ADDRESS VirtualStart;
	UINT64 NumberOfPages;
	UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

typedef struct {
	EFI_PHYSICAL_ADDRESS Address;
	UINT64 Length;
} EFI_MEMORY_RANGE;

// EFI Capsule Header
typedef struct {
	EFI_GUID CapsuleGuid;
	UINT32 HeaderSize;
	UINT32 Flags;
	UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;

// EFI Capsule Block
typedef struct {
	UINT64 Length;
	union {
		EFI_PHYSICAL_ADDRESS DataBlock;
		EFI_PHYSICAL_ADDRESS ContinuationPointer;
	} Union;
} EFI_CAPSULE_BLOCK_DESCRIPTOR;

// EFI Memory Range Capsule
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

// Open Protocol Information Entry
typedef struct {
	EFI_HANDLE AgentHandle;
	EFI_HANDLE ControllerHandle;
	UINT32 Attributes;
	UINT32 OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

// EFI Timer Delay
typedef enum {
	TimerCancel,
	TimerPeriodic,
	TimerRelative
} EFI_TIMER_DELAY;

// EFI Allocation Type
typedef enum {
	AllocateAnyPages,
	AllocateMaxAddress,
	AllocateAddress,
	MaxAllocateType
} EFI_ALLOCATE_TYPE;

// EFI Memory Type
typedef enum {
	EfiReservedMemoryType,
	EfiLoaderCode,
	EfiLoaderData,
	EfiBootServicesCode,
	EfiBootServicesData,
	EfiRuntimeServicesCode,
	EfiRuntimeServicesData,
	EfiConventionalMemory,
	EfiUnusableMemory,
	EfiACPIReclaimMemory,
	EfiACPIMemoryNVS,
	EfiMemoryMappedIO,
	EfiMemoryMappedIOPortSpace,
	EfiPalCode,
	EfiPersistentMemory,
	EfiUnacceptedMemoryType,
	EfiMaxMemoryType
} EFI_MEMORY_TYPE;

// EFI Locate Search Type
typedef enum {
	AllHandles,
	ByRegisterNotify,
	ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

// EFI Interface Type
typedef enum {
	EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

// EFI Reset Type
typedef enum {
	EfiResetCold,
	EfiResetWarm,
	EfiResetShutdown,
	EfiResetPlatformSpecific
} EFI_RESET_TYPE;

/**********************
 * FUNCTIONS          *
 **********************/

typedef EFI_STATUS
(EFIAPI *EFI_IMAGE_ENTRY_POINT)(
	IN EFI_HANDLE ImageHandle,
	IN EFI_SYSTEM_TABLE *SystemTable
);

// EFI Simple Text Input Protocol

typedef 
EFI_STATUS 
(EFIAPI *EFI_INPUT_READ_KEY)(
	IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, 
	OUT EFI_INPUT_KEY *Key
);

typedef
EFI_STATUS
(EFIAPI *EFI_INPUT_RESET)(
	IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
	IN BOOLEAN ExtendedVerification
);

// EFI Simple Text Output Protocol

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_RESET)(
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN BOOLEAN ExtendedVerification
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_TEXT_STRING)(
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN CHAR16 *String
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_TEST_STRING)(
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN CHAR16 *String
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_QUERY_MODE)(
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN UINTN ModeNumber,
	OUT UINTN *Columns,
	OUT UINTN *Rows
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_MODE)(
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN UINTN ModeNumber
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_TEXT_SET_ATTRIBUTE)(
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN UINTN Attribute
);

typedef 
EFI_STATUS
(EFIAPI *EFI_TEXT_CLEAR_SCREEN)(
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This
);

typedef 
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_CURSOR_POSITION)(
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN UINTN Column,
	IN UINTN Row
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_ENABLE_CURSOR)(
	IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	IN BOOLEAN Visible
);

// EFI Simple File System Protocol
typedef
EFI_STATUS
(EFIAPI *EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_OPEN_VOLUME)(
	IN EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *This,
	OUT EFI_FILE_PROTOCOL **Root
);

// EFI File Protocol

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_OPEN)(
	IN EFI_FILE_PROTOCOL *This,
	OUT EFI_FILE_PROTOCOL **NewHandle,
	IN CHAR16 *FileName,
	IN UINT64 OpenMode,
	IN UINT64 Attributes
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_CLOSE)(
	IN EFI_FILE_PROTOCOL *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_DELETE)(
	IN EFI_FILE_PROTOCOL *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_READ)(
	IN EFI_FILE_PROTOCOL *This,
	IN OUT UINTN *BufferSize,
	OUT VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_WRITE)(
	IN EFI_FILE_PROTOCOL *This,
	IN OUT UINTN *BufferSize,
	IN VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_OPEN_EX)(
	IN EFI_FILE_PROTOCOL *This,
	OUT EFI_FILE_PROTOCOL **NewHandle,
	IN CHAR16 *FileName,
	IN UINT64 OpenMode,
	IN UINT64 Attributes,
	IN OUT EFI_FILE_IO_TOKEN *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_READ_EX)(
	IN EFI_FILE_PROTOCOL *This,
	IN OUT EFI_FILE_IO_TOKEN *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_WRITE_EX)(
	IN EFI_FILE_PROTOCOL *This,
	IN OUT EFI_FILE_IO_TOKEN *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_FLUSH_EX)(
	IN EFI_FILE_PROTOCOL *This,
	IN OUT EFI_FILE_IO_TOKEN *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_SET_POSITION)(
	IN EFI_FILE_PROTOCOL *This,
	IN UINT64 Position
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_GET_POSITION)(
	IN EFI_FILE_PROTOCOL *This,
	OUT UINT64 Position
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_GET_INFO)(
	IN EFI_FILE_PROTOCOL *This,
	IN EFI_GUID *InformationType,
	IN OUT UINTN *BufferSize,
	OUT VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_SET_INFO)(
	IN EFI_FILE_PROTOCOL *This,
	IN EFI_GUID *InformationType,
	IN UINTN BufferSize,
	IN VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_FILE_FLUSH)(
	IN EFI_FILE_PROTOCOL *This
);

// EFI Runtime Services

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
(EFIAPI *EFI_QUERY_VARIABLE_INFO)(
	IN UINT32 Attributes,
	OUT UINT64 *MaximumVariableStorageSize,
	OUT UINT64 *RemainingVariableStorageSize,
	OUT UINT64 *MaximumVariableSize
);

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
(EFIAPI *EFI_RESET_SYSTEM)(
	IN EFI_RESET_TYPE ResetType,
	IN EFI_STATUS ResetStatus,
	IN UINTN DataSize,
	IN VOID *ResetData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_HIGH_MONOTONIC_COUNT)(
	OUT UINT32 *HighCount
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



// EFI Boot Services

typedef
VOID
(EFIAPI *EFI_EVENT_NOTIFY)(
	IN EFI_EVENT Event,
	IN VOID *Context
);

typedef
VOID
(EFIAPI *EFI_CREATE_EVENT)(
	IN UINT32 Type,
	IN EFI_TPL NotifyTPL,
	IN EFI_EVENT_NOTIFY NotifyFunction OPTIONAL,
	IN VOID *NotifyContext OPTIONAL,
	OUT EFI_EVENT *Event
);

typedef EFI_STATUS
(EFIAPI *EFI_CREATE_EVENT_EX)(
	IN UINT32 Type,
	IN EFI_TPL NotifyTpl,
	IN EFI_EVENT_NOTIFY NotifyFunction OPTIONAL,
	IN CONST VOID *NotifyContext OPTIONAL,
	IN CONST EFI_GUID *EventGroup OPTIONAL,
	OUT EFI_EVENT *Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_EVENT)(
	IN EFI_EVENT Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_SIGNAL_EVENT)(
	IN EFI_EVENT Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_WAIT_FOR_EVENT)(
	IN UINTN NumberOfEvents,
	IN EFI_EVENT *Event,
	OUT UINTN *Index
);

typedef
EFI_STATUS
(EFIAPI *EFI_CHECK_EVENT)(
	IN EFI_EVENT Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_TIMER)(
	IN EFI_EVENT Event,
	IN EFI_TIMER_DELAY Type,
	IN UINT64 TriggerTime
);

typedef
EFI_TPL
(EFIAPI *EFI_RAISE_TPL)(
	IN EFI_TPL NewTpl
);

typedef
EFI_TPL
(EFIAPI *EFI_RESTORE_TPL)(
	IN EFI_TPL OldTpl
);

typedef
EFI_STATUS
(EFIAPI *EFI_ALLOCATE_PAGES)(
	IN EFI_ALLOCATE_TYPE Type,
	IN EFI_MEMORY_TYPE MemoryType,
	IN UINTN Pages,
	IN OUT EFI_PHYSICAL_ADDRESS *Memory
);

typedef
EFI_STATUS
(EFIAPI *EFI_FREE_PAGES)(
	IN EFI_PHYSICAL_ADDRESS Memory,
	IN UINTN Pages
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_MEMORY_MAP)(
	IN OUT UINTN *MemoryMapSize,
	OUT EFI_MEMORY_DESCRIPTOR *MemoryMap,
	OUT UINTN *MapKey,
	OUT UINTN *DescriptorSize,
	OUT UINT32 *DescriptorVersion
);

typedef
EFI_STATUS
(EFIAPI *EFI_ALLOCATE_POOL)(
	IN EFI_MEMORY_TYPE PoolType,
	IN UINTN Size,
	OUT VOID **Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_FREE_POOL)(
	IN VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_PROTOCOL_INTERFACE)(
	IN OUT EFI_HANDLE *Handle,
	IN EFI_GUID *Protocol,
	IN EFI_INTERFACE_TYPE InterfaceType,
	IN VOID *Interface
);

typedef
EFI_STATUS
(EFIAPI *EFI_UNINSTALL_PROTOCOL_INTERFACE)(
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	IN VOID *Interface
);

typedef
EFI_STATUS
(EFIAPI *EFI_REINSTALL_PROTOCOL_INTERFACE)(
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	IN VOID *OldInterface,
	IN VOID *NewInterface
);

typedef
EFI_STATUS
(EFIAPI *EFI_REGISTER_PROTOCOL_NOTIFY)(
	IN EFI_GUID *Protocol,
	IN EFI_EVENT Event,
	OUT VOID **Registration
);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE)(
	IN EFI_LOCATE_SEARCH_TYPE SearchType,
	IN EFI_GUID *Protocol OPTIONAL,
	IN VOID *SearchKey OPTIONAL,
	IN OUT UINTN *BufferSize,
	OUT EFI_HANDLE *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_HANDLE_PROTOCOL)(
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	OUT VOID **Interface
);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_DEVICE_PATH)(
	IN EFI_GUID *Protocol,
	IN OUT EFI_DEVICE_PATH_PROTOCOL **DevicePath,
	OUT EFI_HANDLE *Device
);

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL)(
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	OUT VOID **Interface OPTIONAL,
	IN EFI_HANDLE AgentHandle,
	IN EFI_HANDLE ControllerHandle,
	IN UINT32 Attributes
);

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_PROTOCOL)(
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	IN EFI_HANDLE AgentHandle,
	IN EFI_HANDLE ControllerHandle
);

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION)(
	IN EFI_HANDLE Handle,
	IN EFI_GUID *Protocol,
	OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer,
	OUT UINTN *EntryCount
);

typedef
EFI_STATUS
(EFIAPI *EFI_CONNECT_CONTROLLER)(
	IN EFI_HANDLE ControllerHandle,
	IN EFI_HANDLE *DriverImageHandle OPTIONAL,
	IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL,
	IN BOOLEAN Recursive
);

typedef
EFI_STATUS
(EFIAPI *EFI_DISCONNECT_CONTROLLER)(
	IN EFI_HANDLE ControllerHandle,
	IN EFI_HANDLE DriverImageHandle OPTIONAL,
	IN EFI_HANDLE ChildHandle OPTIONAL
);

typedef EFI_STATUS
(EFIAPI *EFI_PROTOCOLS_PER_HANDLE)(
	IN EFI_HANDLE Handle,
	OUT EFI_GUID ***ProtocolBuffer,
	OUT UINTN *ProtocolBufferCount
);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE_BUFFER)(
	IN EFI_LOCATE_SEARCH_TYPE SearchType,
	IN EFI_GUID *Protocol OPTIONAL,
	IN VOID *SearchKey OPTIONAL,
	OUT UINTN *NoHandles,
	OUT EFI_HANDLE **Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_PROTOCOL)(
	IN EFI_GUID *Protocol,
	IN VOID *Registration OPTIONAL,
	OUT VOID **Interface
);

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES)(
	IN OUT EFI_HANDLE *Handle,
	...
);

typedef
EFI_STATUS
(EFIAPI *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES)(
	IN OUT EFI_HANDLE *Handle,
	...
);

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_LOAD)(
	IN BOOLEAN BootPolicy,
	IN EFI_HANDLE ParentImageHandle,
	IN EFI_DEVICE_PATH_PROTOCOL *DevicePath OPTIONAL,
	IN VOID *SourceBuffer OPTIONAL,
	IN UINTN SourceSize,
	OUT EFI_HANDLE *ImageHandle
);

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_START)(
	IN EFI_HANDLE ImageHandle,
	OUT UINTN *ExitDataSize,
	OUT CHAR16 **ExitData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_UNLOAD)(
	IN EFI_HANDLE ImageHandle
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXIT)(
	IN EFI_HANDLE ImageHandle,
	IN EFI_STATUS ExitStatus,
	IN UINTN ExitDataSize,
	IN CHAR16 *ExitData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXIT_BOOT_SERVICES)(
	IN EFI_HANDLE ImageHandle,
	IN UINTN MapKey
);

typedef EFI_STATUS
(EFIAPI *EFI_SET_WATCHDOG_TIMER)(
	IN UINTN Timeout,
	IN UINT64 WatchDogCode,
	IN UINTN DataSize,
	IN CHAR16 *WatchdogData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_STALL)(
	IN UINTN Microseconds
);

typedef
VOID
(EFIAPI *EFI_COPY_MEM)(
	IN VOID *Destination,
	IN VOID *Source,
	IN UINTN Length
);

typedef
VOID
(EFIAPI *EFI_SET_MEM)(
	IN VOID *Buffer,
	IN UINTN Size,
	IN UINT8 Value
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_MONOTONIC_COUNT)(
	OUT UINT64 *Count
);

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_CONFIGURATION_TABLE)(
	IN EFI_GUID *Guid,
	IN VOID *Table
);

typedef
EFI_STATUS
(EFIAPI *EFI_CALCULATE_CRC32)(
	IN VOID *Data,
	IN UINTN DataSize,
	OUT UINT32 *Crc32
);

/**********************
 * Protocols & Tables *
 **********************/

// EFI HII Package List Protocol
typedef EFI_HII_PACKAGE_LIST_HEADER *EFI_HII_PACKAGE_LIST_PROTOCOL;

// EFI Device Path Protocol
typedef struct EFI_DEVICE_PATH_PROTOCOL {
	UINT8 Type;
	UINT8 SubType;
	UINT8 Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

// EFI Simple Text Input Protocol
typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
	EFI_INPUT_RESET Reset;
	EFI_INPUT_READ_KEY ReadKeyStroke;
	EFI_EVENT WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

// EFI Simple Text Output Protocol
typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
	EFI_TEXT_RESET Reset;
	EFI_TEXT_STRING OutputString;
	EFI_TEXT_TEST_STRING TestString;
	EFI_TEXT_QUERY_MODE QueryMode;
	EFI_TEXT_SET_MODE SetMode;
	EFI_TEXT_SET_ATTRIBUTE SetAttribute;
	EFI_TEXT_CLEAR_SCREEN ClearScreen;
	EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
	EFI_TEXT_ENABLE_CURSOR EnableCursor;
	SIMPLE_TEXT_OUTPUT_MODE *Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// EFI Simple File System Protocol
typedef struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL {
	UINT64 Revision;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_OPEN_VOLUME OpenVolume;
} EFI_SIMPLE_FILE_SYSTEM_PROTOCOL;

// EFI File Protocol
typedef struct EFI_FILE_PROTOCOL {
	UINT64 Revision;

	EFI_FILE_OPEN Open;
	EFI_FILE_CLOSE Close;
	EFI_FILE_DELETE Delete;
	EFI_FILE_READ Read;
	EFI_FILE_WRITE Write;
	EFI_FILE_GET_POSITION GetPosition;
	EFI_FILE_SET_POSITION SetPosition;
	EFI_FILE_GET_INFO GetInfo;
	EFI_FILE_SET_INFO SetInfo;
	EFI_FILE_FLUSH Flush;

	// Added for revision 2
	EFI_FILE_OPEN_EX OpenEx;
	EFI_FILE_READ_EX ReadEx;
	EFI_FILE_WRITE_EX WriteEx;
	EFI_FILE_FLUSH_EX FlushEx;
} EFI_FILE_PROTOCOL;

// EFI Runtime Services
typedef struct EFI_RUNTIME_SERVICES {
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

// EFI Boot Services

typedef struct EFI_BOOT_SERVICES {
	EFI_TABLE_HEADER Hdr;

	// Task Priority Services
	EFI_RAISE_TPL RaiseTPL;
	EFI_RESTORE_TPL RestoreTPL;

	// Memory Services
	EFI_ALLOCATE_PAGES AllocatePages;
	EFI_FREE_PAGES FreePages;
	EFI_GET_MEMORY_MAP GetMemoryMap;
	EFI_ALLOCATE_POOL AllocatePool;
	EFI_FREE_POOL FreePool;

	// Event & Timer Services
	EFI_CREATE_EVENT CreateEvent;
	EFI_SET_TIMER SetTimer;
	EFI_WAIT_FOR_EVENT WaitForEvent;
	EFI_SIGNAL_EVENT SignalEvent;
	EFI_CLOSE_EVENT CloseEvent;
	EFI_CHECK_EVENT CheckEvent;

	// Protocol Handler Services
	EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
	EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface;
	EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;
	EFI_HANDLE_PROTOCOL HandleProtocol;
	VOID *Reserved;
	EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
	EFI_LOCATE_HANDLE LocateHandle;
	EFI_LOCATE_DEVICE_PATH LocateDevicePath;
	EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;

	// Image Services
	EFI_IMAGE_LOAD LoadImage;
	EFI_IMAGE_START StartImage;
	EFI_EXIT Exit;
	EFI_IMAGE_UNLOAD UnloadImage;
	EFI_EXIT_BOOT_SERVICES ExitBootServices;

	// Miscellaneous Services
	EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
	EFI_STALL Stall;
	EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;

	// DriverSupport Services
	EFI_CONNECT_CONTROLLER ConnectController;
	EFI_DISCONNECT_CONTROLLER DisconnectController;

	// Open and Close Protocol Services
	EFI_OPEN_PROTOCOL OpenProtocol;
	EFI_CLOSE_PROTOCOL CloseProtocol;
	EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;

	// Library Services
	EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;
	EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;
	EFI_LOCATE_PROTOCOL LocateProtocol;
	EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;
	EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;

	// 32-bit CRC Services
	EFI_CALCULATE_CRC32 CalculateCrc32;

	// Miscellaneous Services
	EFI_COPY_MEM CopyMem;
	EFI_SET_MEM SetMem;
	EFI_CREATE_EVENT_EX CreateEventEx;
} EFI_BOOT_SERVICES;

// EFI Capsule Table
typedef struct {
	UINT32 CapsuleArrayNumber;
	VOID *CapsulePtr[ANYSIZE_ARRAY];
} EFI_CAPSULE_TABLE;

// EFI Configuration Table
typedef struct {
	EFI_GUID VendorGuid;
	VOID *VendorTable;
} EFI_CONFIGURATION_TABLE;

// EFI System Table
typedef struct EFI_SYSTEM_TABLE {
	EFI_TABLE_HEADER Hdr;

	CHAR16 *FirmwareVendor;
	UINT32 FirmwareRevision;
	EFI_HANDLE ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
	EFI_HANDLE ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
	EFI_HANDLE StandardErrorHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
	EFI_RUNTIME_SERVICES *RuntimeServices;
	EFI_BOOT_SERVICES *BootServices;
	UINTN NumberOfTableEntries;
	EFI_CONFIGURATION_TABLE *ConfigurationTable;
} EFI_SYSTEM_TABLE;

#endif /* EFI_H */
