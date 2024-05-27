#ifndef EFI_PROTOCOLS_DEBUGGER_H
#define EFI_PROTOCOLS_DEBUGGER_H

#include "loaded_image.h"

////
// Debug Support Protocol
///

#define EFI_DEBUG_SUPPORT_PROTOCOL_GUID {0x2755590c,0x6f3c,0x42fa, {0x9e,0xa4,0xa3,0xba,0x54,0x3c,0xda,0x25}}

// EBC Exception types
#define EXCEPT_EBC_UNDEFINED 0
#define EXCEPT_EBC_DIVIDE_ERROR 1
#define EXCEPT_EBC_DEBUG 2
#define EXCEPT_EBC_BREAKPOINT 3
#define EXCEPT_EBC_OVERFLOW 4
#define EXCEPT_EBC_INVALID_OPCODE 5
#define EXCEPT_EBC_STACK_FAULT 6
#define EXCEPT_EBC_ALIGNMENT_CHECK 7
#define EXCEPT_EBC_INSTRUCTION_ENCODING 8
#define EXCEPT_EBC_BAD_BREAK 9
#define EXCEPT_EBC_SINGLE_STEP 1

// IA-32 Exception types
#define EXCEPT_IA32_DIVIDE_ERROR 0
#define EXCEPT_IA32_DEBUG 1
#define EXCEPT_IA32_NMI 2
#define EXCEPT_IA32_BREAKPOINT 3
#define EXCEPT_IA32_OVERFLOW 4
#define EXCEPT_IA32_BOUND 5
#define EXCEPT_IA32_INVALID_OPCODE 6
#define EXCEPT_IA32_DOUBLE_FAULT 8
#define EXCEPT_IA32_INVALID_TSS 10
#define EXCEPT_IA32_SEG_NOT_PRESENT 11
#define EXCEPT_IA32_STACK_FAULT 12
#define EXCEPT_IA32_GP_FAULT 13
#define EXCEPT_IA32_PAGE_FAULT 14
#define EXCEPT_IA32_FP_ERROR 16
#define EXCEPT_IA32_ALIGNMENT_CHECK 17
#define EXCEPT_IA32_MACHINE_CHECK 18
#define EXCEPT_IA32_SIMD 19

// X64 Exception types
#define EXCEPT_X64_DIVIDE_ERROR 0
#define EXCEPT_X64_DEBUG 1
#define EXCEPT_X64_NMI 2
#define EXCEPT_X64_BREAKPOINT 3
#define EXCEPT_X64_OVERFLOW 4
#define EXCEPT_X64_BOUND 5
#define EXCEPT_X64_INVALID_OPCODE 6
#define EXCEPT_X64_DOUBLE_FAULT 8
#define EXCEPT_X64_INVALID_TSS 10
#define EXCEPT_X64_SEG_NOT_PRESENT 11
#define EXCEPT_X64_STACK_FAULT 12
#define EXCEPT_X64_GP_FAULT 13
#define EXCEPT_X64_PAGE_FAULT 14
#define EXCEPT_X64_FP_ERROR 16
#define EXCEPT_X64_ALIGNMENT_CHECK 17
#define EXCEPT_X64_MACHINE_CHECK 18
#define EXCEPT_X64_SIMD 19

