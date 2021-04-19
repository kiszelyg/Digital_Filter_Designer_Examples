// iircu_cuh.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of a general CUDA (R) IIR filter implementation

#ifndef _IIRCU_CUH_
#define _IIRCU_CUH_

#include <cuda_runtime.h>
#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // memset

#define RETURN_OK 0
#define RETURN_ERROR -1

template <typename T>
class CIirCoeffs
{
public:
    T m_a1;
    T m_a2;
    T m_b0;
    T m_b1;
    T m_b2;

    CIirCoeffs()
    {
        m_a1 = static_cast<T>(0.0);
        m_a2 = static_cast<T>(0.0);
        m_b0 = static_cast<T>(0.0);
        m_b1 = static_cast<T>(0.0);
        m_b2 = static_cast<T>(0.0);
    }

    CIirCoeffs(T f_a1, T f_a2, T f_b0, T f_b1, T f_b2)
    {
        m_a1 = f_a1;
        m_a2 = f_a2;
        m_b0 = f_b0;
        m_b1 = f_b1;
        m_b2 = f_b2;
    }
};

template <typename T>
class CIirCu
{
public:
    CIirCoeffs<T> m_coeffs;
    T m_x;
    T m_y;
    T m_t1_vec[2];
    T m_t2_vec[2];

    CIirCu();
    CIirCu(const CIirCoeffs<T>& f_coeffs);
};

template <typename T>
class CIirFilterCu
{
protected:
    unsigned short m_numOfStages;
    unsigned char m_bitShifter;
    unsigned char m_n = 0;

    CIirCu<T>* m_iirSegments_vec;
    T* m_outputVal_ptr;
public:
    CIirFilterCu(); // must be public
    virtual ~CIirFilterCu();
    T doFiltering(T f_inputVal); // must be public
    void doRwdFiltering(); // must be public
    void resetFilter(); // must be public
    void destroyFilter(); // must be public
};
#endif
