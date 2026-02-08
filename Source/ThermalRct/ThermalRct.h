/*
 * File: ThermalRct.h
 *
 * Code generated for Simulink model 'ThermalRct'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Feb  1 23:11:45 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ThermalRct_h_
#define RTW_HEADER_ThermalRct_h_
#ifndef ThermalRct_COMMON_INCLUDES_
#define ThermalRct_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#endif                                 /* ThermalRct_COMMON_INCLUDES_ */

#include "ThermalRct_types.h"

/* Includes for objects with custom storage classes */
#include "ThermalRct_Internal.h"

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern BatteryThermalStatus_t BatteryThermalStatus;/* '<Root>/BatteryThermalStatus' */
extern BatteryThermalCmd_t BatteryThermalCmd;/*  */
extern void ThermalRct(void);

/* Model reference registration function */
extern void ThermalRct_initialize(const char **rt_errorStatus);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ThermalRct'
 * '<S1>'   : 'ThermalRct/ThermalRct'
 * '<S2>'   : 'ThermalRct/ThermalRct/ThermalRct_Alg'
 * '<S3>'   : 'ThermalRct/ThermalRct/ThermalRct_Alg/FaultLatchMon'
 * '<S4>'   : 'ThermalRct/ThermalRct/ThermalRct_Alg/ProtectionDecision'
 * '<S5>'   : 'ThermalRct/ThermalRct/ThermalRct_Alg/ProtectionDecision/Chart'
 */
#endif                                 /* RTW_HEADER_ThermalRct_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