// Itanium Processor Family Exception types
#define EXCEPT_IPF_VHTP_TRANSLATION 0
#define EXCEPT_IPF_INSTRUCTION_TLB 1
#define EXCEPT_IPF_DATA_TLB 2
#define EXCEPT_IPF_ALT_INSTRUCTION_TLB 3
#define EXCEPT_IPF_ALT_DATA_TLB 4
#define EXCEPT_IPF_DATA_NESTED_TLB 5
#define EXCEPT_IPF_INSTRUCTION_KEY_MISSED 6
#define EXCEPT_IPF_DATA_KEY_MISSED 7
#define EXCEPT_IPF_DIRTY_BIT 8
#define EXCEPT_IPF_INSTRUCTION_ACCESS_BIT 9
#define EXCEPT_IPF_DATA_ACCESS_BIT 10
#define EXCEPT_IPF_BREAKPOINT 11
#define EXCEPT_IPF_EXTERNAL_INTERRUPT 12
#define EXCEPT_IPF_PAGE_NOT_PRESENT 20
#define EXCEPT_IPF_KEY_PERMISSION 21
#define EXCEPT_IPF_INSTRUCTION_ACCESS_RIGHTS 22
#define EXCEPT_IPF_DATA_ACCESS_RIGHTS 23
#define EXCEPT_IPF_GENERAL_EXCEPTION 24
#define EXCEPT_IPF_DISABLED_FP_REGISTER 25
#define EXCEPT_IPF_NAT_CONSUMPTION 26
#define EXCEPT_IPF_SPECULATION 27
#define EXCEPT_IPF_DEBUG 29
#define EXCEPT_IPF_UNALIGNED_REFERENCE 30
#define EXCEPT_IPF_UNSUPPORTED_DATA_REFERENCE 31
#define EXCEPT_IPF_FP_FAULT 32
#define EXCEPT_IPF_FP_TRAP 33
#define EXCEPT_IPF_LOWER_PRIVILEGE_TRANSFER_TRAP 34
#define EXCEPT_IPF_TAKEN_BRANCH 35
#define EXCEPT_IPF_SINGLE_STEP 36
#define EXCEPT_IPF_IA32_EXCEPTION 45
#define EXCEPT_IPF_IA32_INTERCEPT 46
#define EXCEPT_IPF_IA32_INTERRUPT 47

// ARM processor exception types
#define EXCEPT_ARM_RESET 0
#define EXCEPT_ARM_UNDEFINED_INSTRUCTION 1
#define EXCEPT_ARM_SOFTWARE_INTERRUPT 2
#define EXCEPT_ARM_PREFETCH_ABORT 3
#define EXCEPT_ARM_DATA_ABORT 4
#define EXCEPT_ARM_RESERVED 5
#define EXCEPT_ARM_IRQ 6
#define EXCEPT_ARM_FIQ 7
#define MAX_ARM_EXCEPTION EXCEPT_ARM_FIQ

// AARCH64 processor exception types.
#define EXCEPT_AARCH64_SYNCHRONOUS_EXCEPTIONS 0
#define EXCEPT_AARCH64_IRQ 1
#define EXCEPT_AARCH64_FIQ 2
#define EXCEPT_AARCH64_SERROR 3

#define MAX_AARCH64_EXCEPTION EXCEPT_AARCH64_SERROR

// RISC-V processor exception types.
#define EXCEPT_RISCV_INST_MISALIGNED 0
#define EXCEPT_RISCV_INST_ACCESS_FAULT 1
#define EXCEPT_RISCV_ILLEGAL_INST 2
#define EXCEPT_RISCV_BREAKPOINT 3
#define EXCEPT_RISCV_LOAD_ADDRESS_MISALIGNED 4
#define EXCEPT_RISCV_LOAD_ACCESS_FAULT 5
#define EXCEPT_RISCV_STORE_AMO_ADDRESS_MISALIGNED 6
#define EXCEPT_RISCV_STORE_AMO_ACCESS_FAULT 7
#define EXCEPT_RISCV_ENV_CALL_FROM_UMODE 8
#define EXCEPT_RISCV_ENV_CALL_FROM_SMODE 9
#define EXCEPT_RISCV_ENV_CALL_FROM_MMODE 11
#define EXCEPT_RISCV_INST_PAGE_FAULT 12
#define EXCEPT_RISCV_LOAD_PAGE_FAULT 13
#define EXCEPT_RISCV_STORE_AMO_PAGE_FAULT 15

// RISC-V processor interrupt types.
#define EXCEPT_RISCV_SUPERVISOR_SOFTWARE_INT 1
#define EXCEPT_RISCV_MACHINE_SOFTWARE_INT 3
#define EXCEPT_RISCV_SUPERVISOR_TIMER_INT 5
#define EXCEPT_RISCV_MACHINE_TIMER_INT 7
#define EXCEPT_RISCV_SUPERVISOR_EXTERNAL_INT 9
#define EXCEPT_RISCV_MACHINE_EXTERNAL_INT 11

