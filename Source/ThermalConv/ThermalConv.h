/*
 * File: ThermalConv.h
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

#ifndef RTW_HEADER_ThermalConv_h_
#define RTW_HEADER_ThermalConv_h_
#ifndef ThermalConv_COMMON_INCLUDES_
#define ThermalConv_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#endif                                 /* ThermalConv_COMMON_INCLUDES_ */

#include "ThermalConv_types.h"

/* Real-time Model Data Structure */
struct tag_RTM_ThermalConv_T {
  const char **errorStatus;
};

typedef struct {
  RT_MODEL_ThermalConv_T rtm;
} MdlrefDW_ThermalConv_T;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern BatteryThermalAdc_t BatteryThermalAdc;/* '<Root>/BatteryThermalAdc' */
extern BatteryThermalInput_t BatteryThermalInput;/*  */

/* Model reference registration function */
extern void ThermalConv_initialize(const char **rt_errorStatus,
  RT_MODEL_ThermalConv_T *const ThermalConv_M);
extern void ThermalConv(void);

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
 * '<Root>' : 'ThermalConv'
 * '<S1>'   : 'ThermalConv/ThermalConv'
 * '<S2>'   : 'ThermalConv/ThermalConv/ThermalConv_Alg'
 */
#endif                                 /* RTW_HEADER_ThermalConv_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
