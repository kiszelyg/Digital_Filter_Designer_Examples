// fircu_cu.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of a general CUDA (R) FIR filter implementation

#include "fircu.cuh"

template<typename T>
__global__ void sumVector(T* f_data_ptr)
{
    const unsigned short l_threadId = threadIdx.x;
    unsigned short l_idxStep = 1;
    unsigned short l_threadNr = blockDim.x;
    while (0 < l_threadNr)
    {
        if (l_threadId < (l_threadNr))
        {
            f_data_ptr[(2 * l_threadId * l_idxStep)] += f_data_ptr[((2 * l_threadId + 1) * l_idxStep)];
        }
        l_idxStep <<= 1;
        l_threadNr >>= 1;
        __syncthreads();
    }
}

template<typename T>
__global__ void mulVectors(unsigned short f_offset, const T* f_coeff_ptr, const T* f_buffer_ptr, T* f_res_ptr)
{
    const unsigned short l_threadId = threadIdx.x;
    const unsigned short l_idx = (f_offset - l_threadId) < 0 ? (f_offset - l_threadId + blockDim.x) : (f_offset - l_threadId);
    f_res_ptr[l_threadId] = f_coeff_ptr[l_threadId] * f_buffer_ptr[l_idx];
}

template<typename T>
__global__ void resetBuffer(T* f_buffer_ptr)
{
    const unsigned short l_idx = threadIdx.x;
    f_buffer_ptr[l_idx] = static_cast<T>(0.0);
}

template <typename T>
CFirCu<T>::CFirCu()
{
    m_ptrOffset = 0;
}

template <typename T>
CFirCu<T>::~CFirCu()
{
    if (m_coeffs_vec != 0)
    {
        cudaFree(m_coeffs_vec);
        m_coeffs_vec = 0;
    }
    if (m_inputBuffer_vec != 0)
    {
        cudaFree(m_inputBuffer_vec);
        m_inputBuffer_vec = 0;
    }
    if (m_res_vec != 0)
    {
        cudaFree(m_res_vec);
        m_res_vec = 0;
    }
}

template <typename T>
T CFirCu<T>::doFiltering(T f_inputVal)
{
    T l_outputVal = 0;
    dim3 l_mul_grid(1, 1, 1);
    dim3 l_mul_thr(m_numOfStages, 1, 1);
    cudaMemcpy(&m_inputBuffer_vec[m_ptrOffset], &f_inputVal, sizeof(T), cudaMemcpyHostToDevice);
    mulVectors<T> << < l_mul_grid, l_mul_thr >> > (m_ptrOffset, m_coeffs_vec, m_inputBuffer_vec, m_res_vec);
    dim3 l_sum_grid(1, 1, 1);
    dim3 l_sum_thr(m_resSize >> 1, 1, 1);
    sumVector<T> << < l_sum_grid, l_sum_thr >> > (m_res_vec);
    cudaMemcpy(&l_outputVal, m_res_vec, sizeof(T), cudaMemcpyDeviceToHost);
    m_ptrOffset = (m_ptrOffset < (m_numOfStages - 1)) ? ++m_ptrOffset : 0;
    return l_outputVal;
}

template <typename T>
void CFirCu<T>::resetFilter()
{
    m_ptrOffset = 0;
    dim3 l_resetBuffer_grid(1, 1, 1);
    dim3 l_resetBuffer_thr(m_numOfStages, 1, 1);
    resetBuffer<T> << < l_resetBuffer_grid, l_resetBuffer_thr >> > (m_inputBuffer_vec);
}

template <typename T>
long CFirCu<T>::destroyFilter()
{
    long l_retVal = RETURN_OK;
    cudaError_t l_cudaRetVal = cudaSuccess;
    l_cudaRetVal = (cudaFree(m_coeffs_vec));
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Releasing CUDA memory for the results is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    m_coeffs_vec = 0;
    l_cudaRetVal = (cudaFree(m_inputBuffer_vec));
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Releasing CUDA memory for the coefficients is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    m_inputBuffer_vec = 0;
    l_cudaRetVal = (cudaFree(m_res_vec));
    if (cudaSuccess != l_cudaRetVal)
    {
        printf("FAILURE! Releasing CUDA memory for the input buffer is not possible! Error: %d\n", l_cudaRetVal);
        l_retVal = RETURN_ERROR;
    }
    m_res_vec = 0;
    return(l_retVal);
}

// Do NOT call this function, only to avoid the linker error
void TemporaryFunctionDouble()
{
    CFirCu<double> l_tempObj;
    l_tempObj.doFiltering(0.0);
    l_tempObj.resetFilter();
    l_tempObj.destroyFilter();
}

// Do NOT call this function, only to avoid the linker error
void TemporaryFunctionFloat()
{
    CFirCu<float> l_tempObj;
    l_tempObj.doFiltering(0.0);
    l_tempObj.resetFilter();
    l_tempObj.destroyFilter();
}

// Do NOT call this function, only to avoid the linker error
void TemporaryFunctionLongLong()
{
    CFirCu<long long> l_tempObj;
    l_tempObj.doFiltering(0);
    l_tempObj.resetFilter();
    l_tempObj.destroyFilter();
}

// Do NOT call this function, only to avoid the linker error
void TemporaryFunctionLong()
{
    CFirCu<long> l_tempObj;
    l_tempObj.doFiltering(0);
    l_tempObj.resetFilter();
    l_tempObj.destroyFilter();
}

// Do NOT call this function, only to avoid the linker error
void TemporaryFunctionShort()
{
    CFirCu<short> l_tempObj;
    l_tempObj.doFiltering(0);
    l_tempObj.resetFilter();
    l_tempObj.destroyFilter();
}

