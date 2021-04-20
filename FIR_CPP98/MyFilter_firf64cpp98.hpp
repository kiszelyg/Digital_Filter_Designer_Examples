// filtername_firXXXcpp98_hpp.txt template file, version: 01_03_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of MyFilter C++98 FIR filter implementation with the datatype of double
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

#ifndef _MYFILTERFIRF64CPP98_HPP_
#define _MYFILTERFIRF64CPP98_HPP_

#include "fircpp98.hpp"
#include <vector>

class CMyFilterFirF64Cpp98 : public CFirCpp98<double>
{
public:
    CMyFilterFirF64Cpp98();
    ~CMyFilterFirF64Cpp98();
    double doFiltering(double f_inputVal);
};

#endif
