// firXXXc_h.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of a general C FIR filter implementation with the datatype of long
// One instance of this file can handle any amount of particular filter instances with the given data type

#ifndef _FIRI32C_H_
#define _FIRI32C_H_

#define RETURN_OK 0
#define RETURN_ERROR -1

typedef struct CFirI32CData CFirI32CData;

struct CFirI32CData
{
    unsigned char m_numOfStages;
    unsigned char m_bitShifter;
    long* m_coeffsStart_ptr;
    long* m_coeffsEnd_ptr;
    long* m_inputBuffer_ptr;
    long* m_inputBufferStart_ptr;
    long* m_inputBufferEnd_ptr;
};

extern void CFirI32C_resetFilter(CFirI32CData* f_firI32CData_ptr);
extern long CFirI32C_doFiltering(CFirI32CData* f_firI32CData_ptr, long f_inputVal);

#endif
