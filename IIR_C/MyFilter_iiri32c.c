// filtername_iirXXXc_c.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter C IIR filter implementation with the datatype of long
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

#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include "MyFilter_iiri32c.h"

long CMyFilterIirI32C_initFilter(CMyFilterIirI32C* self)
{
    long l_retVal = RETURN_ERROR;
    self->m_n = 0;
    self->m_numOfStages = 3;
    self->m_bitShifter = 11;
    self->m_iirI32C_ptr = (CIirI32C*)malloc((self->m_numOfStages * sizeof(CIirI32C)));
    self->m_coeffs_ptr = (CIirCoeffsI32*)malloc((self->m_numOfStages * sizeof(CIirCoeffsI32)));
    if (0 == self->m_coeffs_ptr)
    {
        printf("FAILURE! Allocating memory for the coefficients is not possible!\n");
        return RETURN_ERROR;
    }
    self->m_coeffs_ptr[0].m_a1 = 1556; self->m_coeffs_ptr[0].m_a2 = -343; self->m_coeffs_ptr[0].m_b0 = 1145; self->m_coeffs_ptr[0].m_b1 = -1658; self->m_coeffs_ptr[0].m_b2 = 1145;
    self->m_coeffs_ptr[1].m_a1 = 1525; self->m_coeffs_ptr[1].m_a2 = -698; self->m_coeffs_ptr[1].m_b0 = 1080; self->m_coeffs_ptr[1].m_b1 = -2111; self->m_coeffs_ptr[1].m_b2 = 1080;
    self->m_coeffs_ptr[2].m_a1 = 1647; self->m_coeffs_ptr[2].m_a2 = -1452; self->m_coeffs_ptr[2].m_b0 = 1397; self->m_coeffs_ptr[2].m_b1 = -2353; self->m_coeffs_ptr[2].m_b2 = 1397;
    CIirI32C* l_iirItr_ptr = self->m_iirI32C_ptr;
    CIirCoeffsI32* l_coeffsItr_ptr = self->m_coeffs_ptr;
    while (l_iirItr_ptr != (self->m_iirI32C_ptr + self->m_numOfStages) && l_coeffsItr_ptr != (self->m_coeffs_ptr + self->m_numOfStages))
    {
        l_retVal = CIirI32C_initFilter(l_iirItr_ptr, l_coeffsItr_ptr);
        if (RETURN_ERROR == l_retVal)
        {
            return(l_retVal);
        }
        l_iirItr_ptr++;
        l_coeffsItr_ptr++;
    }
    return(l_retVal);
}

void CMyFilterIirI32C_resetFilter(CMyFilterIirI32C* self)
{
    self->m_n = 0;
    CIirI32C* l_iirItr_ptr = self->m_iirI32C_ptr;
    while (l_iirItr_ptr != (self->m_iirI32C_ptr + self->m_numOfStages))
    {
        CIirI32C_resetFilter(l_iirItr_ptr);
        l_iirItr_ptr++;
    }
}

long CMyFilterIirI32C_doFiltering(CMyFilterIirI32C* self, long f_inputVal)
{
    long l_tempVal = f_inputVal;
    CIirI32C* l_iirItr_ptr = self->m_iirI32C_ptr;
    while (l_iirItr_ptr != (self->m_iirI32C_ptr + self->m_numOfStages))
    {
        l_tempVal = (*CIirI32C_doFiltering(l_iirItr_ptr, l_tempVal, self->m_n) >>= self->m_bitShifter);
        l_iirItr_ptr++;
    }
    return(l_tempVal);
}

// Function calculates the rewards calculations of the filter
// This function can be called in a parallel thread, started immediatelly after the doFiltering function
// Calculations must be done before the next call of doFiltering
void CMyFilterIirI32C_doRwdFiltering(CMyFilterIirI32C* self)
{
    CIirI32C* l_iirItr_ptr = self->m_iirI32C_ptr;
    while (l_iirItr_ptr != (self->m_iirI32C_ptr + self->m_numOfStages))
    {
        CIirI32C_doRwdFiltering(l_iirItr_ptr, self->m_n);
        l_iirItr_ptr++;
    }
    self->m_n++;
    self->m_n &= 1;
}

void CMyFilterIirI32C_destroyFilter(CMyFilterIirI32C* self)
{
    free(self->m_iirI32C_ptr);
    self->m_iirI32C_ptr = 0;
    free(self->m_coeffs_ptr);
    self->m_coeffs_ptr = 0;
}

