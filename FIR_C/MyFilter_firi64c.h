// filtername_firXXXc_h.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of MyFilter C FIR filter implementation with the datatype of long long
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
// Validator DLL version: FIR_C_VALIDATOR_01_01_01
// Result checksum: 818c2239ddde0b19e5ec1fd51392b366

#ifndef _MYFILTERFIRI64C_H_
#define _MYFILTERFIRI64C_H_

#include "firi64c.h"

extern long CMyFilterFirI64C_initFilter(CFirI64CData* self);
extern void CMyFilterFirI64C_destroyFilter(CFirI64CData* self);

#endif
