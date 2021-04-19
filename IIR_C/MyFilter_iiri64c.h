// filtername_iirXXXc_h.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of MyFilter C IIR filter implementation with the datatype of long long
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// LOW PASS FILTER
// CHEBYSHEV APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_c = 2000.0 Hz, f_s = 3000.0 Hz
// Requirement checksum: 4e7c287ac658902f6f571036d29ec519

// Created at unix time: 1618433235
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_C_VALIDATOR_01_02_01
// Result checksum: 4ab6fabe94c9442e6becea03a89c63a7

#ifndef _MYFILTERIIRI64C_H_
#define _MYFILTERIIRI64C_H_

#include "iiri64c.h"

typedef struct CMyFilterIirI64C CMyFilterIirI64C;

struct CMyFilterIirI64C
{
    unsigned char m_n;
    unsigned short m_numOfStages;
    CIirCoeffsI64* m_coeffs_ptr;
    unsigned char m_bitShifter;
    CIirI64C* m_iirI64C_ptr;
};

extern long CMyFilterIirI64C_initFilter(CMyFilterIirI64C* self);
extern void CMyFilterIirI64C_resetFilter(CMyFilterIirI64C* self);
extern long long CMyFilterIirI64C_doFiltering(CMyFilterIirI64C* self, long long f_inputVal);
extern void CMyFilterIirI64C_doRwdFiltering(CMyFilterIirI64C* self);
extern void CMyFilterIirI64C_destroyFilter(CMyFilterIirI64C* self);

#endif