// LoongArch processor exception types.
#define EXCEPT_LOONGARCH_INT 0
#define EXCEPT_LOONGARCH_PIL 1
#define EXCEPT_LOONGARCH_PIS 2
#define EXCEPT_LOONGARCH_PIF 3
#define EXCEPT_LOONGARCH_PME 4
#define EXCEPT_LOONGARCH_PNR 5
#define EXCEPT_LOONGARCH_PNX 6
#define EXCEPT_LOONGARCH_PPI 7
#define EXCEPT_LOONGARCH_ADE 8
#define EXCEPT_LOONGARCH_ALE 9
#define EXCEPT_LOONGARCH_BCE 10
#define EXCEPT_LOONGARCH_SYS 11
#define EXCEPT_LOONGARCH_BRK 12
#define EXCEPT_LOONGARCH_INE 13
#define EXCEPT_LOONGARCH_IPE 14
#define EXCEPT_LOONGARCH_FPD 15
#define EXCEPT_LOONGARCH_SXD 16
#define EXCEPT_LOONGARCH_ASXD 17
#define EXCEPT_LOONGARCH_FPE 18

// LoongArch processor Interrupt types.
#define EXCEPT_LOONGARCH_INT_SIP0 0
#define EXCEPT_LOONGARCH_INT_SIP1 1
#define EXCEPT_LOONGARCH_INT_IP0 2
#define EXCEPT_LOONGARCH_INT_IP1 3
#define EXCEPT_LOONGARCH_INT_IP2 4
#define EXCEPT_LOONGARCH_INT_IP3 5
#define EXCEPT_LOONGARCH_INT_IP4 6
#define EXCEPT_LOONGARCH_INT_IP5 7
#define EXCEPT_LOONGARCH_INT_IP6 8
#define EXCEPT_LOONGARCH_INT_IP7 9
#define EXCEPT_LOONGARCH_INT_PMC 10
#define EXCEPT_LOONGARCH_INT_TIMER 11
#define EXCEPT_LOONGARCH_INT_IPI 12
#define MAX_LOONGARCH_INTERRUPT 14

typedef struct _EFI_DEBUG_SUPPORT_PROTOCOL EFI_DEBUG_SUPPORT_PROTOCOL;

typedef EFI_INTN EFI_EXCEPTION_TYPE;

typedef enum {
	IsaIa32 = 0x014C, // IMAGE_FILE_MACHINE_I386
	IsaX64 = 0x8664, // IMAGE_FILE_MACHINE_X64
	IsaIpf = 0x0200, // IMAGE_FILE_MACHINE_IA64
	IsaEbc = 0x0EBC, // IMAGE_FILE_MACHINE_EBC
	IsaArm = 0x1C2, // IMAGE_FILE_MACHINE_ARMTHUMB_MIXED
	IsaAArch64 = 0xAA64, // IMAGE_FILE_MACHINE_AARCH64
	IsaRISCV32 = 0x5032, // I\nMAGE_FILE_MACHINE_RISCV32
	IsaRISCV64 = 0x5064, // IMAGE_FILE_MACHINE_RISCV64
	IsaRISCV128 = 0x5128, // IMAGE_FILE_MACHINE_RISCV128
	IsaLoongArch32 = 0x6232, // IMAGE_FILE_MACHINE_LOONGARCH32
	IsaLoongArch64 = 0x6264 // IMAGE_FILE_MACHINE_LOONGARCH64
} EFI_INSTRUCTION_SET_ARCHITECTURE;

typedef struct {
	EFI_UINT64 R0, R1, R2, R3, R4, R5, R6, R7;
	EFI_UINT64 Flags;
	EFI_UINT64 ControlFlags;
	EFI_UINT64 Ip;
} EFI_SYSTEM_CONTEXT_EBC;

