/*
 * File: ThermalConv_private.h
 *
 * Code generated for Simulink model 'ThermalConv'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Feb  8 11:42:24 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ThermalConv_private_h_
#define RTW_HEADER_ThermalConv_private_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "ThermalConv_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif
#endif                                 /* RTW_HEADER_ThermalConv_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
