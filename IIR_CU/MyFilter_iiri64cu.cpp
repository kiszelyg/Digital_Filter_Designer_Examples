// filtername_iirXXXcu_cpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter CUDA (R) IIR filter implementation with the datatype of long long
// File implements the following filter:
// INFINITE IMPULSE RESPONSE
// LOW PASS FILTER
// CHEBYSHEV APPROXIMATION
// A_s = -40.0 dB, d_r = 0.1
// f_sa = 16000.0 Hz
// f_c = 2000.0 Hz, f_s = 3000.0 Hz
// Requirement checksum: 4e7c287ac658902f6f571036d29ec519

// Created at unix time: 1618433235
// Designer DLL version: IIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: IIR_CU_VALIDATOR_01_01_01
// Result checksum: 4ab6fabe94c9442e6becea03a89c63a7

#include "MyFilter_iiri64cu.hpp"

CMyFilterIirI64Cu::CMyFilterIirI64Cu()
    : CIirFilterCu<long long>()
{
    m_numOfStages = 3;
    m_bitShifter = 16;
}
long CMyFilterIirI64Cu::initFilter()
{
    long l_retVal = RETURN_OK;
    cudaError_t l_cudaRetVal = cudaSuccess;
    CIirCoeffs<long long>* l_tempCoeffs_vec = (CIirCoeffs<long long>*)malloc(sizeof(CIirCoeffs<long long>) * m_numOfStages);
    l_tempCoeffs_vec[0] = CIirCoeffs<long long>(static_cast<long long>(103038), static_cast<long long>(-42600), static_cast<long long>(1274), static_cast<long long>(2549), static_cast<long long>(1274));
    l_tempCoeffs_vec[1] = CIirCoeffs<long long>(static_cast<long long>(93976), static_cast<long long>(-48960), static_cast<long long>(5130), static_cast<long long>(10260), static_cast<long long>(5130));
    l_tempCoeffs_vec[2] = CIirCoeffs<long long>(static_cast<long long>(88090), static_cast<long long>(-59338), static_cast<long long>(9196), static_cast<long long>(18392), static_cast<long long>(9196));
    CIirCu<long long>* l_tempIirSegments_vec = (CIirCu<long long>*)malloc(sizeof(CIirCu<long long>) * m_numOfStages);
    for (unsigned short l_idx = 0; l_idx < m_numOfStages; l_idx++)
    {
        l_tempIirSegments_vec[l_idx] = CIirCu<long long>(l_tempCoeffs_vec[l_idx]);
    }
    l_cudaRetVal = (cudaMalloc((void**)&m_iirSegments_vec, (sizeof(CIirCu<long long>) * m_numOfStages)));
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Allocating CUDA memory for the segments is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    else
    {
        l_cudaRetVal = (cudaMemcpy(m_iirSegments_vec, l_tempIirSegments_vec, (sizeof(CIirCu<long long>) * m_numOfStages), cudaMemcpyHostToDevice));
    }
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Copying CUDA memory for the segments is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    l_cudaRetVal = (cudaMalloc((void**)&m_outputVal_ptr, sizeof(long long)));
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Allocating CUDA memory for the results is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    free(l_tempIirSegments_vec);
    l_tempIirSegments_vec = 0;
    free(l_tempCoeffs_vec);
    l_tempCoeffs_vec = 0;
    return(l_retVal);
}
