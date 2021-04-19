// filtername_firXXXcpp11_cpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter C++11 FIR filter implementation with the datatype of long long
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
// Validator DLL version: FIR_CPP11_VALIDATOR_01_01_01
// Result checksum: 818c2239ddde0b19e5ec1fd51392b366

#include "MyFilter_firi64cpp11.hpp"

CMyFilterFirI64Cpp11::CMyFilterFirI64Cpp11()
    : CFirCpp11<long long>()
{
    m_coeffs_vec.resize(37);
    m_coeffs_vec = {
        static_cast<long long>(-158),
        static_cast<long long>(-202),
        static_cast<long long>(0),
        static_cast<long long>(358),
        static_cast<long long>(511),
        static_cast<long long>(136),
        static_cast<long long>(-613),
        static_cast<long long>(-1047),
        static_cast<long long>(-500),
        static_cast<long long>(886),
        static_cast<long long>(1948),
        static_cast<long long>(1327),
        static_cast<long long>(-1133),
        static_cast<long long>(-3662),
        static_cast<long long>(-3436),
        static_cast<long long>(1304),
        static_cast<long long>(9469),
        static_cast<long long>(17269),
        static_cast<long long>(20480),
        static_cast<long long>(17269),
        static_cast<long long>(9469),
        static_cast<long long>(1304),
        static_cast<long long>(-3436),
        static_cast<long long>(-3662),
        static_cast<long long>(-1133),
        static_cast<long long>(1327),
        static_cast<long long>(1948),
        static_cast<long long>(886),
        static_cast<long long>(-500),
        static_cast<long long>(-1047),
        static_cast<long long>(-613),
        static_cast<long long>(136),
        static_cast<long long>(511),
        static_cast<long long>(358),
        static_cast<long long>(0),
        static_cast<long long>(-202),
        static_cast<long long>(-158),
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

