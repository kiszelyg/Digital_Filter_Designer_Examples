// filtername_iirXXXcpp11_hpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of BPF C++11 IIR filter implementation with the datatype of long long
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// BAND PASS FILTER
// CAUER APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_s1 = 500.0 Hz, f_c1 = 1200.0 Hz
// f_c2 = 4200.0 Hz, f_s2 = 5000.0 Hz
// Requirement checksum: 0c8b1d17088d446f1ebb3943043add41

// Created at unix time: 1618869383
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_CPP11_VALIDATOR_01_01_01
// Result checksum: b9b762d2f20424fe640d2e9882ec1148

#ifndef _BPFIIRI64CPP11_HPP_
#define _BPFIIRI64CPP11_HPP_

#include "iircpp11.hpp"
#include <array>

class CBPFIirI64Cpp11
{
private:
    unsigned char m_n = 0;
    std::array<CIirCpp11<long long>, 6> m_iirSegments_vec = {
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(42333), static_cast<long long>(-42427), static_cast<long long>(10284), static_cast<long long>(18716), static_cast<long long>(10284))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(82869), static_cast<long long>(-47611), static_cast<long long>(7335), static_cast<long long>(8294), static_cast<long long>(7335))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(7054), static_cast<long long>(-51317), static_cast<long long>(95240), static_cast<long long>(-189272), static_cast<long long>(95240))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(105909), static_cast<long long>(-57825), static_cast<long long>(13554), static_cast<long long>(10862), static_cast<long long>(13554))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(-10163), static_cast<long long>(-61219), static_cast<long long>(138747), static_cast<long long>(-267290), static_cast<long long>(138747))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(115051), static_cast<long long>(-63537), static_cast<long long>(53586), static_cast<long long>(-101160), static_cast<long long>(53586))),
    };
    static const unsigned char m_bitShifter = 16;
public:
    long long doFiltering(long long f_inputVal);
    void doRwdFiltering();
    void resetFilter();
};

#endif
