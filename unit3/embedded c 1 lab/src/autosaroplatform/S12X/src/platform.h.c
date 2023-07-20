/*
 ============================================================================
 Name        : h.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//GENERAL
#define CPU_TYPE_8
#define CPU_TYPE_16
#define CPU_TYPE_32
#define CPU_TYPE_64
#define MB_FIRST
#define LSB_FIRST
#define HIGH_BYTE_FIRST
#define LOW_BYTE_FIRST

#define CPU_TYPE //CPU_TYPE_16
#define CPU_BIT_ORDER //LSB_FIRST
#define CPU_BYTE_ORDER // HIGH_BYTE_FIRST
//-------------------------------------------

//TYPES

typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8_least;
typedef unsigned char uint8_least;
typedef signed short sint16_least;
typedef unsigned short uint16_least;
typedef signed long sint32_least;
typedef unsigned long uint32_least;
typedef float float32;
typedef double float64;
