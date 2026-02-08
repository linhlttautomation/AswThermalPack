/*
 * File: ThermalRct_types.h
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

#ifndef RTW_HEADER_ThermalRct_types_h_
#define RTW_HEADER_ThermalRct_types_h_
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

#ifndef DEFINED_TYPEDEF_FOR_ContactorCmd_e_
#define DEFINED_TYPEDEF_FOR_ContactorCmd_e_

typedef enum {
  CONTACTOR_OPEN = 0,                  /* Default value */
  CONTACTOR_CLOSE
} ContactorCmd_e;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BatteryThermalCmd_t_
#define DEFINED_TYPEDEF_FOR_BatteryThermalCmd_t_

typedef struct {
  /* Command to enable or disable the cooling fan */
  bool bCoolingFanCmd;

  /* Command to activate battery heating system */
  bool bBatteryHeaterCmd;

  /* Latched thermal fault requiring system reset */
  bool bFaultLatch;

  /* Requested cooling pump speed percentage */
  uint16_t uPumpSpeedCmd;

  /* Command to open or close the battery contactor */
  ContactorCmd_e eBatteryContactorCmd;

  /* Maximum allowed battery charging current */
  float fChargeCurrentLimit;

  /* Maximum allowed battery discharging current */
  float fDischargeCurrentLimit;
} BatteryThermalCmd_t;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_ThermalRct_T RT_MODEL_ThermalRct_T;

#endif                                 /* RTW_HEADER_ThermalRct_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
