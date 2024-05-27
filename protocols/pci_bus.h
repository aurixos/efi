#ifndef EFI_PROTOCOLS_PCI_BUS_H
#define EFI_PROTOCOLS_PCI_BUS_H

////
// PCI Root Bridge I/O Protocol
///

#define EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GUID {0x2f707ebb,0x4a1a,0x11d4, {0x9a,0x38,0x00,0x90,0x27,0x3f,0xc1,0x4d}}

/// PCI Root Bridge I/O Protocol Attribute bits
#define EFI_PCI_ATTRIBUTE_ISA_MOTHERBOARD_IO 0x0001
#define EFI_PCI_ATTRIBUTE_ISA_IO 0x0002
#define EFI_PCI_ATTRIBUTE_VGA_PALETTE_IO 0x0004
#define EFI_PCI_ATTRIBUTE_VGA_MEMORY 0x0008
#define EFI_PCI_ATTRIBUTE_VGA_IO 0x0010
#define EFI_PCI_ATTRIBUTE_IDE_PRIMARY_IO 0x0020
#define EFI_PCI_ATTRIBUTE_IDE_SECONDARY_IO 0x0040
#define EFI_PCI_ATTRIBUTE_MEMORY_WRITE_COMBINE 0x0080
#define EFI_PCI_ATTRIBUTE_MEMORY_CACHED 0x0800
#define EFI_PCI_ATTRIBUTE_MEMORY_DISABLE 0x1000
#define EFI_PCI_ATTRIBUTE_DUAL_ADDRESS_CYCLE 0x8000
#define EFI_PCI_ATTRIBUTE_ISA_IO_16 0x10000
#define EFI_PCI_ATTRIBUTE_VGA_PALETTE_IO_16 0x20000
#define EFI_PCI_ATTRIBUTE_VGA_IO_16 0x40000

typedef struct _EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL;

typedef enum {
	EfiPciWidthUint8,
	EfiPciWidthUint16,
	EfiPciWidthUint32,
	EfiPciWidthUint64,
	EfiPciWidthFifoUint8,
	EfiPciWidthFifoUint16,
	EfiPciWidthFifoUint32,
	EfiPciWidthFifoUint64,
	EfiPciWidthFillUint8,
	EfiPciWidthFillUint16,
	EfiPciWidthFillUint32,
	EfiPciWidthFillUint64,
	EfiPciWidthMaximum
} EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH;

typedef enum {
	EfiPciOperationBusMasterRead,
	EfiPciOperationBusMasterWrite,
	EfiPciOperationBusMasterCommonBuffer,
	EfiPciOperationBusMasterRead64,
	EfiPciOperationBusMasterWrite64,
	EfiPciOperationBusMasterCommonBuffer64,
	EfiPciOperationMaximum
} EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_OPERATION;

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH Width,
	IN EFI_UINT64 Address,
	IN EFI_UINT64 Mask,
	IN EFI_UINT64 Value,
	IN EFI_UINT64 Delay,
	OUT EFI_UINT64 *Result
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_IO_MEM)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH Width,
	IN EFI_UINT64 Address,
	IN EFI_UINTN Count,
	IN OUT VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH Width,
	IN EFI_UINT64 Address,
	IN EFI_UINT64 Mask,
	IN EFI_UINT64 Value,
	IN EFI_UINT64 Delay,
	OUT EFI_UINT64 *Result
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_COPY_MEM)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH Width,
	IN EFI_UINT64 DestAddress,
	IN EFI_UINT64 SrcAddress,
	IN EFI_UINTN Count
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_MAP)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_OPERATION Operation,
	IN VOID *HostAddress,
	IN OUT EFI_UINTN *NumberOfBytes,
	OUT EFI_PHYSICAL_ADDRESS *DeviceAddress,
	OUT VOID **Mapping
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_UNMAP)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	IN VOID *Mapping
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ALLOCATE_BUFFER)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	IN EFI_ALLOCATE_TYPE Type,
	IN EFI_MEMORY_TYPE MemoryType,
	IN EFI_UINTN Pages,
	OUT VOID **HostAddress,
	IN EFI_UINT64 Attributes
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FREE_BUFFER)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	IN EFI_UINTN Pages,
	IN VOID *HostAddress
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FLUSH)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GET_ATTRIBUTES)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	OUT EFI_UINT64 *Supports OPTIONAL,
	OUT EFI_UINT64 *Attributes OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_SET_ATTRIBUTES)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	IN EFI_UINT64 Attributes,
	IN OUT EFI_UINT64 *ResourceBase OPTIONAL,
	IN OUT EFI_UINT64 *ResourceLength OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_CONFIGURATION)(
	IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *This,
	OUT VOID **Resources
);

typedef struct {
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_IO_MEM Read;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_IO_MEM Write;
} EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS;

