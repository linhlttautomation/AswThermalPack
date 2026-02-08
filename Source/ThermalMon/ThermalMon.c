/*
 * File: ThermalMon.c
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

#include "ThermalMon.h"
#include "ThermalMon_private.h"
#include "ThermalMon_types.h"
#include <math.h>
#include "ThermalMon_Internal.h"

MdlrefDW_ThermalMon_T ThermalMon_MdlrefDW;

/* Block signals (default storage) */
B_ThermalMon_c_T ThermalMon_B;

/* Block states (default storage) */
DW_ThermalMon_f_T ThermalMon_DW;

/* Output and update for atomic system: '<S2>/ThermalMon_LPF_Gradient' */
void Thermal_ThermalMon_LPF_Gradient(void)
{
  /* MATLAB Function: '<S3>/ThermalMon_LPF_Gradient' */
  if (!ThermalMon_DW.fFilteredTemp_prev_not_empty) {
    ThermalMon_DW.fFilteredTemp_prev = ThermalMon_B.Max;
    ThermalMon_DW.fFilteredTemp_prev_not_empty = true;
  }

  ThermalMon_B.fFilteredTemp = (ThermalMon_B.Max -
    ThermalMon_DW.fFilteredTemp_prev) * THERMALMON_FILTER_ALPHA +
    ThermalMon_DW.fFilteredTemp_prev;
  ThermalMon_B.fTempGradient = (ThermalMon_B.fFilteredTemp -
    ThermalMon_DW.fFilteredTemp_prev) / THERMALMON_TS_SEC;
  ThermalMon_DW.fFilteredTemp_prev = ThermalMon_B.fFilteredTemp;

  /* End of MATLAB Function: '<S3>/ThermalMon_LPF_Gradient' */
}

/* Output and update for atomic system: '<S2>/ThermalMon_StateClassifier' */
void Ther_ThermalMon_StateClassifier(void)
{
  /* Switch: '<S4>/Switch4' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   *  Inport generated from: '<Root>/In Bus Element'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  RelationalOperator: '<S4>/Relational Operator1'
   *  RelationalOperator: '<S4>/Relational Operator2'
   *  RelationalOperator: '<S4>/Relational Operator3'
   *  Switch: '<S4>/Switch'
   *  Switch: '<S4>/Switch1'
   *  Switch: '<S4>/Switch2'
   *  Switch: '<S4>/Switch3'
   */
  if (BatteryThermalInput.bSensorValid) {
    /* Switch: '<S4>/Switch4' incorporates:
     *  Constant: '<S12>/Constant'
     */
    ThermalMon_B.Switch4 = THERM_CRITICAL;
  } else if (ThermalMon_B.fFilteredTemp <= THERMALMON_T_UNDER_TH) {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S7>/Constant'
     *  Switch: '<S4>/Switch4'
     */
    ThermalMon_B.Switch4 = THERM_UNDER_TEMP;
  } else if (ThermalMon_B.fFilteredTemp <= THERMALMON_T_WARNING_TH) {
    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S8>/Constant'
     *  Switch: '<S4>/Switch'
     *  Switch: '<S4>/Switch4'
     */
    ThermalMon_B.Switch4 = THERM_NORMAL;
  } else if (ThermalMon_B.fFilteredTemp <= THERMALMON_T_OVERHEAT_TH) {
    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S9>/Constant'
     *  Switch: '<S4>/Switch'
     *  Switch: '<S4>/Switch1'
     *  Switch: '<S4>/Switch4'
     */
    ThermalMon_B.Switch4 = THERM_WARNING;
  } else if (ThermalMon_B.fFilteredTemp <= THERMALMON_T_CRITICAL_TH) {
    /* Switch: '<S4>/Switch3' incorporates:
     *  Constant: '<S10>/Constant'
     *  Switch: '<S4>/Switch'
     *  Switch: '<S4>/Switch1'
     *  Switch: '<S4>/Switch2'
     *  Switch: '<S4>/Switch4'
     */
    ThermalMon_B.Switch4 = THERM_OVERHEAT;
  } else {
    /* Switch: '<S4>/Switch4' incorporates:
     *  Constant: '<S11>/Constant'
     *  Switch: '<S4>/Switch'
     *  Switch: '<S4>/Switch1'
     *  Switch: '<S4>/Switch2'
     *  Switch: '<S4>/Switch3'
     */
    ThermalMon_B.Switch4 = THERM_CRITICAL;
  }

  /* End of Switch: '<S4>/Switch4' */
}

