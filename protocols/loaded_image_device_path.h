#ifndef EFI_PROTOCOLS_LOADED_IMAGE_DEVICE_PATH_H
#define EFI_PROTOCOLS_LOADED_IMAGE_DEVICE_PATH_H

#define EFI_LOADED_IMAGE_DEVICE_PATH_PROTOCOL_GUID {0xbc62157e,0x3e33,0x4fec, {0x99,0x20,0x2d,0x3b,0x36,0xd7,0x50,0xdf}}

// UEFI Spec 2.10, 9.2.1:
// The Loaded Image Device Path Protocol uses the same protocol interface structure as the Device Path Protocol defined
// in Chapter 9. The only difference between the Device Path Protocol and the Loaded Image Device Path Protocol is
// the protocol GUID value.
typedef EFI_DEVICE_PATH_PROTOCOL EFI_LOADED_IMAGE_DEVICE_PATH_PROTOCOL;

#endif /* EFI_PROTOCOLS_LOADED_IMAGE_DEVICE_PATH_H */
