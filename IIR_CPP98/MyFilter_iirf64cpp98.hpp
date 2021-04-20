// filtername_iirXXXcpp98_hpp.txt template file, version: 01_03_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of MyFilter C++98 IIR filter implementation with the datatype of double
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// BAND STOP FILTER
// BUTTERWORTH APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_c1 = 2000.0 Hz, f_s1 = 3000.0 Hz
// f_s2 = 5000.0 Hz, f_c2 = 6000.0 Hz
// Requirement checksum: 5eacdd72b012142b4c087c8c19967a44

// Created at unix time: 1618934024
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_CPP98_VALIDATOR_01_04_01
// Result checksum: b506a3ec8d7471ea932cb25005ecf5e9

#ifndef _MYFILTERIIRF64CPP98_HPP_
#define _MYFILTERIIRF64CPP98_HPP_

#include "iircpp98.hpp"
#include <vector>

class CMyFilterIirF64Cpp98
{
private:
    unsigned char m_n;
    std::vector<CIirCpp98<double>> m_iirSegments_vec;
public:
    CMyFilterIirF64Cpp98();
    ~CMyFilterIirF64Cpp98();
    double doFiltering(double f_inputVal);
    void doRwdFiltering();
    void resetFilter();
};

#endif
