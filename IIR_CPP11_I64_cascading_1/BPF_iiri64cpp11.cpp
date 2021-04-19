// filtername_iirXXXcpp11_cpp.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of BPF C++11 IIR filter implementation with the datatype of long long
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

#include "BPF_iiri64cpp11.hpp"

void CBPFIirI64Cpp11::resetFilter()
{
    m_n = 0;
    for (auto& l_iirSegment : m_iirSegments_vec)
    {
        l_iirSegment.resetFilter();
    }
}

// Function calculates the output value
long long CBPFIirI64Cpp11::doFiltering(long long f_inputVal)
{
    long long l_retVal = f_inputVal;
    for (auto& l_iirSegment : m_iirSegments_vec)
    {
        l_retVal = (l_iirSegment.doFiltering(l_retVal, m_n) >>= m_bitShifter);
    }
    return(l_retVal);
}

// Function calculates the rewards calculations of the filter
// This function can be called in a parallel thread, started immediatelly after the doFiltering function
// Calculations must be done before the next call of doFiltering
void CBPFIirI64Cpp11::doRwdFiltering()
{
    for (auto& l_iirSegment : m_iirSegments_vec)
    {
        l_iirSegment.doRwdFiltering(m_n);
    }
    m_n++;
    m_n &= 1;
}

