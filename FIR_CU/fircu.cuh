// fircu_cuh.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of a general CUDA (R) FIR filter implementation

#ifndef _FIRCU_CUH_
#define _FIRCU_CUH_

#include <cuda_runtime.h>
#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // memset

#define RETURN_OK 0
#define RETURN_ERROR -1

template <typename T>
class CFirCu
{
private:
    unsigned short m_ptrOffset;
protected:
    unsigned short m_numOfStages;
    unsigned short m_resSize;
    unsigned char m_bitShifter;
    T* m_coeffs_vec;
    T* m_inputBuffer_vec;
    T* m_res_vec;
public:
    CFirCu(); // must be public
    T doFiltering(T f_inputVal); // must be public
    void resetFilter(); // must be public
    long destroyFilter(); // must be public
    virtual ~CFirCu();
};

#endif

