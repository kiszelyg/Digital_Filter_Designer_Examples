// iircu_cu.txt template file, version: 01_01_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Code file of a general CUDA (R) IIR filter implementation

#include "iircu.cuh"

template<typename T>
__global__ void fwdFiltering(CIirCu<T>* f_segment_ptr, unsigned short m_numOfStages, unsigned char f_bitShifter, T f_inputVal, unsigned char f_n, T* f_output_ptr)
{
    T f_tempVal = f_inputVal;
    for (unsigned short l_idx = 0; l_idx < m_numOfStages; l_idx++)
    {
        f_segment_ptr[l_idx].m_x = f_tempVal;
        if (0 == f_bitShifter)
        {
            f_segment_ptr[l_idx].m_y = (f_segment_ptr[l_idx].m_coeffs.m_b0 * f_segment_ptr[l_idx].m_x + f_segment_ptr[l_idx].m_t1_vec[(f_n + 1) & 1]);
        }
        else
        {
            f_segment_ptr[l_idx].m_y = ((long long)(f_segment_ptr[l_idx].m_coeffs.m_b0 * f_segment_ptr[l_idx].m_x + f_segment_ptr[l_idx].m_t1_vec[(f_n + 1) & 1]) >> f_bitShifter);
        }
        f_tempVal = f_segment_ptr[l_idx].m_y;
    }
    *f_output_ptr = f_tempVal;
}

template<typename T>
__global__ void rwdFiltering(CIirCu<T>* f_segment_ptr, unsigned char f_n)
{
    const unsigned short l_idx = threadIdx.x;
    T l_xB1 = f_segment_ptr[l_idx].m_coeffs.m_b1 * f_segment_ptr[l_idx].m_x;
    T l_xB2 = f_segment_ptr[l_idx].m_coeffs.m_b2 * f_segment_ptr[l_idx].m_x;
    T l_yA1 = f_segment_ptr[l_idx].m_coeffs.m_a1 * f_segment_ptr[l_idx].m_y;
    T l_yA2 = f_segment_ptr[l_idx].m_coeffs.m_a2 * f_segment_ptr[l_idx].m_y;
    f_segment_ptr[l_idx].m_t1_vec[f_n & 1] = l_xB1 + f_segment_ptr[l_idx].m_t2_vec[(f_n + 1) & 1] + l_yA1;
    f_segment_ptr[l_idx].m_t2_vec[f_n & 1] = l_xB2 + l_yA2;
}

template<typename T>
__global__ void resetSegment(CIirCu<T>* f_segment_ptr)
{
    const unsigned short l_idx = threadIdx.x;
    f_segment_ptr[l_idx].m_x = static_cast<T>(0.0);
    f_segment_ptr[l_idx].m_y = static_cast<T>(0.0);
    f_segment_ptr[l_idx].m_t1_vec[0] = static_cast<T>(0.0);
    f_segment_ptr[l_idx].m_t1_vec[1] = static_cast<T>(0.0);
    f_segment_ptr[l_idx].m_t2_vec[0] = static_cast<T>(0.0);
    f_segment_ptr[l_idx].m_t2_vec[1] = static_cast<T>(0.0);
}

template <typename T>
CIirCu<T>::CIirCu()
{
    m_x = static_cast<T>(0.0);
    m_y = static_cast<T>(0.0);
    m_t1_vec[0] = static_cast<T>(0.0);
    m_t1_vec[1] = static_cast<T>(0.0);
    m_t2_vec[0] = static_cast<T>(0.0);
    m_t2_vec[1] = static_cast<T>(0.0);
}

template <typename T>
CIirCu<T>::CIirCu(const CIirCoeffs<T>& f_coeffs)
{
    m_x = static_cast<T>(0.0);
    m_y = static_cast<T>(0.0);
    m_t1_vec[0] = static_cast<T>(0.0);
    m_t1_vec[1] = static_cast<T>(0.0);
    m_t2_vec[0] = static_cast<T>(0.0);
    m_t2_vec[1] = static_cast<T>(0.0);
    m_coeffs = f_coeffs;
}

template <typename T>
CIirFilterCu<T>::CIirFilterCu()
{
}

