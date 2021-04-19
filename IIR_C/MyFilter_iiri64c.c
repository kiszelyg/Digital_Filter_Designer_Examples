// filtername_iirXXXc_c.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter C IIR filter implementation with the datatype of long long
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

#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include "MyFilter_iiri64c.h"

long CMyFilterIirI64C_initFilter(CMyFilterIirI64C* self)
{
    long l_retVal = RETURN_ERROR;
    self->m_n = 0;
    self->m_numOfStages = 3;
    self->m_bitShifter = 16;
    self->m_iirI64C_ptr = (CIirI64C*)malloc((self->m_numOfStages * sizeof(CIirI64C)));
    self->m_coeffs_ptr = (CIirCoeffsI64*)malloc((self->m_numOfStages * sizeof(CIirCoeffsI64)));
    if (0 == self->m_coeffs_ptr)
    {
        printf("FAILURE! Allocating memory for the coefficients is not possible!\n");
        return RETURN_ERROR;
    }
    self->m_coeffs_ptr[0].m_a1 = 103038; self->m_coeffs_ptr[0].m_a2 = -42600; self->m_coeffs_ptr[0].m_b0 = 1274; self->m_coeffs_ptr[0].m_b1 = 2549; self->m_coeffs_ptr[0].m_b2 = 1274;
    self->m_coeffs_ptr[1].m_a1 = 93976; self->m_coeffs_ptr[1].m_a2 = -48960; self->m_coeffs_ptr[1].m_b0 = 5130; self->m_coeffs_ptr[1].m_b1 = 10260; self->m_coeffs_ptr[1].m_b2 = 5130;
    self->m_coeffs_ptr[2].m_a1 = 88090; self->m_coeffs_ptr[2].m_a2 = -59338; self->m_coeffs_ptr[2].m_b0 = 9196; self->m_coeffs_ptr[2].m_b1 = 18392; self->m_coeffs_ptr[2].m_b2 = 9196;
    CIirI64C* l_iirItr_ptr = self->m_iirI64C_ptr;
    CIirCoeffsI64* l_coeffsItr_ptr = self->m_coeffs_ptr;
    while (l_iirItr_ptr != (self->m_iirI64C_ptr + self->m_numOfStages) && l_coeffsItr_ptr != (self->m_coeffs_ptr + self->m_numOfStages))
    {
        l_retVal = CIirI64C_initFilter(l_iirItr_ptr, l_coeffsItr_ptr);
        if (RETURN_ERROR == l_retVal)
        {
            return(l_retVal);
        }
        l_iirItr_ptr++;
        l_coeffsItr_ptr++;
    }
    return(l_retVal);
}

void CMyFilterIirI64C_resetFilter(CMyFilterIirI64C* self)
{
    self->m_n = 0;
    CIirI64C* l_iirItr_ptr = self->m_iirI64C_ptr;
    while (l_iirItr_ptr != (self->m_iirI64C_ptr + self->m_numOfStages))
    {
        CIirI64C_resetFilter(l_iirItr_ptr);
        l_iirItr_ptr++;
    }
}

long long CMyFilterIirI64C_doFiltering(CMyFilterIirI64C* self, long long f_inputVal)
{
    long long l_tempVal = f_inputVal;
    CIirI64C* l_iirItr_ptr = self->m_iirI64C_ptr;
    while (l_iirItr_ptr != (self->m_iirI64C_ptr + self->m_numOfStages))
    {
        l_tempVal = (*CIirI64C_doFiltering(l_iirItr_ptr, l_tempVal, self->m_n) >>= self->m_bitShifter);
        l_iirItr_ptr++;
    }
    return(l_tempVal);
}

// Function calculates the rewards calculations of the filter
// This function can be called in a parallel thread, started immediatelly after the doFiltering function
// Calculations must be done before the next call of doFiltering
void CMyFilterIirI64C_doRwdFiltering(CMyFilterIirI64C* self)
{
    CIirI64C* l_iirItr_ptr = self->m_iirI64C_ptr;
    while (l_iirItr_ptr != (self->m_iirI64C_ptr + self->m_numOfStages))
    {
        CIirI64C_doRwdFiltering(l_iirItr_ptr, self->m_n);
        l_iirItr_ptr++;
    }
    self->m_n++;
    self->m_n &= 1;
}

void CMyFilterIirI64C_destroyFilter(CMyFilterIirI64C* self)
{
    free(self->m_iirI64C_ptr);
    self->m_iirI64C_ptr = 0;
    free(self->m_coeffs_ptr);
    self->m_coeffs_ptr = 0;
}

