/*
 * File: ThermalMon.h
 *
 * Code generated for Simulink model 'ThermalMon'.
 *
 * Model version                  : 1.81
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Feb  8 10:34:48 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ThermalMon_h_
#define RTW_HEADER_ThermalMon_h_
#ifndef ThermalMon_COMMON_INCLUDES_
#define ThermalMon_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#endif                                 /* ThermalMon_COMMON_INCLUDES_ */

#include "ThermalMon_types.h"

/* Includes for objects with custom storage classes */
#include "ThermalMon_Internal.h"

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern BatteryThermalInput_t BatteryThermalInput;/* '<Root>/BatteryThermalInput' */
extern BatteryThermalStatus_t BatteryThermalStatus;/*  */
extern void ThermalMon(void);

/* Model reference registration function */
extern void ThermalMon_initialize(const char **rt_errorStatus);

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
 * '<Root>' : 'ThermalMon'
 * '<S1>'   : 'ThermalMon/ThermalMon'
 * '<S2>'   : 'ThermalMon/ThermalMon/ThermalMon_Alg'
 * '<S3>'   : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalMon_LPF_Gradient'
 * '<S4>'   : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalMon_StateClassifier'
 * '<S5>'   : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalStatusFlagGenerator'
 * '<S6>'   : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalMon_LPF_Gradient/ThermalMon_LPF_Gradient'
 * '<S7>'   : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalMon_StateClassifier/Enumerated Constant'
 * '<S8>'   : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalMon_StateClassifier/Enumerated Constant1'
 * '<S9>'   : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalMon_StateClassifier/Enumerated Constant2'
 * '<S10>'  : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalMon_StateClassifier/Enumerated Constant3'
 * '<S11>'  : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalMon_StateClassifier/Enumerated Constant4'
 * '<S12>'  : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalMon_StateClassifier/Enumerated Constant5'
 * '<S13>'  : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalStatusFlagGenerator/Enumerated Constant5'
 * '<S14>'  : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalStatusFlagGenerator/Enumerated Constant6'
 * '<S15>'  : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalStatusFlagGenerator/Enumerated Constant7'
 * '<S16>'  : 'ThermalMon/ThermalMon/ThermalMon_Alg/ThermalStatusFlagGenerator/Enumerated Constant8'
 */
#endif                                 /* RTW_HEADER_ThermalMon_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
