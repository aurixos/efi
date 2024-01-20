#ifndef EFI_H
#define EFI_H

#include "guid.h"
#include "efi_types.h"

// Event types
#define EVT_TIMER								0x80000000
#define EVT_RUNTIME								0x40000000

#define EVT_NOTIFY_WAIT							0x00000100
#define EVT_NOTIFY_SIGNAL						0x00000200

#define EVT_SIGNAL_EXIT_BOOT_SERVICES			0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE		0x60000202
//

// Task Priority Levels
#define TPL_APPLICATION							4
#define TPL_CALLBACK							8
#define TPL_NOTIFY								16
#define TPL_HIGH_LEVEL							31
//

// Memory Attributes
#define EFI_MEMORY_UC							0x0000000000000001
#define EFI_MEMORY_WC							0x0000000000000002
#define EFI_MEMORY_WT							0x0000000000000004
#define EFI_MEMORY_WB							0x0000000000000008
#define EFI_MEMORY_UCE							0x0000000000000010
#define EFI_MEMORY_WP							0x0000000000001000
#define EFI_MEMORY_RP							0x0000000000002000
#define EFI_MEMORY_XP							0x0000000000004000
#define EFI_MEMORY_NV							0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE				0x0000000000010000
#define EFI_MEMORY_RO							0x0000000000020000
#define EFI_MEMORY_SP							0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO					0x0000000000080000
#define EFI_MEMORY_RUNTIME						0x8000000000000000
#define EFI_MEMORY_ISA_VALID					0x4000000000000000
#define EFI_MEMORY_ISA_MASK						0x0FFFF00000000000
//

// EFI Open Protocol Attributes
#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL	0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL			0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL			0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER	0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER				0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE				0x00000020
//

// Memory Descriptor Version Number
#define EFI_MEMORY_DESCRIPTOR_VERSION			1

// EFI Simple Text Input Protocol
typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

// EFI Simple Text Output Protocol
typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// EFI Device Path Protocol;
typedef struct EFI_DEVICE_PATH_PROTOCOL EFI_DEVICE_PATH_PROTOCOL;

// EFI Runtime Services
typedef struct EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

// EFI Boot Services
typedef struct EFI_BOOT_SERVICES EFI_BOOT_SERVICES;

// EFI System Table
typedef struct EFI_SYSTEM_TABLE EFI_SYSTEM_TABLE;

// EFI GUID
typedef struct EFI_GUID {
	UINT32 Data1;
	UINT16 Data2;
	UINT16 Data3;
	UINT8 Data4[8];
} EFI_GUID;

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

// EFI Memory Descriptor
typedef struct {
	UINT32 Type;
	EFI_PHYSICAL_ADDRESS PhysicalStart;
	EFI_VIRTUAL_ADDRESS VirtualStart;
	UINT64 NumberOfPages;
	UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

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
(EFIAPI *EFI_RESET_SYSTEM)(
	IN EFI_RESET_TYPE ResetType,
	IN EFI_STATUS ResetStatus,
	IN UINTN DataSize,
	IN VOID *ResetData OPTIONAL
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
	void *Reset;
	EFI_INPUT_READ_KEY ReadKeyStroke;
	void *WaitForKey;
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

// EFI Runtime Services
typedef struct EFI_RUNTIME_SERVICES {
	EFI_TABLE_HEADER Hdr;

	// Time Services
	void *GetTime; 
	void *SetTime; 
	void *GetWakeupTime; 
	void *SetWakeupTime; 

	// Virtual Memory Services
	void *SetVirtualAddressMap;
	void *ConvertPointer;

	// Variable Services
	EFI_GET_VARIABLE GetVariable;
	void *GetNextVariableName;
	void *SetVariable;

	// Miscellaneous Services
	void *GetNextHighMonotonicCount;
	EFI_RESET_SYSTEM ResetSystem;

	// UEFI 2.0 Capsule Services
	void *UpdateCapsule;
	void *QueryCapsuleCapabilities;

	// Miscellaneous UEFI 2.0 Service
	void *QueryVariableInfo; 
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
	void *Reserved;
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

// EFI System Table
typedef struct EFI_SYSTEM_TABLE {
	EFI_TABLE_HEADER Hdr;

	void *FirmwareVendor;
	UINT32 FirmwareRevision;
	void *ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
	void *ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
	void *StandardErrorHandle;
	void *StdErr;
	EFI_RUNTIME_SERVICES *RuntimeServices;
	EFI_BOOT_SERVICES *BootServices;
	UINTN NumberOfTableEntries;
	void *ConfigurationTable;
} EFI_SYSTEM_TABLE;

#endif /* EFI_H */
