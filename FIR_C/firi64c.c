// firXXXc_c.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of a general C FIR filter implementation with the datatype of long long

#include <stdio.h> // printf
#include <string.h> // memset
#include "firi64c.h"

void CFirI64C_resetFilter(CFirI64CData* f_firI64CData_ptr){
    if (0 == f_firI64CData_ptr->m_inputBuffer_ptr)
    {
        printf("FAILURE! The input buffer pointer is null pointer and must be initialized first!\n");
    }
    else
    {
        f_firI64CData_ptr->m_inputBuffer_ptr = f_firI64CData_ptr->m_inputBufferStart_ptr;
    }
    if (0 == (long)memset(f_firI64CData_ptr->m_inputBufferStart_ptr, 0, f_firI64CData_ptr->m_numOfStages * sizeof(long long)))
    {
        printf("FAILURE! Memory for the input buffer cannot be set!\n");
    }
}

long long CFirI64C_doFiltering(CFirI64CData* f_firI64CData_ptr, long long f_inputVal)
{
    long long l_outputVal = (long long)0;
    long long* l_coeff_ptr = f_firI64CData_ptr->m_coeffsStart_ptr;

    *f_firI64CData_ptr->m_inputBuffer_ptr = f_inputVal;

    while (f_firI64CData_ptr->m_inputBuffer_ptr >= f_firI64CData_ptr->m_inputBufferStart_ptr)
    {
        l_outputVal += *l_coeff_ptr * *f_firI64CData_ptr->m_inputBuffer_ptr;
        ++l_coeff_ptr;
        --f_firI64CData_ptr->m_inputBuffer_ptr;
    }
    f_firI64CData_ptr->m_inputBuffer_ptr = f_firI64CData_ptr->m_inputBufferEnd_ptr - 1;
    while (l_coeff_ptr < f_firI64CData_ptr->m_coeffsEnd_ptr)
    {
        l_outputVal += *l_coeff_ptr * *f_firI64CData_ptr->m_inputBuffer_ptr;
        ++l_coeff_ptr;
        --f_firI64CData_ptr->m_inputBuffer_ptr;
    }
    f_firI64CData_ptr->m_inputBuffer_ptr++;
    if (f_firI64CData_ptr->m_inputBuffer_ptr >= f_firI64CData_ptr->m_inputBufferEnd_ptr)
    {
        f_firI64CData_ptr->m_inputBuffer_ptr = f_firI64CData_ptr->m_inputBufferStart_ptr;
    }
    return (l_outputVal >> f_firI64CData_ptr->m_bitShifter);
}
