/*
 * File: ThermalConv.c
 *
 * Code generated for Simulink model 'ThermalConv'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Feb  8 13:35:43 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ThermalConv.h"
#include "ThermalConv_types.h"
#include "ThermalConv_private.h"

/* Output and update for referenced model: 'ThermalConv' */
void ThermalConv(void)
{
  /* Outputs for Atomic SubSystem: '<S2>/AdcConvertToTemp1' */
  /* Product: '<S10>/Divide' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Product: '<S11>/Product'
   *  Sum: '<S12>/Add'
   */
  BatteryThermalInput.fCellTempMax = ((float)BatteryThermalAdc.uCellTempMaxAdc *
    0.000805860793F - 0.5F) / 0.01F;

  /* End of Outputs for SubSystem: '<S2>/AdcConvertToTemp1' */

  /* Outputs for Atomic SubSystem: '<S2>/AdcConvertToTemp2' */
  /* Product: '<S13>/Divide' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant3'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Product: '<S14>/Product'
   *  Sum: '<S15>/Add'
   */
  BatteryThermalInput.fCellTempMin = ((float)BatteryThermalAdc.uCellTempMinAdc *
    0.000805860793F - 0.5F) / 0.01F;

  /* End of Outputs for SubSystem: '<S2>/AdcConvertToTemp2' */

  /* Outputs for Atomic SubSystem: '<S2>/AdcConvertToTemp3' */
  /* Product: '<S16>/Divide' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant3'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Product: '<S17>/Product'
   *  Sum: '<S18>/Add'
   */
  BatteryThermalInput.fPackTemp = ((float)BatteryThermalAdc.uPackTempAdc *
    0.000805860793F - 0.5F) / 0.01F;

  /* End of Outputs for SubSystem: '<S2>/AdcConvertToTemp3' */

  /* Outputs for Atomic SubSystem: '<S2>/AdcConvertToTemp' */
  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Product: '<S8>/Product'
   *  Sum: '<S9>/Add'
   */
  BatteryThermalInput.fAmbientTemp = ((float)BatteryThermalAdc.uAmbientTempAdc *
    0.000805860793F - 0.5F) / 0.01F;

  /* End of Outputs for SubSystem: '<S2>/AdcConvertToTemp' */

  /* BusCreator generated from: '<S1>/BatteryThermalInput_BusCreator' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  BatteryThermalInput.fChargeCurrent = 0.0F;
  BatteryThermalInput.bSensorValid = true;
  BatteryThermalInput.fDischargeCurrent = 0.0F;
}

/* Model initialize function */
void ThermalConv_initialize(const char **rt_errorStatus, RT_MODEL_ThermalConv_T *
  const ThermalConv_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(ThermalConv_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
