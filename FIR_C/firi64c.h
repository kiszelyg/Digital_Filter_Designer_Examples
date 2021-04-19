// firXXXc_h.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of a general C FIR filter implementation with the datatype of long long

#ifndef _FIRI64C_H_
#define _FIRI64C_H_

#define RETURN_OK 0
#define RETURN_ERROR -1

typedef struct CFirI64CData CFirI64CData;

struct CFirI64CData
{
    unsigned char m_numOfStages;
    unsigned char m_bitShifter;
    long long* m_coeffsStart_ptr;
    long long* m_coeffsEnd_ptr;
    long long* m_inputBuffer_ptr;
    long long* m_inputBufferStart_ptr;
    long long* m_inputBufferEnd_ptr;
};

extern void CFirI64C_resetFilter(CFirI64CData* f_firI64CData_ptr);
extern long long CFirI64C_doFiltering(CFirI64CData* f_firI64CData_ptr, long long f_inputVal);

#endif
