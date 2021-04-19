// filtername_iirXXXcpp11_hpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of LPF C++11 IIR filter implementation with the datatype of long long
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// LOW PASS FILTER
// CAUER APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_c = 4200.0 Hz, f_s = 5000.0 Hz
// Requirement checksum: 34a4df31e6369e557075b687be02ada1

// Created at unix time: 1618777995
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_CPP11_VALIDATOR_01_01_01
// Result checksum: ee83614716437233f66585d987a358e2

#ifndef _LPFIIRI64CPP11_HPP_
#define _LPFIIRI64CPP11_HPP_

#include "iircpp11.hpp"
#include <array>

class CLPFIirI64Cpp11
{
private:
    unsigned char m_n = 0;
    std::array<CIirCpp11<long long>, 3> m_iirSegments_vec = {
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(53121), static_cast<long long>(-19997), static_cast<long long>(8439), static_cast<long long>(15534), static_cast<long long>(8439))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(12640), static_cast<long long>(-43330), static_cast<long long>(30408), static_cast<long long>(35410), static_cast<long long>(30408))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(-10263), static_cast<long long>(-59610), static_cast<long long>(48262), static_cast<long long>(38886), static_cast<long long>(48262))),
    };
    static const unsigned char m_bitShifter = 16;
public:
    long long doFiltering(long long f_inputVal);
    void doRwdFiltering();
    void resetFilter();
};

#endif
