// filtername_firXXXc_c.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter C FIR filter implementation with the datatype of long
// File implements the following filter:
// FINITE IMPULSE RESPONSE
// HIGH PASS FILTER
// A_s = -40.0 dB
// f_sa = 16000.0 Hz
// f_s = 2000.0 Hz, f_c = 3000.0 Hz
// Requirement checksum: cad78480e6a9e9b969be6d7f680075a4

// Created at unix time: 1618932310
// Designer DLL version: FIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: FIR_C_VALIDATOR_01_01_01
// Result checksum: 86db80a3dd82b31100281e8cafa3a6e2

#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // memset
#include "MyFilter_firi32c.h"

long CMyFilterFirI32C_initFilter(CFirI32CData* self)
{
    self->m_numOfStages = 37;
    self->m_bitShifter = 11;
    self->m_coeffsStart_ptr = 0;
    self->m_coeffsEnd_ptr = 0;
    self->m_inputBuffer_ptr = 0;
    self->m_inputBufferStart_ptr = 0;
    self->m_inputBufferEnd_ptr = 0;
    self->m_coeffsStart_ptr = (long*)malloc(self->m_numOfStages * sizeof(long));
    if (0 == self->m_coeffsStart_ptr)
    {
        printf("FAILURE! Allocating memory for the coefficients is not possible!\n");
        return RETURN_ERROR;
    }
    self->m_coeffsStart_ptr[0] = 5;
    self->m_coeffsStart_ptr[1] = 6;
    self->m_coeffsStart_ptr[2] = 0;
    self->m_coeffsStart_ptr[3] = -11;
    self->m_coeffsStart_ptr[4] = -16;
    self->m_coeffsStart_ptr[5] = -4;
    self->m_coeffsStart_ptr[6] = 19;
    self->m_coeffsStart_ptr[7] = 33;
    self->m_coeffsStart_ptr[8] = 16;
    self->m_coeffsStart_ptr[9] = -28;
    self->m_coeffsStart_ptr[10] = -61;
    self->m_coeffsStart_ptr[11] = -41;
    self->m_coeffsStart_ptr[12] = 35;
    self->m_coeffsStart_ptr[13] = 114;
    self->m_coeffsStart_ptr[14] = 107;
    self->m_coeffsStart_ptr[15] = -41;
    self->m_coeffsStart_ptr[16] = -296;
    self->m_coeffsStart_ptr[17] = -540;
    self->m_coeffsStart_ptr[18] = 1408;
    self->m_coeffsStart_ptr[19] = -540;
    self->m_coeffsStart_ptr[20] = -296;
    self->m_coeffsStart_ptr[21] = -41;
    self->m_coeffsStart_ptr[22] = 107;
    self->m_coeffsStart_ptr[23] = 114;
    self->m_coeffsStart_ptr[24] = 35;
    self->m_coeffsStart_ptr[25] = -41;
    self->m_coeffsStart_ptr[26] = -61;
    self->m_coeffsStart_ptr[27] = -28;
    self->m_coeffsStart_ptr[28] = 16;
    self->m_coeffsStart_ptr[29] = 33;
    self->m_coeffsStart_ptr[30] = 19;
    self->m_coeffsStart_ptr[31] = -4;
    self->m_coeffsStart_ptr[32] = -16;
    self->m_coeffsStart_ptr[33] = -11;
    self->m_coeffsStart_ptr[34] = 0;
    self->m_coeffsStart_ptr[35] = 6;
    self->m_coeffsStart_ptr[36] = 5;
    self->m_coeffsEnd_ptr = self->m_coeffsStart_ptr + self->m_numOfStages;
    self->m_inputBufferStart_ptr = (long*)malloc(self->m_numOfStages * sizeof(long));
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
    if (0 == (long)memset(self->m_inputBufferStart_ptr, 0, self->m_numOfStages * sizeof(long)))
    {
        printf("FAILURE! Memory for the input buffer cannot be set!\n");
        return RETURN_ERROR;
    }
    {
        // do nothing
    }
    return RETURN_OK;
}

void CMyFilterFirI32C_destroyFilter(CFirI32CData* self)
{
    free(self->m_coeffsStart_ptr);
    self->m_coeffsStart_ptr = 0;
    self->m_coeffsEnd_ptr = 0;
    free(self->m_inputBufferStart_ptr);
    self->m_inputBuffer_ptr = 0;
    self->m_inputBufferStart_ptr = 0;
    self->m_inputBufferEnd_ptr = 0;
}