typedef struct {
	EFI_UINT16 Fcw;
	EFI_UINT16 Fsw;
	EFI_UINT16 Ftw;
	EFI_UINT16 Opcode;
	EFI_UINT32 Eip;
	EFI_UINT16 Cs;
	EFI_UINT16 Reserved1;
	EFI_UINT32 DataOffset;
	EFI_UINT16 Ds;EFI_UINT8 Reserved2[10];
	EFI_UINT8 St0Mm0[10], Reserved3[6];
	EFI_UINT8 St1Mm1[10], Reserved4[6];
	EFI_UINT8 St2Mm2[10], Reserved5[6];
	EFI_UINT8 St3Mm3[10], Reserved6[6];
	EFI_UINT8 St4Mm4[10], Reserved7[6];
	EFI_UINT8 St5Mm5[10], Reserved8[6];
	EFI_UINT8 St6Mm6[10], Reserved9[6];
	EFI_UINT8 St7Mm7[10], Reserved10[6];
	EFI_UINT8 Xmm0[16];
	EFI_UINT8 Xmm1[16];
	EFI_UINT8 Xmm2[16];
	EFI_UINT8 Xmm3[16];
	EFI_UINT8 Xmm4[16];
	EFI_UINT8 Xmm5[16];
	EFI_UINT8 Xmm6[16];
	EFI_UINT8 Xmm7[16];
	EFI_UINT8 Reserved11[14 * 16];
} EFI_FX_SAVE_STATE_IA32;

typedef struct {
	EFI_UINT32 ExceptionData;
	EFI_FX_SAVE_STATE_IA32 FxSaveState;
	EFI_UINT32 Dr0, Dr1, Dr2, Dr3, Dr6, Dr7;
	EFI_UINT32 Cr0, Cr1 /* Reserved */, Cr2, Cr3, Cr4;
	EFI_UINT32 Eflags;
	EFI_UINT32 Ldtr, Tr;
	EFI_UINT32 Gdtr[2], Idtr[2];
	EFI_UINT32 Eip;
	EFI_UINT32 Gs, Fs, Es, Ds, Cs, Ss;
	EFI_UINT32 Edi, Esi, Ebp, Esp, Ebx, Edx, Ecx, Eax;
} EFI_SYSTEM_CONTEXT_IA32;

typedef struct {
	EFI_UINT16 Fcw;
	EFI_UINT16 Fsw;
	EFI_UINT16 Ftw;
	EFI_UINT16 Opcode;
	EFI_UINT64 Rip;
	EFI_UINT64 DataOffset;
	EFI_UINT8 Reserved1[8];
	EFI_UINT8 St0Mm0[10], Reserved2[6];
	EFI_UINT8 St1Mm1[10], Reserved3[6];
	EFI_UINT8 St2Mm2[10], Reserved4[6];
	EFI_UINT8 St3Mm3[10], Reserved5[6];
	EFI_UINT8 St4Mm4[10], Reserved6[6];
	EFI_UINT8 St5Mm5[10], Reserved7[6];
	EFI_UINT8 St6Mm6[10], Reserved8[6];
	EFI_UINT8 St7Mm7[10], Reserved9[6];
	EFI_UINT8 Xmm0[16];
	EFI_UINT8 Xmm1[16];
	EFI_UINT8 Xmm2[16];
	EFI_UINT8 Xmm3[16];
	EFI_UINT8 Xmm4[16];
	EFI_UINT8 Xmm5[16];
	EFI_UINT8 Xmm6[16];
	EFI_UINT8 Xmm7[16];
	EFI_UINT8 Reserved11[14 * 16];
} EFI_FX_SAVE_STATE_X64;

typedef struct {
	EFI_UINT64 ExceptionData;
	EFI_FX_SAVE_STATE_X64 FxSaveState;
	EFI_UINT64 Dr0, Dr1, Dr2, Dr3, Dr6, Dr7;
	EFI_UINT64 Cr0, Cr1 /* Reserved */, Cr2, Cr3, Cr4, Cr8;
	EFI_UINT64 Rflags;
	EFI_UINT64 Ldtr, Tr;
	EFI_UINT64 Gdtr[2], Idtr[2];
	EFI_UINT64 Rip;
	EFI_UINT64 Gs, Fs, Es, Ds, Cs, Ss;
	EFI_UINT64 Rdi, Rsi, Rbp, Rsp, Rbx, Rdx, Rcx, Rax;
	EFI_UINT64 R8, R9, R10, R11, R12, R13, R14, R15;
} EFI_SYSTEM_CONTEXT_X64;

