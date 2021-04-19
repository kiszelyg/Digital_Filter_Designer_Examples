// iirXXXc_c.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of a general C IIR filter implementation with the datatype of long long

#include <stdio.h> // printf
#include <string.h> // memset
#include "iiri64c.h"

long CIirI64C_initFilter(CIirI64C* f_iirI64CData_ptr, const CIirCoeffsI64* f_coeffs_ptr)
{
    f_iirI64CData_ptr->m_x = (long long)0.0;
    f_iirI64CData_ptr->m_y = (long long)0.0;
    if (0 == (long)memset(f_iirI64CData_ptr->m_t1, 0, (2 * sizeof(long long))))
    {
        printf("FAILURE! Memory for the internal buffer cannot be set!\n");
        return RETURN_ERROR;
    }
    if (0 == (long)memset(f_iirI64CData_ptr->m_t2, 0, (2 * sizeof(long long))))
    {
        printf("FAILURE! Memory for the internal buffer cannot be set!\n");
        return RETURN_ERROR;
    }
    f_iirI64CData_ptr->m_coeffs_ptr = f_coeffs_ptr;
    return RETURN_OK;
}

void CIirI64C_resetFilter(CIirI64C* f_iirI64CData_ptr)
{
    f_iirI64CData_ptr->m_x = (long long)0.0;
    f_iirI64CData_ptr->m_y = (long long)0.0;
    if (0 == (long)memset(f_iirI64CData_ptr->m_t1, 0, (2 * sizeof(long long))))
    {
        printf("FAILURE! Memory for the internal buffer cannot be set!\n");
    }
    if (0 == (long)memset(f_iirI64CData_ptr->m_t2, 0, (2 * sizeof(long long))))
    {
        printf("FAILURE! Memory for the internal buffer cannot be set!\n");
    }
}

long long* CIirI64C_doFiltering(CIirI64C* f_iirI64CData_ptr, long long f_inputVal, unsigned char f_n)
{
    f_iirI64CData_ptr->m_x = f_inputVal;
    f_iirI64CData_ptr->m_y = f_iirI64CData_ptr->m_coeffs_ptr->m_b0 * f_iirI64CData_ptr->m_x + f_iirI64CData_ptr->m_t1[(f_n + 1) & 1];
    return(&f_iirI64CData_ptr->m_y);
}

void CIirI64C_doRwdFiltering(CIirI64C* f_iirI64CData_ptr, unsigned char f_n)
{
    long long l_xB1 = f_iirI64CData_ptr->m_coeffs_ptr->m_b1 * f_iirI64CData_ptr->m_x;
    long long l_xB2 = f_iirI64CData_ptr->m_coeffs_ptr->m_b2 * f_iirI64CData_ptr->m_x;
    long long l_yA1 = f_iirI64CData_ptr->m_coeffs_ptr->m_a1 * f_iirI64CData_ptr->m_y;
    long long l_yA2 = f_iirI64CData_ptr->m_coeffs_ptr->m_a2 * f_iirI64CData_ptr->m_y;
    f_iirI64CData_ptr->m_t1[f_n] = l_xB1 + f_iirI64CData_ptr->m_t2[(f_n + 1) & 1] + l_yA1;
    f_iirI64CData_ptr->m_t2[f_n] = l_xB2 + l_yA2;
}

