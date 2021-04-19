// filtername_iirXXXcpp11_hpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of BSF2 C++11 IIR filter implementation with the datatype of long long
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// BAND STOP FILTER
// BUTTERWORTH APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_c1 = 3500.0 Hz, f_s1 = 4000.0 Hz
// f_s2 = 4200.0 Hz, f_c2 = 5000.0 Hz
// Requirement checksum: f8f402568d4d312d6f53986e5ec6310f

// Created at unix time: 1618868728
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_CPP11_VALIDATOR_01_01_01
// Result checksum: 87701f27a637c7104351a004cfd72728

#ifndef _BSF2IIRI64CPP11_HPP_
#define _BSF2IIRI64CPP11_HPP_

#include "iircpp11.hpp"
#include <array>

class CBSF2IirI64Cpp11
{
private:
    unsigned char m_n = 0;
    std::array<CIirCpp11<long long>, 6> m_iirSegments_vec = {
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(-3162), static_cast<long long>(-38470), static_cast<long long>(48606), static_cast<long long>(9957), static_cast<long long>(48606))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(-18089), static_cast<long long>(-38787), static_cast<long long>(55519), static_cast<long long>(11373), static_cast<long long>(55519))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(9973), static_cast<long long>(-44905), static_cast<long long>(45567), static_cast<long long>(9335), static_cast<long long>(45567))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(-31974), static_cast<long long>(-45576), static_cast<long long>(64896), static_cast<long long>(13294), static_cast<long long>(64896))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(19006), static_cast<long long>(-57323), static_cast<long long>(47102), static_cast<long long>(9649), static_cast<long long>(47102))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(-42713), static_cast<long long>(-57713), static_cast<long long>(75271), static_cast<long long>(15420), static_cast<long long>(75271))),
    };
    static const unsigned char m_bitShifter = 16;
public:
    long long doFiltering(long long f_inputVal);
    void doRwdFiltering();
    void resetFilter();
};

#endif
