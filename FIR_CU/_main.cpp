// Example to print out the frequency response of the filter

#include "MyFilter_firi64cu.hpp" // STEP 0: Include the generated header file of the filter implementation

// These includes are necessary for the filter simulation. They are probably not neccessary for your filter application
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

// Simulation parameters
#define NUM_OF_STEPS 1001 // The frequency range between 0 Hz and SAMPLING_FREQ Hz will be divided to as much parts
#define NUM_OF_SAMPLES 3700 // The number of analysed steps at the single frequency values, shorter value may give uncertain results, longer value causes longer simulation time
#define SAMPLING_FREQ 16000.0 // Sampling frequency, must be the same value, as the sampling frequency of the filter
#define AMPLITUDE 131071 // Amplitude of the incoming signal, lower values may cause underflow, higher values may cause overflow
#define INITIALLY_IGNORED_SAMPLES 100 // Some of the first samples must ignored for the result calculation

int main()
{
	CMyFilterFirI64Cu l_myFilter; // STEP 1: Make a filter instance

	if (RETURN_OK != l_myFilter.initFilter()) // STEP 2: Initialise it
	{
		printf("Implement your failure handling for this case!\n");
		return RETURN_ERROR;
	}

	double l_startFreq_f64 = 0.0;
	double l_finalFreq_f64 = SAMPLING_FREQ / 2.0;
	double l_samplingFreq_f64 = SAMPLING_FREQ;
	const unsigned long l_numOfSteps_ui64 = NUM_OF_STEPS;
	double l_recentFreq_f64 = l_startFreq_f64;
	double l_stepSize_f64 = (l_finalFreq_f64 - l_startFreq_f64) / ((double)l_numOfSteps_ui64);

	double l_amplitude_f64 = AMPLITUDE;
	unsigned long l_startAtSample_ui64 = INITIALLY_IGNORED_SAMPLES; // to avoid start up transient behaviour, must be at least 16* num of stages
	unsigned long l_numOfSamples_ui64 = NUM_OF_SAMPLES; // number of signal periods at the half of sampling frequency
	while (l_recentFreq_f64 < l_finalFreq_f64)
	{
		l_myFilter.resetFilter(); // STEP 3: Reset the filter between the frequency steps

		double l_absSumInput_f64 = 0.0;
		double l_absSumOutput_f64 = 0.0;
		for (unsigned long l_sampleCntr_ui64 = 0; l_sampleCntr_ui64 < (l_numOfSamples_ui64 + l_startAtSample_ui64); l_sampleCntr_ui64++)
		{
			double l_inputVal_f64 = 0.0;
			if (l_recentFreq_f64 > 0.0)
			{
				double l_arg_f64 = ((double)l_sampleCntr_ui64 * 2.0 * l_recentFreq_f64 * M_PI) / l_samplingFreq_f64;
				l_inputVal_f64 = l_amplitude_f64 * sin(l_arg_f64);
			}
			else
			{
				l_inputVal_f64 = l_amplitude_f64;
			}

			long long l_realInputVal = (long long)(round(l_inputVal_f64)); // Input value must fit to the filter data type
			long long l_realOutputVal = 0.0; // Input value must fit to the filter data type

			l_realOutputVal = l_myFilter.doFiltering(l_realInputVal); // STEP 4: Call the filter with the recent input value

			double l_outputVal_f64 = (double)l_realOutputVal; // Only for the simulation

			if (l_sampleCntr_ui64 >= l_startAtSample_ui64) // Ignoring the first elements to avoid transient error
			{
				l_absSumInput_f64 += fabs(l_inputVal_f64);
				l_absSumOutput_f64 += fabs(l_outputVal_f64);
			}
		}
		double l_aVal_f64 = 20.0 * log10(l_absSumOutput_f64 / l_absSumInput_f64);
		printf("f = %f Hz, A = %f dB\n", l_recentFreq_f64, l_aVal_f64);

		l_recentFreq_f64 = l_recentFreq_f64 + l_stepSize_f64;
	}
	l_myFilter.destroyFilter(); // STEP 5: Clean up the memory at the end of the operation
	return 0;
}
