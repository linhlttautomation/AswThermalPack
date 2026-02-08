/*
 * File: ThermalConv_types.h
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

#ifndef RTW_HEADER_ThermalConv_types_h_
#define RTW_HEADER_ThermalConv_types_h_
#include <stdint.h>
#include <stdbool.h>
#ifndef DEFINED_TYPEDEF_FOR_BatteryThermalAdc_t_
#define DEFINED_TYPEDEF_FOR_BatteryThermalAdc_t_

typedef struct {
  /* ADC measurement of ambient environmental temperature surrounding the battery */
  uint16_t uAmbientTempAdc;

  /* ADC measurement of mamaximum temperature measured among all battery cells */
  uint16_t uCellTempMaxAdc;

  /* ADC measurement of minimum temperature measured among all battery cells */
  uint16_t uCellTempMinAdc;

  /* ADC measurement of average temperature of the battery pack */
  uint16_t uPackTempAdc;
} BatteryThermalAdc_t;

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

/* Forward declaration for rtModel */
typedef struct tag_RTM_ThermalConv_T RT_MODEL_ThermalConv_T;

#endif                                 /* RTW_HEADER_ThermalConv_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