typedef struct {
	EFI_UINT64 Reserved;
	EFI_UINT64 R1, R2, R3, R4, R5, R6, R7, R8, R9, R10,
		R11, R12, R13, R14, R15, R16, R17, R18, R19, R20,
		R21, R22, R23, R24, R25, R26, R27, R28, R29, R30,
		R31;
	EFI_UINT64 F2[2], F3[2], F4[2], F5[2], F6[2],
		F7[2], F8[2], F9[2], F10[2], F11[2],
		F12[2], F13[2], F14[2], F15[2], F16[2],
		F17[2], F18[2], F19[2], F20[2], F21[2],
		F22[2], F23[2], F24[2], F25[2], F26[2],
		F27[2], F28[2], F29[2], F30[2], F31[2];
	EFI_UINT64 Pr;
	EFI_UINT64 B0, B1, B2, B3, B4, B5, B6, B7;
	// application registers
	EFI_UINT64 ArRsc, ArBsp, ArBspstore, ArRnat;
	EFI_UINT64 ArFcr;
	EFI_UINT64 ArEflag, ArCsd, ArSsd, ArCflg;
	EFI_UINT64 ArFsr, ArFir, ArFdr;
	EFI_UINT64 ArCcv;
	EFI_UINT64 ArUnat;
	EFI_UINT64 ArFpsr;
	EFI_UINT64 ArPfs, ArLc, ArEc;
	// control registers
	EFI_UINT64 CrDcr, CrItm, CrIva, CrPta, CrIpsr, CrIsr;
	EFI_UINT64 CrIip, CrIfa, CrItir, CrIipa, CrIfs, CrIim;
	EFI_UINT64 CrIha;
	// debug registers
	EFI_UINT64 Dbr0, Dbr1, Dbr2, Dbr3, Dbr4, Dbr5, Dbr6, Dbr7;
	EFI_UINT64 Ibr0, Ibr1, Ibr2, Ibr3, Ibr4, Ibr5, Ibr6, Ibr7;
	// virtual registers
	EFI_UINT64 IntNat;
} EFI_SYSTEM_CONTEXT_IPF;

typedef struct {
	EFI_UINT32 R0;
	EFI_UINT32 R1;
	EFI_UINT32 R2;
	EFI_UINT32 R3;
	EFI_UINT32 R4;
	EFI_UINT32 R5;
	EFI_UINT32 R6;
	EFI_UINT32 R7;
	EFI_UINT32 R8;
	EFI_UINT32 R9;
	EFI_UINT32 R10;
	EFI_UINT32 R11;
	EFI_UINT32 R12;
	EFI_UINT32 SP;
	EFI_UINT32 LR;
	EFI_UINT32 PC;
	EFI_UINT32 CPSR;
	EFI_UINT32 DFSR;
	EFI_UINT32 DFAR;
	EFI_UINT32 IFSR;
} EFI_SYSTEM_CONTEXT_ARM;

typedef struct {
	// General Purpose Registers
	EFI_UINT64 X0;
	EFI_UINT64 X1;
	EFI_UINT64 X2;
	EFI_UINT64 X3;
	EFI_UINT64 X4;
	EFI_UINT64 X5;
	EFI_UINT64 X6;
	EFI_UINT64 X7;
	EFI_UINT64 X8;
	EFI_UINT64 X9;
	EFI_UINT64 X10;
	EFI_UINT64 X11;
	EFI_UINT64 X12;
	EFI_UINT64 X13;
	EFI_UINT64 X14;
	EFI_UINT64 X15;
	EFI_UINT64 X16;
	EFI_UINT64 X17;
	EFI_UINT64 X18;
	EFI_UINT64 X19;
	EFI_UINT64 X20;
	EFI_UINT64 X21;
	EFI_UINT64 X22;
	EFI_UINT64 X23;
	EFI_UINT64 X24;
	EFI_UINT64 X25;
	EFI_UINT64 X26;
	EFI_UINT64 X27;
	EFI_UINT64 X28;
	EFI_UINT64 FP; // x29 - Frame Pointer
	EFI_UINT64 LR; // x30 - Link Register
	EFI_UINT64 SP; // x31 - Stack Pointer
	// FP/SIMD Registers
	EFI_UINT64 V0[2];
	EFI_UINT64 V1[2];
	EFI_UINT64 V2[2];
	EFI_UINT64 V3[2];
	EFI_UINT64 V4[2];
	EFI_UINT64 V5[2];
	EFI_UINT64 V6[2];
	EFI_UINT64 V7[2];
	EFI_UINT64 V8[2];
	EFI_UINT64 V9[2];
	EFI_UINT64 V10[2];
	EFI_UINT64 V11[2];
	EFI_UINT64 V12[2];
	EFI_UINT64 V13[2];
	EFI_UINT64 V14[2];
	EFI_UINT64 V15[2];
	EFI_UINT64 V16[2];
	EFI_UINT64 V17[2];
	EFI_UINT64 V18[2];
	EFI_UINT64 V19[2];
	EFI_UINT64 V20[2];
	EFI_UINT64 V21[2];
	EFI_UINT64 V22[2];
	EFI_UINT64 V23[2];
	EFI_UINT64 V24[2];
	EFI_UINT64 V25[2];
	EFI_UINT64 V26[2];
	EFI_UINT64 V27[2];
	EFI_UINT64 V28[2];
	EFI_UINT64 V29[2];
	EFI_UINT64 V30[2];
	EFI_UINT64 V31[2];
	EFI_UINT64 ELR; // Exception Link Register
	EFI_UINT64 SPSR; // Saved Processor Status Register
	EFI_UINT64 FPSR; // Floating Point Status Register
	EFI_UINT64 ESR; // Exception syndrome register
	EFI_UINT64 FAR; // Fault Address Register
} EFI_SYSTEM_CONTEXT_AARCH64;

