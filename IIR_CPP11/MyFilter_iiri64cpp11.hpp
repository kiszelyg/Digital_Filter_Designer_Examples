// filtername_iirXXXcpp11_hpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of MyFilter C++11 IIR filter implementation with the datatype of long long
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
// Validator DLL version: IIR_CPP11_VALIDATOR_01_01_01
// Result checksum: 4ab6fabe94c9442e6becea03a89c63a7

#ifndef _MYFILTERIIRI64CPP11_HPP_
#define _MYFILTERIIRI64CPP11_HPP_

#include "iircpp11.hpp"
#include <array>

class CMyFilterIirI64Cpp11
{
private:
    unsigned char m_n = 0;
    std::array<CIirCpp11<long long>, 3> m_iirSegments_vec = {
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(103038), static_cast<long long>(-42600), static_cast<long long>(1274), static_cast<long long>(2549), static_cast<long long>(1274))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(93976), static_cast<long long>(-48960), static_cast<long long>(5130), static_cast<long long>(10260), static_cast<long long>(5130))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(88090), static_cast<long long>(-59338), static_cast<long long>(9196), static_cast<long long>(18392), static_cast<long long>(9196))),
    };
    static const unsigned char m_bitShifter = 16;
public:
    long long doFiltering(long long f_inputVal);
    void doRwdFiltering();
    void resetFilter();
};

#endif
