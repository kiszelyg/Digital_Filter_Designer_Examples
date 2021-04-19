// filtername_firXXXc_c.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter C FIR filter implementation with the datatype of long long
// File implements the following filter:
// FINITE IMPULSE RESPONSE
// LOW PASS FILTER
// A_s = -40.0 dB
// f_sa = 16000.0 Hz
// f_c = 2000.0 Hz, f_s = 3000.0 Hz
// Requirement checksum: 1d61d275710be224cc82236ae85b28ab

// Created at unix time: 1618431298
// Designer DLL version: FIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: FIR_C_VALIDATOR_01_01_01
// Result checksum: 818c2239ddde0b19e5ec1fd51392b366

#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // memset
#include "MyFilter_firi64c.h"

long CMyFilterFirI64C_initFilter(CFirI64CData* self)
{
    self->m_numOfStages = 37;
    self->m_bitShifter = 16;
    self->m_coeffsStart_ptr = 0;
    self->m_coeffsEnd_ptr = 0;
    self->m_inputBuffer_ptr = 0;
    self->m_inputBufferStart_ptr = 0;
    self->m_inputBufferEnd_ptr = 0;
    self->m_coeffsStart_ptr = (long long*)malloc(self->m_numOfStages * sizeof(long long));
    if (0 == self->m_coeffsStart_ptr)
    {
        printf("FAILURE! Allocating memory for the coefficients is not possible!\n");
        return RETURN_ERROR;
    }
    self->m_coeffsStart_ptr[0] = -158;
    self->m_coeffsStart_ptr[1] = -202;
    self->m_coeffsStart_ptr[2] = 0;
    self->m_coeffsStart_ptr[3] = 358;
    self->m_coeffsStart_ptr[4] = 511;
    self->m_coeffsStart_ptr[5] = 136;
    self->m_coeffsStart_ptr[6] = -613;
    self->m_coeffsStart_ptr[7] = -1047;
    self->m_coeffsStart_ptr[8] = -500;
    self->m_coeffsStart_ptr[9] = 886;
    self->m_coeffsStart_ptr[10] = 1948;
    self->m_coeffsStart_ptr[11] = 1327;
    self->m_coeffsStart_ptr[12] = -1133;
    self->m_coeffsStart_ptr[13] = -3662;
    self->m_coeffsStart_ptr[14] = -3436;
    self->m_coeffsStart_ptr[15] = 1304;
    self->m_coeffsStart_ptr[16] = 9469;
    self->m_coeffsStart_ptr[17] = 17269;
    self->m_coeffsStart_ptr[18] = 20480;
    self->m_coeffsStart_ptr[19] = 17269;
    self->m_coeffsStart_ptr[20] = 9469;
    self->m_coeffsStart_ptr[21] = 1304;
    self->m_coeffsStart_ptr[22] = -3436;
    self->m_coeffsStart_ptr[23] = -3662;
    self->m_coeffsStart_ptr[24] = -1133;
    self->m_coeffsStart_ptr[25] = 1327;
    self->m_coeffsStart_ptr[26] = 1948;
    self->m_coeffsStart_ptr[27] = 886;
    self->m_coeffsStart_ptr[28] = -500;
    self->m_coeffsStart_ptr[29] = -1047;
    self->m_coeffsStart_ptr[30] = -613;
    self->m_coeffsStart_ptr[31] = 136;
    self->m_coeffsStart_ptr[32] = 511;
    self->m_coeffsStart_ptr[33] = 358;
    self->m_coeffsStart_ptr[34] = 0;
    self->m_coeffsStart_ptr[35] = -202;
    self->m_coeffsStart_ptr[36] = -158;
    self->m_coeffsEnd_ptr = self->m_coeffsStart_ptr + self->m_numOfStages;
    self->m_inputBufferStart_ptr = (long long*)malloc(self->m_numOfStages * sizeof(long long));
    if (0 == self->m_inputBufferStart_ptr)
    {
        printf("FAILURE! Allocating memory for the input buffer is not possible!\n");
        return RETURN_ERROR;
    }
    else
    {
        self->m_inputBuffer_ptr = self->m_inputBufferStart_ptr;
    }
    self->m_inputBufferEnd_ptr = self->m_inputBufferStart_ptr + self->m_numOfStages;
    if (0 == (long)memset(self->m_inputBufferStart_ptr, 0, self->m_numOfStages * sizeof(long long)))
    {
        printf("FAILURE! Memory for the input buffer cannot be set!\n");
        return RETURN_ERROR;
    }
    {
        // do nothing
    }
    return RETURN_OK;
}

void CMyFilterFirI64C_destroyFilter(CFirI64CData* self)
{
    free(self->m_coeffsStart_ptr);
    self->m_coeffsStart_ptr = 0;
    self->m_coeffsEnd_ptr = 0;
    free(self->m_inputBufferStart_ptr);
    self->m_inputBuffer_ptr = 0;
    self->m_inputBufferStart_ptr = 0;
    self->m_inputBufferEnd_ptr = 0;
}
