#ifndef EFI_H
#define EFI_H

#include "guid.h"
#include "_types.h"

// EFI Simple Text Input Protocol
typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

// EFI Simple Text Output Protocol
typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// EFI Runtime Services
typedef struct EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

// EFI System Table
typedef struct EFI_SYSTEM_TABLE EFI_SYSTEM_TABLE;

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

// EFI Table Header
typedef struct {
	UINT64 Signature;
	UINT32 Revision;
	UINT32 HeaderSize;
	UINT32 CRC32;
	UINT32 Reserved;
} EFI_TABLE_HEADER;

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
VOID 
(EFIAPI *EFI_RESET_SYSTEM)(
	IN EFI_RESET_TYPE ResetType,      
	IN EFI_STATUS ResetStatus,   
	IN UINTN DataSize,     
	IN VOID *ResetData OPTIONAL
);

/**********************
 * Protocols & Tables *
 **********************/

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
	void *GetVariable;
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
	void *BootServices;
	UINTN NumberOfTableEntries;
	void *ConfigurationTable;
} EFI_SYSTEM_TABLE;

#endif /* EFI_H */
