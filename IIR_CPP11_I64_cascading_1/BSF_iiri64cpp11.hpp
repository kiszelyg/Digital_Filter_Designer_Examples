// filtername_iirXXXcpp11_hpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of BSF C++11 IIR filter implementation with the datatype of long long
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// BAND STOP FILTER
// CAUER APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_c1 = 1500.0 Hz, f_s1 = 2500.0 Hz
// f_s2 = 3500.0 Hz, f_c2 = 4000.0 Hz
// Requirement checksum: e5a0fc9cfc63d27a6f9be8920e437469

// Created at unix time: 1618777861
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_CPP11_VALIDATOR_01_01_01
// Result checksum: c0f70c0b07787d292224c1627b2da4bd

#ifndef _BSFIIRI64CPP11_HPP_
#define _BSFIIRI64CPP11_HPP_

#include "iircpp11.hpp"
#include <array>

class CBSFIirI64Cpp11
{
private:
    unsigned char m_n = 0;
    std::array<CIirCpp11<long long>, 6> m_iirSegments_vec = {
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(-40427), static_cast<long long>(-20058), static_cast<long long>(257547), static_cast<long long>(-389073), static_cast<long long>(257547))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(101244), static_cast<long long>(-42614), static_cast<long long>(4342), static_cast<long long>(-1777), static_cast<long long>(4342))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(-13198), static_cast<long long>(-50027), static_cast<long long>(226988), static_cast<long long>(-325214), static_cast<long long>(226988))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(105985), static_cast<long long>(-57180), static_cast<long long>(11694), static_cast<long long>(-6657), static_cast<long long>(11694))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(311), static_cast<long long>(-61944), static_cast<long long>(164865), static_cast<long long>(-202561), static_cast<long long>(164865))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(107202), static_cast<long long>(-63512), static_cast<long long>(19641), static_cast<long long>(-17436), static_cast<long long>(19641))),
    };
    static const unsigned char m_bitShifter = 16;
public:
    long long doFiltering(long long f_inputVal);
    void doRwdFiltering();
    void resetFilter();
};

#endif