typedef struct {
	// Integer registers
	EFI_UINT32 Zero, Ra, Sp, Gp, Tp, T0, T1, T2;
	EFI_UINT32 S0FP, S1, A0, A1, A2, A3, A4, A5, A6, A7;
	EFI_UINT32 S2, S3, S4, S5, S6, S7, S8, S9, S10, S11;
	EFI_UINT32 T3, T4, T5, T6;
	// Floating registers for F, D and Q Standard Extensions
	EFI_UINT128 Ft0, Ft1, Ft2, Ft3, Ft4, Ft5, Ft6, Ft7;
	EFI_UINT128 Fs0, Fs1, Fa0, Fa1, Fa2, Fa3, Fa4, Fa5, Fa6, Fa7;
	EFI_UINT128 Fs2, Fs3, Fs4, Fs5, Fs6, Fs7, Fs8, Fs9, Fs10, Fs11;
	EFI_UINT128 Ft8, Ft9, Ft10, Ft11;
} EFI_SYSTEM_CONTEXT_RISCV32;

typedef struct {
	// Integer registers
	EFI_UINT64 Zero, Ra, Sp, Gp, Tp, T0, T1, T2;
	EFI_UINT64 S0FP, S1, A0, A1, A2, A3, A4, A5, A6, A7;
	EFI_UINT64 S2, S3, S4, S5, S6, S7, S8, S9, S10, S11;
	EFI_UINT64 T3, T4, T5, T6;
	EFI_UINT128 Ft0, Ft1, Ft2, Ft3, Ft4, Ft5, Ft6, Ft7;
	EFI_UINT128 Fs0, Fs1, Fa0, Fa1, Fa2, Fa3, Fa4, Fa5, Fa6, Fa7;
	EFI_UINT128 Fs2, Fs3, Fs4, Fs5, Fs6, Fs7, Fs8, Fs9, Fs10, Fs11;
	EFI_UINT128 Ft8, Ft9, Ft10, Ft11;
} EFI_SYSTEM_CONTEXT_RISCV64;

typedef struct {
	// Integer registers
	EFI_UINT128 Zero, Ra, Sp, Gp, Tp, T0, T1, T2;
	EFI_UINT128 S0FP, S1, A0, A1, A2, A3, A4, A5, A6, A7;
	EFI_UINT128 S2, S3, S4, S5, S6, S7, S8, S9, S10, S11;
	EFI_UINT128 T3, T4, T5, T6;
	// Floating registers for F, D and Q Standard Extensions
	EFI_UINT128 Ft0, Ft1, Ft2, Ft3, Ft4, Ft5, Ft6, Ft7;
	EFI_UINT128 Fs0, Fs1, Fa0, Fa1, Fa2, Fa3, Fa4, Fa5, Fa6, Fa7;
	EFI_UINT128 Fs2, Fs3, Fs4, Fs5, Fs6, Fs7, Fs8, Fs9, Fs10, Fs11;
	EFI_UINT128 Ft8, Ft9, Ft10, Ft11;
} EFI_SYSTEM_CONTEXT_RISCV128;

