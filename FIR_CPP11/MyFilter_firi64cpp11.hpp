// filtername_firXXXcpp11_hpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of MyFilter C++11 FIR filter implementation with the datatype of long long
// File implements the following filter:
// FINITE IMPULSE RESPONSE
// BAND PASS FILTER
// A_s = -40.0 dB
// f_sa = 16000.0 Hz
// f_s1 = 2000.0 Hz, f_c1 = 3000.0 Hz
// f_c2 = 5000.0 Hz, f_s2 = 6000.0 Hz
// Requirement checksum: 830bddb5c5d97ac081753ffba9040f4c

// Created at unix time: 1618932697
// Designer DLL version: FIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: FIR_CPP11_VALIDATOR_01_01_01
// Result checksum: 0748d9d5b5132fc6c2e63f37f570035e

#ifndef _MYFILTERFIRI64CPP11_HPP_
#define _MYFILTERFIRI64CPP11_HPP_

#include "fircpp11.hpp"
#include <vector>

class CMyFilterFirI64Cpp11 : public CFirCpp11<long long>
{
protected:
    static const unsigned char m_bitShifter = 16;
public:
    CMyFilterFirI64Cpp11();
    ~CMyFilterFirI64Cpp11();
    long long doFiltering(long long f_inputVal);
};

#endif
