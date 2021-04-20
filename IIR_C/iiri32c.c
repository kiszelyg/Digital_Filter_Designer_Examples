// iirXXXc_c.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of a general C IIR filter implementation with the datatype of long
// One instance of this file can handle any amount of particular filter instances with the given data type

#include <stdio.h> // printf
#include <string.h> // memset
#include "iiri32c.h"

long CIirI32C_initFilter(CIirI32C* f_iirI32CData_ptr, const CIirCoeffsI32* f_coeffs_ptr)
{
    f_iirI32CData_ptr->m_x = (long)0.0;
    f_iirI32CData_ptr->m_y = (long)0.0;
    if (0 == (long)memset(f_iirI32CData_ptr->m_t1, 0, (2 * sizeof(long))))
    {
        printf("FAILURE! Memory for the internal buffer cannot be set!\n");
        return RETURN_ERROR;
    }
    if (0 == (long)memset(f_iirI32CData_ptr->m_t2, 0, (2 * sizeof(long))))
    {
        printf("FAILURE! Memory for the internal buffer cannot be set!\n");
        return RETURN_ERROR;
    }
    f_iirI32CData_ptr->m_coeffs_ptr = f_coeffs_ptr;
    return RETURN_OK;
}

void CIirI32C_resetFilter(CIirI32C* f_iirI32CData_ptr)
{
    f_iirI32CData_ptr->m_x = (long)0.0;
    f_iirI32CData_ptr->m_y = (long)0.0;
    if (0 == (long)memset(f_iirI32CData_ptr->m_t1, 0, (2 * sizeof(long))))
    {
        printf("FAILURE! Memory for the internal buffer cannot be set!\n");
    }
    if (0 == (long)memset(f_iirI32CData_ptr->m_t2, 0, (2 * sizeof(long))))
    {
        printf("FAILURE! Memory for the internal buffer cannot be set!\n");
    }
}

long* CIirI32C_doFiltering(CIirI32C* f_iirI32CData_ptr, long f_inputVal, unsigned char f_n)
{
    f_iirI32CData_ptr->m_x = f_inputVal;
    f_iirI32CData_ptr->m_y = f_iirI32CData_ptr->m_coeffs_ptr->m_b0 * f_iirI32CData_ptr->m_x + f_iirI32CData_ptr->m_t1[(f_n + 1) & 1];
    return(&f_iirI32CData_ptr->m_y);
}

void CIirI32C_doRwdFiltering(CIirI32C* f_iirI32CData_ptr, unsigned char f_n)
{
    long l_xB1 = f_iirI32CData_ptr->m_coeffs_ptr->m_b1 * f_iirI32CData_ptr->m_x;
    long l_xB2 = f_iirI32CData_ptr->m_coeffs_ptr->m_b2 * f_iirI32CData_ptr->m_x;
    long l_yA1 = f_iirI32CData_ptr->m_coeffs_ptr->m_a1 * f_iirI32CData_ptr->m_y;
    long l_yA2 = f_iirI32CData_ptr->m_coeffs_ptr->m_a2 * f_iirI32CData_ptr->m_y;
    f_iirI32CData_ptr->m_t1[f_n] = l_xB1 + f_iirI32CData_ptr->m_t2[(f_n + 1) & 1] + l_yA1;
    f_iirI32CData_ptr->m_t2[f_n] = l_xB2 + l_yA2;
}