typedef struct {
	EFI_UINT64 R0;
	EFI_UINT64 R1;
	EFI_UINT64 R2;
	EFI_UINT64 R3;
	EFI_UINT64 R4;
	EFI_UINT64 R5;
	EFI_UINT64 R6;
	EFI_UINT64 R7;
	EFI_UINT64 R8;
	EFI_UINT64 R9;
	EFI_UINT64 R10;
	EFI_UINT64 R11;
	EFI_UINT64 R12;
	EFI_UINT64 R13;
	EFI_UINT64 R14;
	EFI_UINT64 R15;
	EFI_UINT64 R16;
	EFI_UINT64 R17;
	EFI_UINT64 R18;
	EFI_UINT64 R19;
	EFI_UINT64 R20;
	EFI_UINT64 R21;
	EFI_UINT64 R22;
	EFI_UINT64 R23;
	EFI_UINT64 R24;
	EFI_UINT64 R25;
	EFI_UINT64 R26;
	EFI_UINT64 R27;
	EFI_UINT64 R28;
	EFI_UINT64 R29;
	EFI_UINT64 R30;
	EFI_UINT64 R31;
	EFI_UINT64 CRMD; // CuRrent MoDe information
	EFI_UINT64 PRMD; // PRe-exception MoDe information
	EFI_UINT64 EUEN; // Extended component Unit ENable
	EFI_UINT64 MISC; // MISCellaneous controller
	EFI_UINT64 ECFG; // Execption ConFiGuration
	EFI_UINT64 ESTAT; // Exeption STATus
	EFI_UINT64 ERA; // Exception Return Address
	EFI_UINT64 BADV; // BAD Virtual address
	EFI_UINT64 BADI; // BAD Instruction
} EFI_SYSTEM_CONTEXT_LOONGARCH64;

typedef union {
	EFI_SYSTEM_CONTEXT_EBC *SystemContextEbc;
	EFI_SYSTEM_CONTEXT_IA32 *SystemContextIa32;
	EFI_SYSTEM_CONTEXT_X64 *SystemContextX64;
	EFI_SYSTEM_CONTEXT_IPF *SystemContextIpf;
	EFI_SYSTEM_CONTEXT_ARM *SystemContextArm;
	EFI_SYSTEM_CONTEXT_AARCH64 *SystemContextAArch64;
	EFI_SYSTEM_CONTEXT_RISCV32 *SystemContextRiscV32;
	EFI_SYSTEM_CONTEXT_RISCV64 *SystemContextRiscV64;
	EFI_SYSTEM_CONTEXT_RISCV128 *SystemContextRiscv128;
	EFI_SYSTEM_CONTEXT_LOONGARCH64 *SystemContextLongArch64;
} EFI_SYSTEM_CONTEXT;

typedef
VOID
(*EFI_PERIODIC_CALLBACK)(
	IN OUT EFI_SYSTEM_CONTEXT SystemContext
);

typedef
VOID
(*EFI_EXCEPTION_CALLBACK)(
	IN EFI_EXCEPTION_TYPE ExceptionType,
	IN OUT EFI_SYSTEM_CONTEXT SystemContext
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_MAXIMUM_PROCESSOR_INDEX)(
	IN EFI_DEBUG_SUPPORT_PROTOCOL *This,
	OUT EFI_UINTN *MaxProcessorIndex
);

typedef
EFI_STATUS
(EFIAPI *EFI_REGISTER_PERIODIC_CALLBACK)(
	IN EFI_DEBUG_SUPPORT_PROTOCOL *This,
	IN EFI_UINTN ProcessorIndex,
	IN EFI_PERIODIC_CALLBACK PeriodicCallback
);

typedef
EFI_STATUS
(EFIAPI *EFI_REGISTER_EXCEPTION_CALLBACK)(
	IN EFI_DEBUG_SUPPORT_PROTOCOL *This,
	IN EFI_UINTN ProcessorIndex,
	IN EFI_EXCEPTION_CALLBACK ExceptionCallback,
	IN EFI_EXCEPTION_TYPE ExceptionType
);

