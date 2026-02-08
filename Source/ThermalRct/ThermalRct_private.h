/*
 * File: ThermalRct_private.h
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

#ifndef RTW_HEADER_ThermalRct_private_h_
#define RTW_HEADER_ThermalRct_private_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "ThermalRct_types.h"

/* Block signals for model 'ThermalRct' */
typedef struct {
  float fChargeCurrentLimit;           /* '<S4>/Chart' */
  float fDischargeCurrentLimit;        /* '<S4>/Chart' */
  ContactorCmd_e eBatteryContactorCmd; /* '<S4>/Chart' */
  uint16_t uPumpSpeedCmd;              /* '<S4>/Chart' */
  bool bBatteryHeaterCmd;              /* '<S4>/Chart' */
  bool bCoolingFanCmd;                 /* '<S4>/Chart' */
} B_ThermalRct_c_T;

/* Block states (default storage) for model 'ThermalRct' */
typedef struct {
  uint8_t is_active_c3_ThermalRct;     /* '<S4>/Chart' */
  uint8_t is_c3_ThermalRct;            /* '<S4>/Chart' */
} DW_ThermalRct_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_ThermalRct_T {
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
  RT_MODEL_ThermalRct_T rtm;
} MdlrefDW_ThermalRct_T;

extern void ThermalRct_FaultLatchMon(void);
extern void ThermalRct_ProtectionDecision(void);
extern MdlrefDW_ThermalRct_T ThermalRct_MdlrefDW;

/* Block signals (default storage) */
extern B_ThermalRct_c_T ThermalRct_B;

/* Block states (default storage) */
extern DW_ThermalRct_f_T ThermalRct_DW;

#endif                                 /* RTW_HEADER_ThermalRct_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