typedef struct _EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL {
	EFI_HANDLE ParentHandle;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM PollMem;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM PollIo;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS Mem;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS Io;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS Pci;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_COPY_MEM CopyMem;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_MAP Map;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_UNMAP Unmap;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ALLOCATE_BUFFER AllocateBuffer;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FREE_BUFFER FreeBuffer;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FLUSH Flush;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GET_ATTRIBUTES GetAttributes;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_SET_ATTRIBUTES SetAttributes;
	EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_CONFIGURATION Configuration;
	EFI_UINT32 SegmentNumber;
} EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL;

////
// PCI I/O Protocol
///

#define EFI_PCI_IO_PROTOCOL_GUID {0x4cf5b200,0x68b8,0x4ca5, {0x9e,0xec,0xb2,0x3e,0x3f,0x50,0x02,0x9a}}

#define EFI_PCI_IO_PASS_THROUGH_BAR 0xff

// PCI I/O Protocol Attribute bits
#define EFI_PCI_IO_ATTRIBUTE_ISA_MOTHERBOARD_IO 0x0001
#define EFI_PCI_IO_ATTRIBUTE_ISA_IO 0x0002
#define EFI_PCI_IO_ATTRIBUTE_VGA_PALETTE_IO 0x0004
#define EFI_PCI_IO_ATTRIBUTE_VGA_MEMORY 0x0008
#define EFI_PCI_IO_ATTRIBUTE_VGA_IO 0x0010
#define EFI_PCI_IO_ATTRIBUTE_IDE_PRIMARY_IO 0x0020
#define EFI_PCI_IO_ATTRIBUTE_IDE_SECONDARY_IO 0x0040
#define EFI_PCI_IO_ATTRIBUTE_MEMORY_WRITE_COMBINE 0x0080
#define EFI_PCI_IO_ATTRIBUTE_IO 0x0100
#define EFI_PCI_IO_ATTRIBUTE_MEMORY 0x0200
#define EFI_PCI_IO_ATTRIBUTE_BUS_MASTER 0x0400
#define EFI_PCI_IO_ATTRIBUTE_MEMORY_CACHED 0x0800
#define EFI_PCI_IO_ATTRIBUTE_MEMORY_DISABLE 0x1000
#define EFI_PCI_IO_ATTRIBUTE_EMBEDDED_DEVICE 0x2000
#define EFI_PCI_IO_ATTRIBUTE_EMBEDDED_ROM 0x4000
#define EFI_PCI_IO_ATTRIBUTE_DUAL_ADDRESS_CYCLE 0x8000
#define EFI_PCI_IO_ATTRIBUTE_ISA_IO_16 0x10000
#define EFI_PCI_IO_ATTRIBUTE_VGA_PALETTE_IO_16 0x20000
#define EFI_PCI_IO_ATTRIBUTE_VGA_IO_16 0x40000

typedef struct _EFI_PCI_IO_PROTOCOL EFI_PCI_IO_PROTOCOL;

typedef enum {
	EfiPciIoWidthUint8,
	EfiPciIoWidthUint16,
	EfiPciIoWidthUint32,
	EfiPciIoWidthUint64,
	EfiPciIoWidthFifoUint8,
	EfiPciIoWidthFifoUint16,
	EfiPciIoWidthFifoUint32,
	EfiPciIoWidthFifoUint64,
	EfiPciIoWidthFillUint8,
	EfiPciIoWidthFillUint16,
	EfiPciIoWidthFillUint32,
	EfiPciIoWidthFillUint64,
	EfiPciIoWidthMaximum
} EFI_PCI_IO_PROTOCOL_WIDTH;

typedef enum {
	EfiPciIoOperationBusMasterRead,
	EfiPciIoOperationBusMasterWrite,
	EfiPciIoOperationBusMasterCommonBuffer,
	EfiPciIoOperationMaximum
} EFI_PCI_IO_PROTOCOL_OPERATION;

