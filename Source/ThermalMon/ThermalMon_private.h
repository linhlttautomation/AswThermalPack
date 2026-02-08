/*
 * File: ThermalMon_private.h
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

#ifndef RTW_HEADER_ThermalMon_private_h_
#define RTW_HEADER_ThermalMon_private_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "ThermalMon_types.h"

/* Block signals for model 'ThermalMon' */
typedef struct {
  float Max;                           /* '<S2>/Max' */
  float fFilteredTemp;                 /* '<S3>/ThermalMon_LPF_Gradient' */
  float fTempGradient;                 /* '<S3>/ThermalMon_LPF_Gradient' */
  ThermalState_e Switch4;              /* '<S4>/Switch4' */
} B_ThermalMon_c_T;

/* Block states (default storage) for model 'ThermalMon' */
typedef struct {
  float fFilteredTemp_prev;            /* '<S3>/ThermalMon_LPF_Gradient' */
  bool fFilteredTemp_prev_not_empty;   /* '<S3>/ThermalMon_LPF_Gradient' */
} DW_ThermalMon_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_ThermalMon_T {
  const char **errorStatus;
};

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

typedef struct {
  RT_MODEL_ThermalMon_T rtm;
} MdlrefDW_ThermalMon_T;

extern void Thermal_ThermalMon_LPF_Gradient(void);
extern void Ther_ThermalMon_StateClassifier(void);
extern void Ther_ThermalStatusFlagGenerator(void);
extern MdlrefDW_ThermalMon_T ThermalMon_MdlrefDW;

/* Block signals (default storage) */
extern B_ThermalMon_c_T ThermalMon_B;

/* Block states (default storage) */
extern DW_ThermalMon_f_T ThermalMon_DW;

#endif                                 /* RTW_HEADER_ThermalMon_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