template <typename T>
CIirFilterCu<T>::~CIirFilterCu()
{
}

template <typename T>
T CIirFilterCu<T>::doFiltering(T f_inputVal)
{
    T l_outputVal;
    dim3 l_fwd_grid(1, 1, 1);
    dim3 l_fwd_thr(1, 1, 1);
    fwdFiltering<T> << < l_fwd_grid, l_fwd_thr >> > (m_iirSegments_vec, m_numOfStages, m_bitShifter, f_inputVal, m_n, m_outputVal_ptr);
    cudaMemcpy(&l_outputVal, m_outputVal_ptr, sizeof(T), cudaMemcpyDeviceToHost);
    return l_outputVal;
}

template <typename T>
void CIirFilterCu<T>::doRwdFiltering()
{
    dim3 l_rwd_grid(1, 1, 1);
    dim3 l_rwd_thr(m_numOfStages, 1, 1);
    rwdFiltering<T> << < l_rwd_grid, l_rwd_thr >> > (m_iirSegments_vec, m_n);
    m_n++;
    m_n &= 1;
}

template <typename T>
void CIirFilterCu<T>::resetFilter()
{
    m_n = 0;
    dim3 l_res_grid(1, 1, 1);
    dim3 l_res_thr(m_numOfStages, 1, 1);
    resetSegment<T> << < l_res_grid, l_res_thr >> > (m_iirSegments_vec);
}

template <typename T>
void CIirFilterCu<T>::destroyFilter()
{
    cudaFree(m_iirSegments_vec);
    m_iirSegments_vec = 0;
    cudaFree(m_outputVal_ptr);
    m_outputVal_ptr = 0;
}

// Do NOT call this function, only to avoid the linker error
void TemporaryFunction_i16()
{
    CIirFilterCu<short> l_tempObj;
    l_tempObj.doFiltering(0);
    l_tempObj.doRwdFiltering();
    l_tempObj.resetFilter();
    l_tempObj.destroyFilter();
    CIirCoeffs<short> l_tempCoeffs;
    CIirCu<short> l_tempIir_1;
    CIirCu<short> l_tempIir_2(l_tempCoeffs);
}

// Do NOT call this function, only to avoid the linker error
void TemporaryFunction_i32()
{
    CIirFilterCu<long> l_tempObj;
    l_tempObj.doFiltering(0);
    l_tempObj.doRwdFiltering();
    l_tempObj.resetFilter();
    l_tempObj.destroyFilter();
    CIirCoeffs<long> l_tempCoeffs;
    CIirCu<long> l_tempIir_1;
    CIirCu<long> l_tempIir_2(l_tempCoeffs);
}

// Do NOT call this function, only to avoid the linker error
void TemporaryFunction_i64()
{
    CIirFilterCu<long long> l_tempObj;
    l_tempObj.doFiltering(0);
    l_tempObj.doRwdFiltering();
    l_tempObj.resetFilter();
    l_tempObj.destroyFilter();
    CIirCoeffs<long long> l_tempCoeffs;
    CIirCu<long long> l_tempIir_1;
    CIirCu<long long> l_tempIir_2(l_tempCoeffs);
}

// Do NOT call this function, only to avoid the linker error
void TemporaryFunction_f32()
{
    CIirFilterCu<float> l_tempObj;
    l_tempObj.doFiltering(0);
    l_tempObj.doRwdFiltering();
    l_tempObj.resetFilter();
    l_tempObj.destroyFilter();
    CIirCoeffs<float> l_tempCoeffs;
    CIirCu<float> l_tempIir_1;
    CIirCu<float> l_tempIir_2(l_tempCoeffs);
}

// Do NOT call this function, only to avoid the linker error
void TemporaryFunction_f64()
{
    CIirFilterCu<double> l_tempObj;
    l_tempObj.doFiltering(0);
    l_tempObj.doRwdFiltering();
    l_tempObj.resetFilter();
    l_tempObj.destroyFilter();
    CIirCoeffs<double> l_tempCoeffs;
    CIirCu<double> l_tempIir_1;
    CIirCu<double> l_tempIir_2(l_tempCoeffs);
}

