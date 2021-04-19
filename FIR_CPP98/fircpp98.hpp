// fircpp98_hpp.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of a general C++98 FIR filter implementation

#ifndef _FIRCPP98_HPP_
#define _FIRCPP98_HPP_

#include <vector>

#define RETURN_OK 0
#define RETURN_ERROR -1

template <typename T>
class CFirCpp98
{
private:
    typename std::vector<T>::iterator m_inputBuffer_it;
protected:
    std::vector<T> m_coeffs_vec;
    std::vector<T> m_inputBuffer_vec;

    CFirCpp98()
    {
        m_coeffs_vec.clear();
        m_inputBuffer_it = m_inputBuffer_vec.begin();
    }

    T doFiltering(T f_inputVal)
    {
        T l_outputVal = static_cast<T>(0.0);
        T l_tempVal = static_cast<T>(0.0);
        typename std::vector<T>::const_iterator l_coeff_it = m_coeffs_vec.begin();
        *m_inputBuffer_it = f_inputVal;
        while (m_inputBuffer_it > m_inputBuffer_vec.begin())
        {
            l_outputVal += *l_coeff_it * *m_inputBuffer_it;
            ++l_coeff_it;
            --m_inputBuffer_it;
        }
        l_outputVal += *l_coeff_it * *m_inputBuffer_it;
        ++l_coeff_it;
        m_inputBuffer_it = m_inputBuffer_vec.end() - 1;
        while (l_coeff_it < m_coeffs_vec.end())
        {
            l_outputVal += *l_coeff_it * *m_inputBuffer_it;
            ++l_coeff_it;
            --m_inputBuffer_it;
        }
        ++m_inputBuffer_it;
        if (m_inputBuffer_it >= m_inputBuffer_vec.end())
        {
            m_inputBuffer_it = m_inputBuffer_vec.begin();
        }
        return (l_outputVal);
    }

public:
    virtual ~CFirCpp98()
    {
        m_coeffs_vec.clear();
        m_inputBuffer_vec.clear();
    }
    void resetFilter()
    {
        m_inputBuffer_it = m_inputBuffer_vec.begin();
        std::fill(m_inputBuffer_vec.begin(), m_inputBuffer_vec.end(), static_cast<T>(0.0));
    }
};

#endif
