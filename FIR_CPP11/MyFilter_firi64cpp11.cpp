// filtername_firXXXcpp11_cpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter C++11 FIR filter implementation with the datatype of long long
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

#include "MyFilter_firi64cpp11.hpp"

CMyFilterFirI64Cpp11::CMyFilterFirI64Cpp11()
    : CFirCpp11<long long>()
{
    m_coeffs_vec.resize(37);
    m_coeffs_vec = {
        static_cast<long long>(317),
        static_cast<long long>(0),
        static_cast<long long>(0),
        static_cast<long long>(0),
        static_cast<long long>(-1021),
        static_cast<long long>(0),
        static_cast<long long>(1225),
        static_cast<long long>(0),
        static_cast<long long>(1000),
        static_cast<long long>(0),
        static_cast<long long>(-3896),
        static_cast<long long>(0),
        static_cast<long long>(2265),
        static_cast<long long>(0),
        static_cast<long long>(6872),
        static_cast<long long>(0),
        static_cast<long long>(-18938),
        static_cast<long long>(0),
        static_cast<long long>(24576),
        static_cast<long long>(0),
        static_cast<long long>(-18938),
        static_cast<long long>(0),
        static_cast<long long>(6872),
        static_cast<long long>(0),
        static_cast<long long>(2265),
        static_cast<long long>(0),
        static_cast<long long>(-3896),
        static_cast<long long>(0),
        static_cast<long long>(1000),
        static_cast<long long>(0),
        static_cast<long long>(1225),
        static_cast<long long>(0),
        static_cast<long long>(-1021),
        static_cast<long long>(0),
        static_cast<long long>(0),
        static_cast<long long>(0),
        static_cast<long long>(317),
        };
    m_inputBuffer_vec.clear();
    m_inputBuffer_vec.resize(37);
    std::fill(m_inputBuffer_vec.begin(), m_inputBuffer_vec.end(), static_cast<long long>(0.0));
}

CMyFilterFirI64Cpp11::~CMyFilterFirI64Cpp11()
{
    m_coeffs_vec.clear();
    m_inputBuffer_vec.clear();
}

long long CMyFilterFirI64Cpp11::doFiltering(long long f_inputVal)
{
    return(CFirCpp11<long long>::doFiltering(f_inputVal) >> m_bitShifter);
}

