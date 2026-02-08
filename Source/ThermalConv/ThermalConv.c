/*
 * File: ThermalConv.c
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

#include "ThermalConv.h"
#include "ThermalConv_types.h"
#include "ThermalConv_private.h"

/* Output and update for referenced model: 'ThermalConv' */
void ThermalConv(void)
{
  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   *  RelationalOperator: '<S2>/Relational Operator'
   */
  BatteryThermalInput.fAmbientTemp = (float)(BatteryThermalAdc.uAmbientTempAdc <=
    1);

  /* BusCreator generated from: '<S1>/BatteryThermalInput_BusCreator' */
  BatteryThermalInput.fCellTempMax = 0.0F;
  BatteryThermalInput.fCellTempMin = 0.0F;
  BatteryThermalInput.fPackTemp = 0.0F;
  BatteryThermalInput.fChargeCurrent = 0.0F;
  BatteryThermalInput.bSensorValid = false;
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
