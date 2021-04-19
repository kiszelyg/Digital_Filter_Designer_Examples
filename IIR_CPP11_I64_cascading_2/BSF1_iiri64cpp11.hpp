// filtername_iirXXXcpp11_hpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of BSF1 C++11 IIR filter implementation with the datatype of long long
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// BAND STOP FILTER
// BUTTERWORTH APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_c1 = 500.0 Hz, f_s1 = 1200.0 Hz
// f_s2 = 1500.0 Hz, f_c2 = 2500.0 Hz
// Requirement checksum: 69ef44493da109fbe9700a0fa54f2779

// Created at unix time: 1618868643
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_CPP11_VALIDATOR_01_01_01
// Result checksum: 1d0854dbf25d47ec0c2befad8b5146bb

#ifndef _BSF1IIRI64CPP11_HPP_
#define _BSF1IIRI64CPP11_HPP_

#include "iircpp11.hpp"
#include <array>

class CBSF1IirI64Cpp11
{
private:
    unsigned char m_n = 0;
    std::array<CIirCpp11<long long>, 6> m_iirSegments_vec = {
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(73643), static_cast<long long>(-25000), static_cast<long long>(84445), static_cast<long long>(-151998), static_cast<long long>(84445))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(65755), static_cast<long long>(-30879), static_cast<long long>(153261), static_cast<long long>(-275862), static_cast<long long>(153261))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(99674), static_cast<long long>(-39656), static_cast<long long>(27584), static_cast<long long>(-49650), static_cast<long long>(27584))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(71410), static_cast<long long>(-50221), static_cast<long long>(221685), static_cast<long long>(-399022), static_cast<long long>(221685))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(113922), static_cast<long long>(-51775), static_cast<long long>(16945), static_cast<long long>(-30500), static_cast<long long>(16945))),
        CIirCpp11<long long>(CIirCoeffs<long long>(static_cast<long long>(123599), static_cast<long long>(-60989), static_cast<long long>(14625), static_cast<long long>(-26324), static_cast<long long>(14625))),
    };
    static const unsigned char m_bitShifter = 16;
public:
    long long doFiltering(long long f_inputVal);
    void doRwdFiltering();
    void resetFilter();
};

#endif