/* Output and update for atomic system: '<S2>/ThermalStatusFlagGenerator' */
void Ther_ThermalStatusFlagGenerator(void)
{
  /* Switch: '<S5>/Switch4' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S5>/Constant10'
   *  Constant: '<S5>/Constant11'
   *  Constant: '<S5>/Constant8'
   *  Constant: '<S5>/Constant9'
   *  Inport generated from: '<Root>/In Bus Element'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  RelationalOperator: '<S5>/Relational Operator1'
   *  RelationalOperator: '<S5>/Relational Operator2'
   *  RelationalOperator: '<S5>/Relational Operator3'
   *  Switch: '<S5>/Switch5'
   *  Switch: '<S5>/Switch6'
   *  Switch: '<S5>/Switch7'
   */
  if (BatteryThermalInput.bSensorValid) {
    BatteryThermalStatus.bUnderTemp = false;
    BatteryThermalStatus.bOverTempWarn = true;
    BatteryThermalStatus.bOverTempCrit = true;
    BatteryThermalStatus.bDerateReq = true;
  } else {
    BatteryThermalStatus.bUnderTemp = (ThermalMon_B.Switch4 == THERM_UNDER_TEMP);
    BatteryThermalStatus.bOverTempWarn = (ThermalMon_B.Switch4 == THERM_WARNING);
    BatteryThermalStatus.bOverTempCrit = (ThermalMon_B.Switch4 == THERM_OVERHEAT);
    BatteryThermalStatus.bDerateReq = (ThermalMon_B.Switch4 == THERM_CRITICAL);
  }

  /* End of Switch: '<S5>/Switch4' */
}

/* Output and update for referenced model: 'ThermalMon' */
void ThermalMon(void)
{
  /* MinMax: '<S2>/Max' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  ThermalMon_B.Max = fmaxf(fmaxf(fmaxf(BatteryThermalInput.fCellTempMax,
    BatteryThermalInput.fPackTemp), BatteryThermalInput.fCellTempMin),
    BatteryThermalInput.fAmbientTemp);

  /* Outputs for Atomic SubSystem: '<S2>/ThermalMon_LPF_Gradient' */
  Thermal_ThermalMon_LPF_Gradient();

  /* End of Outputs for SubSystem: '<S2>/ThermalMon_LPF_Gradient' */

  /* Outputs for Atomic SubSystem: '<S2>/ThermalMon_StateClassifier' */
  Ther_ThermalMon_StateClassifier();

  /* End of Outputs for SubSystem: '<S2>/ThermalMon_StateClassifier' */

  /* Outputs for Atomic SubSystem: '<S2>/ThermalStatusFlagGenerator' */
  Ther_ThermalStatusFlagGenerator();

  /* End of Outputs for SubSystem: '<S2>/ThermalStatusFlagGenerator' */

  /* BusCreator generated from: '<S1>/BatteryThermalStatus_BusCreator' */
  BatteryThermalStatus.eThermalState = ThermalMon_B.Switch4;
  BatteryThermalStatus.fFilteredTemp = ThermalMon_B.fFilteredTemp;
  BatteryThermalStatus.fTempGradient = ThermalMon_B.fTempGradient;
}

/* Model initialize function */
void ThermalMon_initialize(const char **rt_errorStatus)
{
  RT_MODEL_ThermalMon_T *const ThermalMon_M = &(ThermalMon_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(ThermalMon_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
