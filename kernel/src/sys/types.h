#ifndef __TYPES_H
#define __TYPES_H

// Boolean types
typedef int bool;
#define true 1
#define false 0

// Define fixed-size integer types
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned long long uint64_t;
typedef signed long long int64_t;

// Define pointer-sized integer types
typedef uint32_t uintptr_t;
typedef int32_t intptr_t;

// Size types
typedef unsigned int size_t;

// Define integer types for maximum and minimum values
#define UINT8_MAX (0xFF)
#define INT8_MAX (0x7F)
#define INT8_MIN (-0x80)
#define UINT16_MAX (0xFFFF)
#define INT16_MAX (0x7FFF)
#define INT16_MIN (-0x8000)
#define UINT32_MAX (0xFFFFFFFF)
#define INT32_MAX (0x7FFFFFFF)
#define INT32_MIN (-0x80000000)
#define UINT64_MAX (0xFFFFFFFFFFFFFFFFULL)
#define INT64_MAX (0x7FFFFFFFFFFFFFFFULL)
#define INT64_MIN (-0x8000000000000000LL)

// Miscellaneous types
#define NULL ((void*)0)

#endif