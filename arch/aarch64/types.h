#ifndef _SEL_ARCH_TYPES_H
#define _SEL_ARCH_TYPES_H

#include "cpubind.h"

//
// Calling convention specifier
//
#ifndef EFIAPI
# define EFIAPI
#endif

//
// Basic data types
//
typedef char				INT8;
typedef unsigned char		UINT8;
typedef short				INT16;
typedef unsigned short		UINT16;
typedef int					INT32;
typedef unsigned int		UINT32;
typedef long				INT64;
typedef unsigned long		UINT64;

//
// Additional data types
//
typedef char				CHAR8;
typedef short				CHAR16;

typedef INT64				INTN;
typedef UINT64				UINTN;

typedef void				VOID;

typedef unsigned char		BOOLEAN;

#endif /* _SEL_ARCH_TYPES_H */