typedef enum {
	EfiPciIoAttributeOperationGet,
	EfiPciIoAttributeOperationSet,
	EfiPciIoAttributeOperationEnable,
	EfiPciIoAttributeOperationDisable,
	EfiPciIoAttributeOperationSupported,
	EfiPciIoAttributeOperationMaximum
} EFI_PCI_IO_PROTOCOL_ATTRIBUTE_OPERATION;

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_POLL_IO_MEM)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_PCI_IO_PROTOCOL_WIDTH Width,
	IN EFI_UINT8 BarIndex,
	IN EFI_UINT64 Offset,
	IN EFI_UINT64 Mask,
	IN EFI_UINT64 Value,
	IN EFI_UINT64 Delay,
	OUT EFI_UINT64 *Result
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_IO_MEM)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_PCI_IO_PROTOCOL_WIDTH Width,
	IN EFI_UINT8 BarIndex,
	IN EFI_UINT64 Offset,
	IN EFI_UINTN Count,
	IN OUT VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_CONFIG)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_PCI_IO_PROTOCOL_WIDTH Width,
	IN EFI_UINT32 Offset,
	IN EFI_UINTN Count,
	IN OUT VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_POLL_IO_MEM)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_PCI_IO_PROTOCOL_WIDTH Width,
	IN EFI_UINT8 BarIndex,
	IN EFI_UINT64 Offset,
	IN EFI_UINT64 Mask,
	IN EFI_UINT64 Value,
	IN EFI_UINT64 Delay,
	OUT EFI_UINT64 *Result
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_MEM)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_PCI_IO_PROTOCOL_WIDTH Width,
	IN EFI_UINT8 BarIndex,
	IN EFI_UINT64 Offset,
	IN EFI_UINTN Count,
	IN OUT VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_COPY_MEM)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_PCI_IO_PROTOCOL_WIDTH Width,
	IN EFI_UINT8 DestBarIndex,
	IN EFI_UINT64 DestOffset,
	IN EFI_UINT8 SrcBarIndex,
	IN EFI_UINT64 SrcOffset,
	IN EFI_UINTN Count
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_MAP)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_PCI_IO_PROTOCOL_OPERATION Operation,
	IN VOID *HostAddress,
	IN OUT EFI_UINTN *NumberOfBytes,
	OUT EFI_PHYSICAL_ADDRESS *DeviceAddress,
	OUT VOID **Mapping
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_UNMAP)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN VOID *Mapping
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_ALLOCATE_BUFFER)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_ALLOCATE_TYPE Type,
	IN EFI_MEMORY_TYPE MemoryType,
	IN EFI_UINTN Pages,
	OUT VOID **HostAddress,
	IN EFI_UINT64 Attributes
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_FREE_BUFFER)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_UINTN Pages,
	IN VOID *HostAddress
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_FLUSH)(
	IN EFI_PCI_IO_PROTOCOL *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_GET_LOCATION)(
	IN EFI_PCI_IO_PROTOCOL *This,
	OUT EFI_UINTN *SegmentNumber,
	OUT EFI_UINTN *BusNumber,
	OUT EFI_UINTN *DeviceNumber,
	OUT EFI_UINTN *FunctionNumber
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_ATTRIBUTES)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_PCI_IO_PROTOCOL_ATTRIBUTE_OPERATION Operation,
	IN EFI_UINT64 Attributes,
	OUT EFI_UINT64 *Result OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_GET_BAR_ATTRIBUTES)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_UINT8 BarIndex,
	OUT EFI_UINT64 *Supports OPTIONAL,
	OUT VOID **Resources OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_IO_PROTOCOL_SET_BAR_ATTRIBUTES)(
	IN EFI_PCI_IO_PROTOCOL *This,
	IN EFI_UINT64 Attributes,
	IN EFI_UINT8 BarIndex,
	IN OUT EFI_UINT64 *Offset,
	IN OUT EFI_UINT64 *Length
);

typedef struct {
	EFI_PCI_IO_PROTOCOL_IO_MEM Read;
	EFI_PCI_IO_PROTOCOL_IO_MEM Write;
} EFI_PCI_IO_PROTOCOL_ACCESS;

typedef struct {
	EFI_PCI_IO_PROTOCOL_CONFIG Read;
	EFI_PCI_IO_PROTOCOL_CONFIG Write;
} EFI_PCI_IO_PROTOCOL_CONFIG_ACCESS;

typedef struct _EFI_PCI_IO_PROTOCOL {
EFI_PCI_IO_PROTOCOL_POLL_IO_MEM PollMem;
EFI_PCI_IO_PROTOCOL_POLL_IO_MEM PollIo;
EFI_PCI_IO_PROTOCOL_ACCESS Mem;
EFI_PCI_IO_PROTOCOL_ACCESS Io;
EFI_PCI_IO_PROTOCOL_CONFIG_ACCESS Pci;
EFI_PCI_IO_PROTOCOL_COPY_MEM CopyMem;
EFI_PCI_IO_PROTOCOL_MAP Map;
EFI_PCI_IO_PROTOCOL_UNMAP Unmap;
EFI_PCI_IO_PROTOCOL_ALLOCATE_BUFFER AllocateBuffer;
EFI_PCI_IO_PROTOCOL_FREE_BUFFER FreeBuffer;
EFI_PCI_IO_PROTOCOL_FLUSH Flush;
EFI_PCI_IO_PROTOCOL_GET_LOCATION GetLocation;
EFI_PCI_IO_PROTOCOL_ATTRIBUTES Attributes;
EFI_PCI_IO_PROTOCOL_GET_BAR_ATTRIBUTES GetBarAttributes;
EFI_PCI_IO_PROTOCOL_SET_BAR_ATTRIBUTES SetBarAttributes;
EFI_UINT64 RomSize;
VOID *RomImage;
} EFI_PCI_IO_PROTOCOL;

#endif /* EFI_PROTOCOLS_PCI_BUS_H */