typedef
EFI_STATUS
(EFIAPI *EFI_INVALIDATE_INSTRUCTION_CACHE)(
	IN EFI_DEBUG_SUPPORT_PROTOCOL *This,
	IN EFI_UINTN ProcessorIndex,
	IN VOID *Start,
	IN EFI_UINT64 Length
);

typedef struct _EFI_DEBUG_SUPPORT_PROTOCOL {
	EFI_INSTRUCTION_SET_ARCHITECTURE Isa;
	EFI_GET_MAXIMUM_PROCESSOR_INDEX GetMaximumProcessorIndex;
	EFI_REGISTER_PERIODIC_CALLBACK RegisterPeriodicCallback;
	EFI_REGISTER_EXCEPTION_CALLBACK RegisterExceptionCallback;
	EFI_INVALIDATE_INSTRUCTION_CACHE InvalidateInstructionCache;
} EFI_DEBUG_SUPPORT_PROTOCOL;

////
// EFI Debug Port Protocol
///

#define EFI_DEBUGPORT_PROTOCOL_GUID {0xeba4e8d2,0x3858,0x41ec, {0xa2,0x81,0x26,0x47,0xba,0x96,0x60,0xd0}}

#define DEVICE_PATH_MESSAGING_DEBUGPORT EFI_DEBUGPORT_PROTOCOL_GUID
#define EFI_DEBUGPORT_VARIABLE_NAME L"DEBUGPORT"
#define EFI_DEBUGPORT_VARIABLE_GUID EFI_DEBUGPORT_PROTOCOL_GUID

typedef struct _EFI_DEBUGPORT_PROTOCOL EFI_DEBUGPORT_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_DEBUGPORT_RESET)(
	IN EFI_DEBUGPORT_PROTOCOL *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_DEBUGPORT_WRITE)(
	IN EFI_DEBUGPORT_PROTOCOL *This,
	IN EFI_UINT32 Timeout,
	IN OUT EFI_UINTN *BufferSize,
	IN VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_DEBUGPORT_READ)(
	IN EFI_DEBUGPORT_PROTOCOL *This,
	IN EFI_UINT32 Timeout,
	IN OUT EFI_UINTN *BufferSize,
	OUT VOID *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_DEBUGPORT_POLL)(
	IN EFI_DEBUGPORT_PROTOCOL *This
);

typedef struct _EFI_DEBUGPORT_PROTOCOL {
	EFI_DEBUGPORT_RESET Reset;
	EFI_DEBUGPORT_WRITE Write;
	EFI_DEBUGPORT_READ Read;
	EFI_DEBUGPORT_POLL Poll;
} EFI_DEBUGPORT_PROTOCOL;

////
// EFI Debug Support Table
///

#define EFI_DEBUG_IMAGE_INFO_TABLE_GUID {0x49152e77,0x1ada,0x4764, {0xb7,0xa2,0x7a,0xfe,0xfe,0xd9,0x5e,0x8b}}

// UpdateStatus bits
#define EFI_DEBUG_IMAGE_INFO_UPDATE_IN_PROGRESS 0x01
#define EFI_DEBUG_IMAGE_INFO_TABLE_MODIFIED 0x02

#define EFI_DEBUG_IMAGE_INFO_TYPE_NORMAL 0x01

typedef struct {
	EFI_UINT32 ImageInfoType;
	EFI_LOADED_IMAGE_PROTOCOL *LoadedImageProtocolInstance;
	EFI_HANDLE ImageHandle;
} EFI_DEBUG_IMAGE_INFO_NORMAL;

typedef union {
	EFI_UINT32 *ImageInfoType;
	EFI_DEBUG_IMAGE_INFO_NORMAL *NormalImage;
} EFI_DEBUG_IMAGE_INFO;

typedef struct {
	volatile EFI_UINT32 UpdateStatus;
	EFI_UINT32 TableSize;
	EFI_DEBUG_IMAGE_INFO *EfiDebugImageInfoTable;
} EFI_DEBUG_IMAGE_INFO_TABLE_HEADER;

#endif /* EFI_PROTOCOLS_DEBUGGER_H */