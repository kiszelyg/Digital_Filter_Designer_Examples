// filtername_iirXXXc_h.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of MyFilter C IIR filter implementation with the datatype of long
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// HIGH PASS FILTER
// INVERSE CHEBYSHEV APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_s = 2000.0 Hz, f_c = 3000.0 Hz
// Requirement checksum: 017c4e51c947bcc050191cb7b85cdc78

// Created at unix time: 1618933399
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_C_VALIDATOR_01_02_01
// Result checksum: dfac01d082d65f49b25cabf52300df9e

#ifndef _MYFILTERIIRI32C_H_
#define _MYFILTERIIRI32C_H_

#include "iiri32c.h"

typedef struct CMyFilterIirI32C CMyFilterIirI32C;

struct CMyFilterIirI32C
{
    unsigned char m_n;
    unsigned short m_numOfStages;
    CIirCoeffsI32* m_coeffs_ptr;
    unsigned char m_bitShifter;
    CIirI32C* m_iirI32C_ptr;
};

extern long CMyFilterIirI32C_initFilter(CMyFilterIirI32C* self);
extern void CMyFilterIirI32C_resetFilter(CMyFilterIirI32C* self);
extern long CMyFilterIirI32C_doFiltering(CMyFilterIirI32C* self, long f_inputVal);
extern void CMyFilterIirI32C_doRwdFiltering(CMyFilterIirI32C* self);
extern void CMyFilterIirI32C_destroyFilter(CMyFilterIirI32C* self);

#endif

