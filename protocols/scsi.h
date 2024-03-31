#ifndef EFI_PROTOCOLS_SCSI_H
#define EFI_PROTOCOLS_SCSI_H

////
// SCSI I/O Protocol
///

#define EFI_SCSI_IO_PROTOCOL_GUID {0x932f47e6,0x2362,0x4002, {0x80,0x3e,0x3c,0xd5,0x4b,0x13,0x8f,0x85}}

// SCSI Primary Commands
#define EFI_SCSI_IO_TYPE_DISK 0x00 // Disk device
#define EFI_SCSI_IO_TYPE_TAPE 0x01 // Tape device
#define EFI_SCSI_IO_TYPE_PRINTER 0x02 // Printer
#define EFI_SCSI_IO_TYPE_PROCESSOR 0x03 // Processor
#define EFI_SCSI_IO_TYPE_WORM 0x04 // Write-once read-multiple
#define EFI_SCSI_IO_TYPE_CDROM 0x05 // CD or DVD device
#define EFI_SCSI_IO_TYPE_SCANNER 0x06 // Scanner device
#define EFI_SCSI_IO_TYPE_OPTICAL 0x07 // Optical memory device
#define EFI_SCSI_IO_TYPE_MEDIUMCHANGER 0x08 // Medium Changer device
#define EFI_SCSI_IO_TYPE_COMMUNICATION 0x09 // Communications device
#define MFI_SCSI_IO_TYPE_A 0x0A // Obsolete
#define MFI_SCSI_IO_TYPE_B 0x0B // Obsolete
#define MFI_SCSI_IO_TYPE_RAID 0x0C // Storage array controller device (RAID)
#define MFI_SCSI_IO_TYPE_SES 0x0D // Enclosure services device
#define MFI_SCSI_IO_TYPE_RBC 0x0E // Simplified direct-access device
#define MFI_SCSI_IO_TYPE_OCRW 0x0F // Optical card r/w device
#define MFI_SCSI_IO_TYPE_BRIDGE 0x10 // Bridge Controller Commands
#define MFI_SCSI_IO_TYPE_OSD 0x11 // Object-based Storage Device
#define EFI_SCSI_IO_TYPE_RESERVED_LOW 0x12 // Reserved (low)
#define EFI_SCSI_IO_TYPE_RESERVED_HIGH 0x1E // Reserved (high)
#define EFI_SCSI_IO_TYPE_UNKNOWN 0x1F // Unknown no device type

// DataDirection
#define EFI_SCSI_IO_DATA_DIRECTION_READ 0
#define EFI_SCSI_IO_DATA_DIRECTION_WRITE 1
#define EFI_SCSI_IO_DATA_DIRECTION_BIDIRECTIONAL 2

// HostAdapterStatus
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_OK 0x00
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_TIMEOUT_COMMAND 0x09
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_TIMEOUT 0x0b
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_MESSAGE_REJECT 0x0d
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_BUS_RESET 0x0e
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_PARITY_ERROR 0x0f
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_REQUEST_SENSE_FAILED 0x10
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_SELECTION_TIMEOUT 0x11
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_DATA_OVERRUN_UNDERRUN 0x12
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_BUS_FREE 0x13
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_PHASE_ERROR 0x14
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_OTHER 0x7f

// TargetStatus
#define EFI_SCSI_IO_STATUS_TARGET_GOOD 0x00
#define EFI_SCSI_IO_STATUS_TARGET_CHECK_CONDITION 0x02
#define EFI_SCSI_IO_STATUS_TARGET_CONDITION_MET 0x04
#define EFI_SCSI_IO_STATUS_TARGET_BUSY 0x08
#define EFI_SCSI_IO_STATUS_TARGET_INTERMEDIATE 0x10
#define EFI_SCSI_IO_STATUS_TARGET_INTERMEDIATE_CONDITION_METn 0x14
#define EFI_SCSI_IO_STATUS_TARGET_RESERVATION_CONFLICT 0x18
#define EFI_SCSI_IO_STATUS_TARGET_COMMAND_TERMINATED 0x22
#define EFI_SCSI_IO_STATUS_TARGET_QUEUE_FULL 0x28

typedef struct _EFI_SCSI_IO_PROTOCOL EFI_SCSI_IO_PROTOCOL;

typedef struct {
	UINT64 Timeout;
	VOID *InDataBuffer;
	VOID *OutDataBuffer;
	VOID *SenseData;
	VOID *Cdb;
	UINT32 InTransferLength;
	UINT32 OutTransferLength;
	UINT8 CdbLength;
	UINT8 DataDirection;
	UINT8 HostAdapterStatus;
	UINT8 TargetStatus;
	UINT8 SenseDataLength;
} EFI_SCSI_IO_SCSI_REQUEST_PACKET;

