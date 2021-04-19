// iirXXXc_h.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of a general C IIR filter implementation with the datatype of long long

#ifndef _IIRI64C_H_
#define _IIRI64C_H_

#define RETURN_OK 0
#define RETURN_ERROR -1

typedef struct CIirI64C CIirI64C;

typedef struct CIirCoeffsI64
{
    long long m_a1;
    long long m_a2;
    long long m_b0;
    long long m_b1;
    long long m_b2;
} CIirCoeffsI64;

struct CIirI64C
{
    const CIirCoeffsI64* m_coeffs_ptr;
    long long m_x;
    long long m_y;
    long long m_t1[2];
    long long m_t2[2];
};

extern long CIirI64C_initFilter(CIirI64C* f_iirI64CData_ptr, const CIirCoeffsI64* l_coeffs_ptr);
extern void CIirI64C_resetFilter(CIirI64C* f_iirI64CData_ptr);
extern long long* CIirI64C_doFiltering(CIirI64C* f_iirI64CData_ptr, long long f_inputVal, unsigned char f_n);
extern void CIirI64C_doRwdFiltering(CIirI64C* f_iirI64CData_ptr, unsigned char f_n);

#endif

