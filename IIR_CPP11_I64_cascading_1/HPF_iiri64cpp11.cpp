// filtername_iirXXXcpp11_cpp.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of HPF C++11 IIR filter implementation with the datatype of long long
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

#include "HPF_iiri64cpp11.hpp"

void CHPFIirI64Cpp11::resetFilter()
{
    m_n = 0;
    for (auto& l_iirSegment : m_iirSegments_vec)
    {
        l_iirSegment.resetFilter();
    }
}

// Function calculates the output value
long long CHPFIirI64Cpp11::doFiltering(long long f_inputVal)
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
void CHPFIirI64Cpp11::doRwdFiltering()
{
    for (auto& l_iirSegment : m_iirSegments_vec)
    {
        l_iirSegment.doRwdFiltering(m_n);
    }
    m_n++;
    m_n &= 1;
}

