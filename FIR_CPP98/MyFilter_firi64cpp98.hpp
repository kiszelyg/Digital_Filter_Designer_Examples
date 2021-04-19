// filtername_firXXXcpp98_hpp.txt template file, version: 01_03_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of MyFilter C++98 FIR filter implementation with the datatype of long long
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
// Validator DLL version: FIR_CPP98_VALIDATOR_01_02_02
// Result checksum: 818c2239ddde0b19e5ec1fd51392b366

#ifndef _MYFILTERFIRI64CPP98_HPP_
#define _MYFILTERFIRI64CPP98_HPP_

#include "fircpp98.hpp"
#include <vector>

class CMyFilterFirI64Cpp98 : public CFirCpp98<long long>
{
protected:
    unsigned char m_bitShifter;
public:
    CMyFilterFirI64Cpp98();
    ~CMyFilterFirI64Cpp98();
    long long doFiltering(long long f_inputVal);
};

#endif
