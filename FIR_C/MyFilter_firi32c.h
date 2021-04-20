// filtername_firXXXc_h.txt template file, version: 01_02_01
// GENERATED FILE! MODIFY THIS FILE ONLY AT YOUR OWN RESPONSIBLITY!
// An identical behaviour to the simulation results can be assured only if this file remains unchanged!
// Header file of MyFilter C FIR filter implementation with the datatype of long
// File implements the following filter:
// FINITE IMPULSE RESPONSE
// HIGH PASS FILTER
// A_s = -40.0 dB
// f_sa = 16000.0 Hz
// f_s = 2000.0 Hz, f_c = 3000.0 Hz
// Requirement checksum: cad78480e6a9e9b969be6d7f680075a4

// Created at unix time: 1618932310
// Designer DLL version: FIR_DESIGNER_01_01_02
// Licensed DLL user: Gabor Kiszely
// DLL license info: 2021_01_09
// Filter valid: True
// Validator DLL version: FIR_C_VALIDATOR_01_01_01
// Result checksum: 86db80a3dd82b31100281e8cafa3a6e2

#ifndef _MYFILTERFIRI32C_H_
#define _MYFILTERFIRI32C_H_

#include "firi32c.h"

extern long CMyFilterFirI32C_initFilter(CFirI32CData* self);
extern void CMyFilterFirI32C_destroyFilter(CFirI32CData* self);

#endif
