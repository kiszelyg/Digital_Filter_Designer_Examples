// filtername_iirXXXcpp98_cpp.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter C++98 IIR filter implementation with the datatype of double
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

#include "MyFilter_iirf64cpp98.hpp"

CMyFilterIirF64Cpp98::CMyFilterIirF64Cpp98()
{
    m_n = 0;
    m_iirSegments_vec.clear();
    m_iirSegments_vec.resize(8);
    m_iirSegments_vec[0] = CIirCpp98<double>(CIirCoeffs<double>(static_cast<double>(-0.3540643291939086), static_cast<double>(-0.108400954730431), static_cast<double>(0.7312326419621699), static_cast<double>(-0.0000000000000001), static_cast<double>(0.7312326419621699)));
    m_iirSegments_vec[1] = CIirCpp98<double>(CIirCoeffs<double>(static_cast<double>(0.3540643291939091), static_cast<double>(-0.1084009547304312), static_cast<double>(0.3771683127682611), static_cast<double>(-0.0000000000000001), static_cast<double>(0.3771683127682611)));
    m_iirSegments_vec[2] = CIirCpp98<double>(CIirCoeffs<double>(static_cast<double>(-0.7172719652780568), static_cast<double>(-0.3066788367277973), static_cast<double>(1.0119754010029272), static_cast<double>(-0.0000000000000002), static_cast<double>(1.0119754010029272)));
    m_iirSegments_vec[3] = CIirCpp98<double>(CIirCoeffs<double>(static_cast<double>(0.7172719652780571), static_cast<double>(-0.3066788367277975), static_cast<double>(0.2947034357248702), static_cast<double>(-0.0000000000000001), static_cast<double>(0.2947034357248702)));
    m_iirSegments_vec[4] = CIirCpp98<double>(CIirCoeffs<double>(static_cast<double>(-0.9778382754918262), static_cast<double>(-0.5362687079810849), static_cast<double>(1.2570534917364558), static_cast<double>(-0.0000000000000002), static_cast<double>(1.2570534917364558)));
    m_iirSegments_vec[5] = CIirCpp98<double>(CIirCoeffs<double>(static_cast<double>(0.9778382754918267), static_cast<double>(-0.5362687079810853), static_cast<double>(0.2792152162446294), static_cast<double>(-0.0), static_cast<double>(0.2792152162446294)));
    m_iirSegments_vec[6] = CIirCpp98<double>(CIirCoeffs<double>(static_cast<double>(-1.2212164989940051), static_cast<double>(-0.8213601238149946), static_cast<double>(1.5212883114045002), static_cast<double>(-0.0000000000000003), static_cast<double>(1.5212883114045002)));
    m_iirSegments_vec[7] = CIirCpp98<double>(CIirCoeffs<double>(static_cast<double>(1.221216498994006), static_cast<double>(-0.8213601238149957), static_cast<double>(0.3000718124104949), static_cast<double>(-0.0000000000000001), static_cast<double>(0.3000718124104949)));
}

CMyFilterIirF64Cpp98::~CMyFilterIirF64Cpp98()
{
    m_iirSegments_vec.clear();
}

void CMyFilterIirF64Cpp98::resetFilter()
{
    m_n = 0;
    for (std::vector<CIirCpp98<double>>::iterator l_iirSegments_itr = m_iirSegments_vec.begin(); l_iirSegments_itr != m_iirSegments_vec.end(); l_iirSegments_itr++)
    {
        l_iirSegments_itr->resetFilter();
    }
}

// Function calculates the output value
double CMyFilterIirF64Cpp98::doFiltering(double f_inputVal)
{
    double l_retVal = f_inputVal;
    for (std::vector<CIirCpp98<double>>::iterator l_iirSegments_itr = m_iirSegments_vec.begin(); l_iirSegments_itr != m_iirSegments_vec.end(); l_iirSegments_itr++)
    {
        l_retVal = (l_iirSegments_itr->doFiltering(l_retVal, m_n));
    }
    return(l_retVal);
}

// Function calculates the rewards calculations of the filter
// This function can be called in a parallel thread, started immediatelly after the doFiltering function
// Calculations must be done before the next call of doFiltering
void CMyFilterIirF64Cpp98::doRwdFiltering()
{
    for (std::vector<CIirCpp98<double>>::iterator l_iirSegments_itr = m_iirSegments_vec.begin(); l_iirSegments_itr != m_iirSegments_vec.end(); l_iirSegments_itr++)
    {
        l_iirSegments_itr->doRwdFiltering(m_n);
    }
    m_n++;
    m_n &= 1;
}

