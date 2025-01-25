#ifndef Falcon_h
#define Falcon_h

#define D_ENABLE 22
#define D_ON 0
#define D_OFF 1

#define D1_STEP 10
#define D1_DIR 21
#define D1_DIAG 16
#define D1_SERIAL uart1
#define D1_ADDRESS 0b00
#define D1_RS 0.11f
#define D1_CURRENT 700

#define D2_STEP 11
#define D2_DIR 20
#define D2_DIAG 17
#define D2_SERIAL uart1
#define D2_ADDRESS 0b01
#define D2_RS 0.11f
#define D2_CURRENT 700

#define D3_STEP 12
#define D3_DIR 19
#define D3_DIAG 18
#define D3_SERIAL uart1
#define D3_ADDRESS 0b11
#define D3_RS 0.11f
#define D3_CURRENT 700

#define D4_STEP 8
#define D4_DIR 9
#define D4_DIAG 2
#define D4_SERIAL uart0
#define D4_ADDRESS 0b00
#define D4_RS 0.11f
#define D4_CURRENT 700

#define D5_STEP 7
#define D5_DIR 26
#define D5_DIAG 3
#define D5_SERIAL uart0
#define D5_ADDRESS 0b01
#define D5_RS 0.11f
#define D5_CURRENT 700

#define D6_STEP 6
#define D6_DIR 27
#define D6_DIAG 28
#define D6_SERIAL uart0
#define D6_ADDRESS 0b11
#define D6_RS 0.11f
#define D6_CURRENT 700

// #define F1 15
// #define F2

#define B1 14
#define B2 13

#endif