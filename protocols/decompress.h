#ifndef EFI_PROTOCOLS_DECOMPRESS_H
#define EFI_PROTOCOLS_DECOMPRESS_H

////
// Decompress Protocol
///

#define EFI_DECOMPRESS_PROTOCOL_GUID {0xd8117cfe,0x94a6,0x11d4, {0x9a,0x3a,0x00,0x90,0x27,0x3f,0xc1,0x4d}}

typedef struct _EFI_DECOMPRESS_PROTOCOL EFI_DECOMPRESS_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_DECOMPRESS_GET_INFO)(
	IN EFI_DECOMPRESS_PROTOCOL *This,
	IN VOID *Source,
	IN EFI_UINT32 SourceSize,
	OUT EFI_UINT32 *DestinationSize,
	OUT EFI_UINT32 *ScratchSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_DECOMPRESS_DECOMPRESS)(
	IN EFI_DECOMPRESS_PROTOCOL *This,
	IN VOID *Source,
	IN EFI_UINT32 SourceSize,
	IN OUT VOID *Destination,
	IN EFI_UINT32 DestinationSize,
	IN OUT VOID *Scratch,
	IN EFI_UINT32 ScratchSize
);

typedef struct _EFI_DECOMPRESS_PROTOCOL {
	EFI_DECOMPRESS_GET_INFO GetInfo;
	EFI_DECOMPRESS_DECOMPRESS Decompress;
} EFI_DECOMPRESS_PROTOCOL;

#endif /* EFI_PROTOCOLS_DECOMPRESS_H */
