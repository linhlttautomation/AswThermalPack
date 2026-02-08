/*
 * File: ThermalMon_types.h
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

#ifndef RTW_HEADER_ThermalMon_types_h_
#define RTW_HEADER_ThermalMon_types_h_
#include <stdint.h>
#include <stdbool.h>
#ifndef DEFINED_TYPEDEF_FOR_ThermalState_e_
#define DEFINED_TYPEDEF_FOR_ThermalState_e_

typedef enum {
  THERM_UNDER_TEMP = 0,                /* Default value */
  THERM_NORMAL,
  THERM_WARNING,
  THERM_OVERHEAT,
  THERM_CRITICAL
} ThermalState_e;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BatteryThermalInput_t_
#define DEFINED_TYPEDEF_FOR_BatteryThermalInput_t_

typedef struct {
  /* Maximum temperature measured among all battery cells */
  float fCellTempMax;

  /* Minimum temperature measured among all battery cells */
  float fCellTempMin;

  /* Average temperature of the battery pack */
  float fPackTemp;

  /* Current flowing into the battery during charging */
  float fChargeCurrent;

  /* Ambient environmental temperature surrounding the battery */
  float fAmbientTemp;

  /* Indicates whether thermal sensor data is valid */
  bool bSensorValid;

  /* Current flowing out of the battery during discharging */
  float fDischargeCurrent;
} BatteryThermalInput_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BatteryThermalStatus_t_
#define DEFINED_TYPEDEF_FOR_BatteryThermalStatus_t_

typedef struct {
  /* Classified thermal state of the battery pack */
  ThermalState_e eThermalState;

  /* Filtered and stabilized battery temperature value */
  float fFilteredTemp;

  /* Rate of temperature change over time (°C/s) */
  float fTempGradient;

  /* Indicates battery temperature exceeds warning threshold */
  bool bOverTempWarn;

  /* Indicates battery temperature exceeds critical threshold */
  bool bOverTempCrit;

  /* Request to reduce charging and discharging power */
  bool bDerateReq;

  /* Indicates battery temperature is below minimum operating limit */
  bool bUnderTemp;
} BatteryThermalStatus_t;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_ThermalMon_T RT_MODEL_ThermalMon_T;

#endif                                 /* RTW_HEADER_ThermalMon_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
