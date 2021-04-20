// filtername_firXXXcpp98_cpp.txt template file, version: 01_03_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter C++98 FIR filter implementation with the datatype of double
// File implements the following filter:
// FINITE IMPULSE RESPONSE
// BAND STOP FILTER
// A_s = -40.0 dB
// f_sa = 16000.0 Hz
// f_c1 = 2000.0 Hz, f_s1 = 3000.0 Hz
// f_s2 = 5000.0 Hz, f_c2 = 6000.0 Hz
// Requirement checksum: 862afff435901eda117a4fba00f24ab3

// Created at unix time: 1618932594
// Designer DLL version: FIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: FIR_CPP98_VALIDATOR_01_02_02
// Result checksum: b8f7406c9b540ae16fb8a1f81eac8d24

#include "MyFilter_firf64cpp98.hpp"

CMyFilterFirF64Cpp98::CMyFilterFirF64Cpp98()
    : CFirCpp98<double>()
{
    m_coeffs_vec.clear();
    m_coeffs_vec.resize(39);
    m_coeffs_vec[0] = static_cast<double>(-0.0);
    m_coeffs_vec[1] = static_cast<double>(-0.0063720105233532);
    m_coeffs_vec[2] = static_cast<double>(0.0);
    m_coeffs_vec[3] = static_cast<double>(-0.0);
    m_coeffs_vec[4] = static_cast<double>(0.0);
    m_coeffs_vec[5] = static_cast<double>(0.0175303789436683);
    m_coeffs_vec[6] = static_cast<double>(-0.0000000000000001);
    m_coeffs_vec[7] = static_cast<double>(-0.020226320081906);
    m_coeffs_vec[8] = static_cast<double>(0.0);
    m_coeffs_vec[9] = static_cast<double>(-0.0160632120024572);
    m_coeffs_vec[10] = static_cast<double>(0.0000000000000001);
    m_coeffs_vec[11] = static_cast<double>(0.0613153737391039);
    m_coeffs_vec[12] = static_cast<double>(-0.0000000000000001);
    m_coeffs_vec[13] = static_cast<double>(-0.0351489296628958);
    m_coeffs_vec[14] = static_cast<double>(-0.0);
    m_coeffs_vec[15] = static_cast<double>(-0.105625115892992);
    m_coeffs_vec[16] = static_cast<double>(0.0000000000000001);
    m_coeffs_vec[17] = static_cast<double>(0.2894848018366299);
    m_coeffs_vec[18] = static_cast<double>(-0.0000000000000001);
    m_coeffs_vec[19] = static_cast<double>(0.6250000000000001);
    m_coeffs_vec[20] = static_cast<double>(-0.0000000000000001);
    m_coeffs_vec[21] = static_cast<double>(0.2894848018366299);
    m_coeffs_vec[22] = static_cast<double>(0.0000000000000001);
    m_coeffs_vec[23] = static_cast<double>(-0.105625115892992);
    m_coeffs_vec[24] = static_cast<double>(-0.0);
    m_coeffs_vec[25] = static_cast<double>(-0.0351489296628958);
    m_coeffs_vec[26] = static_cast<double>(-0.0000000000000001);
    m_coeffs_vec[27] = static_cast<double>(0.0613153737391039);
    m_coeffs_vec[28] = static_cast<double>(0.0000000000000001);
    m_coeffs_vec[29] = static_cast<double>(-0.0160632120024572);
    m_coeffs_vec[30] = static_cast<double>(0.0);
    m_coeffs_vec[31] = static_cast<double>(-0.020226320081906);
    m_coeffs_vec[32] = static_cast<double>(-0.0000000000000001);
    m_coeffs_vec[33] = static_cast<double>(0.0175303789436683);
    m_coeffs_vec[34] = static_cast<double>(0.0);
    m_coeffs_vec[35] = static_cast<double>(-0.0);
    m_coeffs_vec[36] = static_cast<double>(0.0);
    m_coeffs_vec[37] = static_cast<double>(-0.0063720105233532);
    m_coeffs_vec[38] = static_cast<double>(-0.0);
    m_inputBuffer_vec.clear();
    m_inputBuffer_vec.resize(39);
    std::fill(m_inputBuffer_vec.begin(), m_inputBuffer_vec.end(), static_cast<double>(0.0));
}

CMyFilterFirF64Cpp98::~CMyFilterFirF64Cpp98()
{
    m_coeffs_vec.clear();
    m_inputBuffer_vec.clear();
}

double CMyFilterFirF64Cpp98::doFiltering(double f_inputVal)
{
    return(CFirCpp98<double>::doFiltering(f_inputVal));
}

