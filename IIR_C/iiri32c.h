// iirXXXc_h.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of a general C IIR filter implementation with the datatype of long
// One instance of this file can handle any amount of particular filter instances with the given data type

#ifndef _IIRI32C_H_
#define _IIRI32C_H_

#define RETURN_OK 0
#define RETURN_ERROR -1

typedef struct CIirI32C CIirI32C;

typedef struct CIirCoeffsI32
{
    long m_a1;
    long m_a2;
    long m_b0;
    long m_b1;
    long m_b2;
} CIirCoeffsI32;

struct CIirI32C
{
    const CIirCoeffsI32* m_coeffs_ptr;
    long m_x;
    long m_y;
    long m_t1[2];
    long m_t2[2];
};

extern long CIirI32C_initFilter(CIirI32C* f_iirI32CData_ptr, const CIirCoeffsI32* l_coeffs_ptr);
extern void CIirI32C_resetFilter(CIirI32C* f_iirI32CData_ptr);
extern long* CIirI32C_doFiltering(CIirI32C* f_iirI32CData_ptr, long f_inputVal, unsigned char f_n);
extern void CIirI32C_doRwdFiltering(CIirI32C* f_iirI32CData_ptr, unsigned char f_n);

#endif

