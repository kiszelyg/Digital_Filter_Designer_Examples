// filtername_firXXXcpp98_cpp.txt template file, version: 01_03_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter C++98 FIR filter implementation with the datatype of long long
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

#include "MyFilter_firi64cpp98.hpp"

CMyFilterFirI64Cpp98::CMyFilterFirI64Cpp98()
    : CFirCpp98<long long>()
{
    m_coeffs_vec.clear();
    m_coeffs_vec.resize(37);
    m_coeffs_vec[0] = static_cast<long long>(-158);
    m_coeffs_vec[1] = static_cast<long long>(-202);
    m_coeffs_vec[2] = static_cast<long long>(0);
    m_coeffs_vec[3] = static_cast<long long>(358);
    m_coeffs_vec[4] = static_cast<long long>(511);
    m_coeffs_vec[5] = static_cast<long long>(136);
    m_coeffs_vec[6] = static_cast<long long>(-613);
    m_coeffs_vec[7] = static_cast<long long>(-1047);
    m_coeffs_vec[8] = static_cast<long long>(-500);
    m_coeffs_vec[9] = static_cast<long long>(886);
    m_coeffs_vec[10] = static_cast<long long>(1948);
    m_coeffs_vec[11] = static_cast<long long>(1327);
    m_coeffs_vec[12] = static_cast<long long>(-1133);
    m_coeffs_vec[13] = static_cast<long long>(-3662);
    m_coeffs_vec[14] = static_cast<long long>(-3436);
    m_coeffs_vec[15] = static_cast<long long>(1304);
    m_coeffs_vec[16] = static_cast<long long>(9469);
    m_coeffs_vec[17] = static_cast<long long>(17269);
    m_coeffs_vec[18] = static_cast<long long>(20480);
    m_coeffs_vec[19] = static_cast<long long>(17269);
    m_coeffs_vec[20] = static_cast<long long>(9469);
    m_coeffs_vec[21] = static_cast<long long>(1304);
    m_coeffs_vec[22] = static_cast<long long>(-3436);
    m_coeffs_vec[23] = static_cast<long long>(-3662);
    m_coeffs_vec[24] = static_cast<long long>(-1133);
    m_coeffs_vec[25] = static_cast<long long>(1327);
    m_coeffs_vec[26] = static_cast<long long>(1948);
    m_coeffs_vec[27] = static_cast<long long>(886);
    m_coeffs_vec[28] = static_cast<long long>(-500);
    m_coeffs_vec[29] = static_cast<long long>(-1047);
    m_coeffs_vec[30] = static_cast<long long>(-613);
    m_coeffs_vec[31] = static_cast<long long>(136);
    m_coeffs_vec[32] = static_cast<long long>(511);
    m_coeffs_vec[33] = static_cast<long long>(358);
    m_coeffs_vec[34] = static_cast<long long>(0);
    m_coeffs_vec[35] = static_cast<long long>(-202);
    m_coeffs_vec[36] = static_cast<long long>(-158);
    m_bitShifter = 16;
    m_inputBuffer_vec.clear();
    m_inputBuffer_vec.resize(37);
    std::fill(m_inputBuffer_vec.begin(), m_inputBuffer_vec.end(), static_cast<long long>(0.0));
}

CMyFilterFirI64Cpp98::~CMyFilterFirI64Cpp98()
{
    m_coeffs_vec.clear();
    m_inputBuffer_vec.clear();
}

long long CMyFilterFirI64Cpp98::doFiltering(long long f_inputVal)
{
    return(CFirCpp98<long long>::doFiltering(f_inputVal) >> m_bitShifter);
}