typedef
EFI_STATUS
(EFIAPI *EFI_SCSI_IO_PROTOCOL_GET_DEVICE_TYPE)(
	IN EFI_SCSI_IO_PROTOCOL *This,
	OUT UINT8 *DeviceType
);

typedef
EFI_STATUS
(EFIAPI *EFI_SCSI_IO_PROTOCOL_GET_DEVICE_LOCATION)(
	IN EFI_SCSI_IO_PROTOCOL *This,
	IN OUT UINT8 **Target,
	OUT UINT64 *Lun
);

typedef
EFI_STATUS
(EFIAPI *EFI_SCSI_IO_PROTOCOL_RESET_BUS)(
	IN EFI_SCSI_IO_PROTOCOL *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_SCSI_IO_PROTOCOL_RESET_DEVICE)(
	IN EFI_SCSI_IO_PROTOCOL *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_SCSI_IO_PROTOCOL_EXECUTE_SCSI_COMMAND)(
	IN EFI_SCSI_IO_PROTOCOL *This,
	IN OUT EFI_SCSI_IO_SCSI_REQUEST_PACKET *Packet,
	IN EFI_EVENT Event OPTIONAL
);

typedef struct _EFI_SCSI_IO_PROTOCOL {
	EFI_SCSI_IO_PROTOCOL_GET_DEVICE_TYPE GetDeviceType;
	EFI_SCSI_IO_PROTOCOL_GET_DEVICE_LOCATION GetDeviceLocation;
	EFI_SCSI_IO_PROTOCOL_RESET_BUS ResetBus;
	EFI_SCSI_IO_PROTOCOL_RESET_DEVICE ResetDevice;
	EFI_SCSI_IO_PROTOCOL_EXECUTE_SCSI_COMMAND ExecuteScsiCommand;
	UINT32 IoAlign;
} EFI_SCSI_IO_PROTOCOL;

////
// Extended SCSI Pass Thru Protocol
///

#define EFI_EXT_SCSI_PASS_THRU_PROTOCOL_GUID {0x143b7632,0xb81b,0x4cb7, {0xab,0xd3,0xb6,0x25,0xa5,0xb9,0xbf,0xfe}}

#define TARGET_MAX_BYTES 0x10
#define EFI_EXT_SCSI_PASS_THRU_ATTRIBUTES_PHYSICAL 0x0001
#define EFI_EXT_SCSI_PASS_THRU_ATTRIBUTES_LOGICAL 0x0002
#define EFI_EXT_SCSI_PASS_THRU_ATTRIBUTES_NONBLOCKIO 0x0004

// DataDirection
#define EFI_EXT_SCSI_DATA_DIRECTION_READ 0
#define EFI_EXT_SCSI_DATA_DIRECTION_WRITE 1
#define EFI_EXT_SCSI_DATA_DIRECTION_BIDIRECTIONAL 2

// HostAdapterStatus
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_OK 0x00
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_TIMEOUT_COMMAND 0x09
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_TIMEOUT 0x0b
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_MESSAGE_REJECT 0x0d
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_BUS_RESET 0x0e
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_PARITY_ERROR 0x0f
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_REQUEST_SENSE_FAILED 0x10
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_SELECTION_TIMEOUT 0x11
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_DATA_OVERRUN_UNDERRUN 0x12
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_BUS_FREE 0x13
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_PHASE_ERROR 0x14
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_OTHER 0x7f

// TargetStatus
#define EFI_EXT_SCSI_STATUS_TARGET_GOOD 0x00
#define EFI_EXT_SCSI_STATUS_TARGET_CHECK_CONDITION 0x02
#define EFI_EXT_SCSI_STATUS_TARGET_CONDITION_MET 0x04
#define EFI_EXT_SCSI_STATUS_TARGET_BUSY 0x08
#define EFI_EXT_SCSI_STATUS_TARGET_INTERMEDIATE 0x10
#define EFI_EXT_SCSI_STATUS_TARGET_INTERMEDIATE_CONDITION_MET 0x14
#define EFI_EXT_SCSI_STATUS_TARGET_RESERVATION_CONFLICT 0x18
#define EFI_EXT_SCSI_STATUS_TARGET_TASK_SET_FULL 0x28
#define EFI_EXT_SCSI_STATUS_TARGET_ACA_ACTIVE 0x30
#define EFI_EXT_SCSI_STATUS_TARGET_TASK_ABORTED 0x40

