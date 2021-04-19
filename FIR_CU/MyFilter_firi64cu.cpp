// filtername_firXXXcu_cpp.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of MyFilter CUDA (R) FIR filter implementation with the datatype of long long
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
// Validator DLL version: FIR_CU_VALIDATOR_01_01_01
// Result checksum: 818c2239ddde0b19e5ec1fd51392b366

#include "MyFilter_firi64cu.hpp"

CMyFilterFirI64Cu::CMyFilterFirI64Cu()
    : CFirCu<long long>()
{
    m_numOfStages = 37;
    m_bitShifter = 16;
    unsigned short l_tempSize = 1;
    while (l_tempSize < m_numOfStages)
    {
        l_tempSize <<= 1;
    }
    m_resSize = l_tempSize;
}

CMyFilterFirI64Cu::~CMyFilterFirI64Cu()
{
}

long CMyFilterFirI64Cu::initFilter()
{
    long l_retVal = RETURN_OK;
    cudaError_t l_cudaRetVal = cudaSuccess;
    long long* l_tempCoeffs_vec = (long long*)malloc(sizeof(long long) * m_numOfStages);
    if (0 == l_tempCoeffs_vec)
    {
        printf("FAILURE! Allocating memory for the coefficients is not possible!\n");
        l_retVal = RETURN_ERROR;
    }
    else
    {
        l_tempCoeffs_vec[0] = static_cast<long long>(-158);
        l_tempCoeffs_vec[1] = static_cast<long long>(-202);
        l_tempCoeffs_vec[2] = static_cast<long long>(0);
        l_tempCoeffs_vec[3] = static_cast<long long>(358);
        l_tempCoeffs_vec[4] = static_cast<long long>(511);
        l_tempCoeffs_vec[5] = static_cast<long long>(136);
        l_tempCoeffs_vec[6] = static_cast<long long>(-613);
        l_tempCoeffs_vec[7] = static_cast<long long>(-1047);
        l_tempCoeffs_vec[8] = static_cast<long long>(-500);
        l_tempCoeffs_vec[9] = static_cast<long long>(886);
        l_tempCoeffs_vec[10] = static_cast<long long>(1948);
        l_tempCoeffs_vec[11] = static_cast<long long>(1327);
        l_tempCoeffs_vec[12] = static_cast<long long>(-1133);
        l_tempCoeffs_vec[13] = static_cast<long long>(-3662);
        l_tempCoeffs_vec[14] = static_cast<long long>(-3436);
        l_tempCoeffs_vec[15] = static_cast<long long>(1304);
        l_tempCoeffs_vec[16] = static_cast<long long>(9469);
        l_tempCoeffs_vec[17] = static_cast<long long>(17269);
        l_tempCoeffs_vec[18] = static_cast<long long>(20480);
        l_tempCoeffs_vec[19] = static_cast<long long>(17269);
        l_tempCoeffs_vec[20] = static_cast<long long>(9469);
        l_tempCoeffs_vec[21] = static_cast<long long>(1304);
        l_tempCoeffs_vec[22] = static_cast<long long>(-3436);
        l_tempCoeffs_vec[23] = static_cast<long long>(-3662);
        l_tempCoeffs_vec[24] = static_cast<long long>(-1133);
        l_tempCoeffs_vec[25] = static_cast<long long>(1327);
        l_tempCoeffs_vec[26] = static_cast<long long>(1948);
        l_tempCoeffs_vec[27] = static_cast<long long>(886);
        l_tempCoeffs_vec[28] = static_cast<long long>(-500);
        l_tempCoeffs_vec[29] = static_cast<long long>(-1047);
        l_tempCoeffs_vec[30] = static_cast<long long>(-613);
        l_tempCoeffs_vec[31] = static_cast<long long>(136);
        l_tempCoeffs_vec[32] = static_cast<long long>(511);
        l_tempCoeffs_vec[33] = static_cast<long long>(358);
        l_tempCoeffs_vec[34] = static_cast<long long>(0);
        l_tempCoeffs_vec[35] = static_cast<long long>(-202);
        l_tempCoeffs_vec[36] = static_cast<long long>(-158);
    }
    long long* l_tempBuffer_vec = (long long*)malloc(sizeof(long long) * m_numOfStages);
    if (0 == l_tempBuffer_vec)
    {
        printf("FAILURE! Allocating memory for the input buffer is not possible!\n");
        l_retVal = RETURN_ERROR;
    }
    else
    {
        if (0 == (long)memset(l_tempBuffer_vec, 0x00, sizeof(long long) * m_numOfStages))
        {
            printf("FAILURE! Setting memory for the input buffer is not possible!\n");
            l_retVal = RETURN_ERROR;
        }
    }
    long long* l_tempRes_vec = (long long*)malloc(sizeof(long long) * m_resSize);
    if (0 == l_tempRes_vec)
    {
        printf("FAILURE! Allocating memory for the result buffer is not possible!\n");
        l_retVal = RETURN_ERROR;
    }
    else
    {
        if (0 == (long)memset(l_tempRes_vec, 0x00, sizeof(long long) * m_resSize))
        {
            printf("FAILURE! Setting memory for the input buffer is not possible!\n");
            l_retVal = RETURN_ERROR;
        }
    }
    l_cudaRetVal = (cudaMalloc((void**)&m_coeffs_vec, (sizeof(long long) * m_numOfStages)));
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Allocating CUDA memory for the coefficients is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    else
    {
        l_cudaRetVal = (cudaMemcpy(m_coeffs_vec, l_tempCoeffs_vec, (sizeof(long long) * m_numOfStages), cudaMemcpyHostToDevice));
    }
    free(l_tempCoeffs_vec);
    l_tempCoeffs_vec = 0;
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Copying CUDA data for the coefficients is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    l_cudaRetVal = (cudaMalloc((void**)&m_inputBuffer_vec, (sizeof(long long) * m_numOfStages)));
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Allocating CUDA memory for the input buffer is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    else
    {
        l_cudaRetVal = (cudaMemcpy(m_inputBuffer_vec, l_tempBuffer_vec, (sizeof(long long) * m_numOfStages), cudaMemcpyHostToDevice));
    }
    free(l_tempBuffer_vec);
    l_tempBuffer_vec = 0;
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Copying CUDA data for the input buffer is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    l_cudaRetVal = (cudaMalloc((void**)&m_res_vec, (sizeof(long long) * m_resSize)));
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Allocating CUDA memory for the results is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    else
    {
        l_cudaRetVal = (cudaMemcpy(m_res_vec, l_tempRes_vec, (sizeof(long long) * m_resSize), cudaMemcpyHostToDevice));
    }
    free(l_tempRes_vec);
    l_tempRes_vec = 0;
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Copying CUDA data for the results is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    return(l_retVal);
}

long long CMyFilterFirI64Cu::doFiltering(long long f_inputVal)
{
    return(CFirCu<long long>::doFiltering(f_inputVal) >> m_bitShifter);
}

