// filtername_iirXXXcpp11_hpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of HPF C++11 IIR filter implementation with the datatype of long long
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// HIGH PASS FILTER
// CAUER APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_s = 500.0 Hz, f_c = 1200.0 Hz
// Requirement checksum: 968bd6d33e9645b50af67d3ca4e13e34

// Created at unix time: 1618777748
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_CPP11_VALIDATOR_01_01_01
// Result checksum: 4a9d7ddaa1b2690272186db0440bd753

#ifndef _HPFIIRI64CPP11_HPP_
#define _HPFIIRI64CPP11_HPP_

#include "iircpp11.hpp"
#include <array>

class CHPFIirI64Cpp11
{
private:
    unsigned char m_n = 0;
    std::array<CIirCpp11<long long>, 2> m_iirSegments_vec = {
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(63894), static_cast<long long>(-23845), static_cast<long long>(38378), static_cast<long long>(-76520), static_cast<long long>(38378))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(110103), static_cast<long long>(-57667), static_cast<long long>(58816), static_cast<long long>(-115674), static_cast<long long>(58816))),
    };
    static const unsigned char m_bitShifter = 16;
public:
    long long doFiltering(long long f_inputVal);
    void doRwdFiltering();
    void resetFilter();
};

#endif