typedef struct _EFI_EXT_SCSI_PASS_THRU_PROTOCOL EFI_EXT_SCSI_PASS_THRU_PROTOCOL;

typedef struct {
	UINT32 *AdapterId;
	UINT32 *Attributes;
	UINT32 *IoAlign;
} EFI_EXT_SCSI_PASS_THRU_MODE;

typedef struct {
	UINT64 Timeout;
	VOID *InDataBuffer;
	VOID *OutDataBuffer;
	VOID *SenseData;
	VOID *Cdb;
	UINT32 InTransferLength;
	UINT32 OutTransferLength;
	UINT8 CdbLength;
	UINT8 DataDirection;
	UINT8 HostAdapterStatus;
	UINT8 TargetStatus;
	UINT8 SenseDataLength;
} EFI_EXT_SCSI_PASS_THRU_SCSI_REQUEST_PACKET;

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_PASSTHRU)(
	IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL *This,
	IN UINT8 *Target,
	IN UINT64 Lun,
	IN OUT EFI_EXT_SCSI_PASS_THRU_SCSI_REQUEST_PACKET *Packet,
	IN EFI_EVENT Event OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_GET_NEXT_TARGET_LUN)(
	IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL *This,
	IN OUT UINT8 **Target,
	IN OUT UINT64 *Lun
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_BUILD_DEVICE_PATH)(
	IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL *This,
	IN UINT8 *Target,
	IN UINT64 Lun,
	OUT EFI_DEVICE_PATH_PROTOCOL **DevicePath
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_GET_TARGET_LUN)(
	IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL *This,
	IN EFI_DEVICE_PATH_PROTOCOL *DevicePath,
	OUT UINT8 **Target,
	OUT UINT64 *Lun
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_RESET_CHANNEL)(
	IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_RESET_TARGET_LUN)(
	IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL *This,
	IN UINT8 *Target,
	IN UINT64 Lun
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_GET_NEXT_TARGET)(
	IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL *This,
	IN OUT UINT8 **Target
);

typedef struct _EFI_EXT_SCSI_PASS_THRU_PROTOCOL {
	EFI_EXT_SCSI_PASS_THRU_MODE *Mode;
	EFI_EXT_SCSI_PASS_THRU_PASSTHRU PassThru;
	EFI_EXT_SCSI_PASS_THRU_GET_NEXT_TARGET_LUN GetNextTargetLun;
	EFI_EXT_SCSI_PASS_THRU_BUILD_DEVICE_PATH BuildDevicePath;
	EFI_EXT_SCSI_PASS_THRU_GET_TARGET_LUN GetTargetLun;
	EFI_EXT_SCSI_PASS_THRU_RESET_CHANNEL ResetChannel;
	EFI_EXT_SCSI_PASS_THRU_RESET_TARGET_LUN ResetTargetLun;
	EFI_EXT_SCSI_PASS_THRU_GET_NEXT_TARGET GetNextTarget;
} EFI_EXT_SCSI_PASS_THRU_PROTOCOL;

////
// iSCSI Initiator Name Protocol
///

#define EFI_ISCSI_INITIATOR_NAME_PROTOCOL_GUID {0x59324945,0xec44,0x4c0d, {0xb1,0xcd,0x9d,0xb1,0x39,0xdf,0x07,0x0c}}

typedef struct _EFI_ISCSI_INITIATOR_NAME_PROTOCOL EFI_ISCSI_INITIATOR_NAME_PROTOCOL;

typedef EFI_STATUS
(EFIAPI *EFI_ISCSI_INITIATOR_NAME_GET)(
	IN EFI_ISCSI_INITIATOR_NAME_PROTOCOL *This,
	IN OUT UINTN *BufferSize,
	OUT VOID *Buffer
);

typedef EFI_STATUS
(EFIAPI *EFI_ISCSI_INITIATOR_NAME_SET)(
	IN EFI_ISCSI_INITIATOR_NAME_PROTOCOL *This,
	IN OUT UINTN *BufferSize,
	IN VOID *Buffer
);

typedef struct _EFI_ISCSI_INITIATOR_NAME_PROTOCOL {
	EFI_ISCSI_INITIATOR_NAME_GET Get;
	EFI_ISCSI_INITIATOR_NAME_SET Set;
} EFI_ISCSI_INITIATOR_NAME_PROTOCOL;

#endif /* EFI_PROTOCOLS_SCSI_H */