// filtername_iirXXXcu_hpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of MyFilter CUDA (R) IIR filter implementation with the datatype of long long
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
// Validator DLL version: IIR_CU_VALIDATOR_01_01_01
// Result checksum: 4ab6fabe94c9442e6becea03a89c63a7

#ifndef _MYFILTERIIRI64CU_HPP_
#define _MYFILTERIIRI64CU_HPP_

#include <cuda_runtime.h>
#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <string.h> // memset
#include "iircu.cuh"

class CMyFilterIirI64Cu : public CIirFilterCu<long long>
{
public:
    CMyFilterIirI64Cu();
    long initFilter();
};

#endif
