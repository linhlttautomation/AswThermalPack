/*
 * File: ThermalRct.c
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

#include "ThermalRct.h"
#include <stdint.h>
#include "ThermalRct_private.h"
#include "ThermalRct_types.h"
#include "ThermalRct_Internal.h"

/* Named constants for Chart: '<S4>/Chart' */
#define ThermalRct_IN_CRITICAL         ((uint8_t)1U)
#define ThermalRct_IN_NORMAL           ((uint8_t)2U)
#define ThermalRct_IN_OVERHEAT         ((uint8_t)3U)
#define ThermalRct_IN_UNDER_TEMP       ((uint8_t)4U)
#define ThermalRct_IN_WARNING          ((uint8_t)5U)

MdlrefDW_ThermalRct_T ThermalRct_MdlrefDW;

/* Block signals (default storage) */
B_ThermalRct_c_T ThermalRct_B;

/* Block states (default storage) */
DW_ThermalRct_f_T ThermalRct_DW;

/* Output and update for atomic system: '<S2>/FaultLatchMon' */
void ThermalRct_FaultLatchMon(void)
{
  /* Logic: '<S3>/OR' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  BatteryThermalCmd.bFaultLatch = (BatteryThermalStatus.bDerateReq ||
    BatteryThermalStatus.bOverTempCrit || BatteryThermalStatus.bUnderTemp);
}

/* Output and update for atomic system: '<S2>/ProtectionDecision' */
void ThermalRct_ProtectionDecision(void)
{
  /* Chart: '<S4>/Chart' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  if (ThermalRct_DW.is_active_c3_ThermalRct == 0U) {
    ThermalRct_DW.is_active_c3_ThermalRct = 1U;
    ThermalRct_DW.is_c3_ThermalRct = ThermalRct_IN_NORMAL;
    ThermalRct_B.bBatteryHeaterCmd = false;
    ThermalRct_B.bCoolingFanCmd = false;
    ThermalRct_B.uPumpSpeedCmd = ((uint16_t)TRCT_PUMP_OFF);
    ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
    ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_NORMAL;
    ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_NORMAL;
  } else {
    switch (ThermalRct_DW.is_c3_ThermalRct) {
     case ThermalRct_IN_CRITICAL:
      ThermalRct_B.bBatteryHeaterCmd = false;
      ThermalRct_B.bCoolingFanCmd = true;
      ThermalRct_B.uPumpSpeedCmd = ((uint16_t)TRCT_PUMP_MAX);
      ThermalRct_B.eBatteryContactorCmd = CONTACTOR_OPEN;
      ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_OFF;
      ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_OFF;
      if (BatteryThermalStatus.eThermalState == THERM_OVERHEAT) {
        ThermalRct_DW.is_c3_ThermalRct = ThermalRct_IN_OVERHEAT;
        ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
        ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_OVERHEAT;
        ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_OVERHEAT;
      }
      break;

     case ThermalRct_IN_NORMAL:
      ThermalRct_B.bBatteryHeaterCmd = false;
      ThermalRct_B.bCoolingFanCmd = false;
      ThermalRct_B.uPumpSpeedCmd = ((uint16_t)TRCT_PUMP_OFF);
      ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
      ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_NORMAL;
      ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_NORMAL;
      switch (BatteryThermalStatus.eThermalState) {
       case THERM_UNDER_TEMP:
        ThermalRct_DW.is_c3_ThermalRct = ThermalRct_IN_UNDER_TEMP;
        ThermalRct_B.bBatteryHeaterCmd = true;
        ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
        ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_UNDER_TEMP;
        break;

       case THERM_WARNING:
        ThermalRct_DW.is_c3_ThermalRct = ThermalRct_IN_WARNING;
        ThermalRct_B.bCoolingFanCmd = true;
        ThermalRct_B.uPumpSpeedCmd = ((uint16_t)TRCT_PUMP_MEDIUM);
        ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
        ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_WARNING;
        ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_WARNING;
        break;
      }
      break;

     case ThermalRct_IN_OVERHEAT:
      ThermalRct_B.bBatteryHeaterCmd = false;
      ThermalRct_B.bCoolingFanCmd = true;
      ThermalRct_B.uPumpSpeedCmd = ((uint16_t)TRCT_PUMP_MAX);
      ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
      ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_OVERHEAT;
      ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_OVERHEAT;
      switch (BatteryThermalStatus.eThermalState) {
       case THERM_WARNING:
        ThermalRct_DW.is_c3_ThermalRct = ThermalRct_IN_WARNING;
        ThermalRct_B.uPumpSpeedCmd = ((uint16_t)TRCT_PUMP_MEDIUM);
        ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
        ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_WARNING;
        ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_WARNING;
        break;

       case THERM_CRITICAL:
        ThermalRct_DW.is_c3_ThermalRct = ThermalRct_IN_CRITICAL;
        ThermalRct_B.eBatteryContactorCmd = CONTACTOR_OPEN;
        ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_OFF;
        ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_OFF;
        break;
      }
      break;

     case ThermalRct_IN_UNDER_TEMP:
      ThermalRct_B.bBatteryHeaterCmd = true;
      ThermalRct_B.bCoolingFanCmd = false;
      ThermalRct_B.uPumpSpeedCmd = ((uint16_t)TRCT_PUMP_OFF);
      ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
      ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_UNDER_TEMP;
      ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_NORMAL;
      if (BatteryThermalStatus.eThermalState == THERM_NORMAL) {
        ThermalRct_DW.is_c3_ThermalRct = ThermalRct_IN_NORMAL;
        ThermalRct_B.bBatteryHeaterCmd = false;
        ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
        ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_NORMAL;
      }
      break;

     default:
      /* case IN_WARNING: */
      ThermalRct_B.bBatteryHeaterCmd = false;
      ThermalRct_B.bCoolingFanCmd = true;
      ThermalRct_B.uPumpSpeedCmd = ((uint16_t)TRCT_PUMP_MEDIUM);
      ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
      ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_WARNING;
      ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_WARNING;
      switch (BatteryThermalStatus.eThermalState) {
       case THERM_NORMAL:
        ThermalRct_DW.is_c3_ThermalRct = ThermalRct_IN_NORMAL;
        ThermalRct_B.bCoolingFanCmd = false;
        ThermalRct_B.uPumpSpeedCmd = ((uint16_t)TRCT_PUMP_OFF);
        ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
        ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_NORMAL;
        ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_NORMAL;
        break;

       case THERM_OVERHEAT:
        ThermalRct_DW.is_c3_ThermalRct = ThermalRct_IN_OVERHEAT;
        ThermalRct_B.uPumpSpeedCmd = ((uint16_t)TRCT_PUMP_MAX);
        ThermalRct_B.eBatteryContactorCmd = CONTACTOR_CLOSE;
        ThermalRct_B.fChargeCurrentLimit = TRCT_CHG_OVERHEAT;
        ThermalRct_B.fDischargeCurrentLimit = TRCT_DISCHG_OVERHEAT;
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Chart' */
}

/* Output and update for referenced model: 'ThermalRct' */
void ThermalRct(void)
{
  /* Outputs for Atomic SubSystem: '<S2>/ProtectionDecision' */
  ThermalRct_ProtectionDecision();

  /* End of Outputs for SubSystem: '<S2>/ProtectionDecision' */

  /* Outputs for Atomic SubSystem: '<S2>/FaultLatchMon' */
  ThermalRct_FaultLatchMon();

  /* End of Outputs for SubSystem: '<S2>/FaultLatchMon' */

  /* BusCreator generated from: '<S1>/BatteryThermalCmd_BusCreator' */
  BatteryThermalCmd.bCoolingFanCmd = ThermalRct_B.bCoolingFanCmd;
  BatteryThermalCmd.bBatteryHeaterCmd = ThermalRct_B.bBatteryHeaterCmd;
  BatteryThermalCmd.uPumpSpeedCmd = ThermalRct_B.uPumpSpeedCmd;
  BatteryThermalCmd.eBatteryContactorCmd = ThermalRct_B.eBatteryContactorCmd;
  BatteryThermalCmd.fChargeCurrentLimit = ThermalRct_B.fChargeCurrentLimit;
  BatteryThermalCmd.fDischargeCurrentLimit = ThermalRct_B.fDischargeCurrentLimit;
}

/* Model initialize function */
void ThermalRct_initialize(const char **rt_errorStatus)
{
  RT_MODEL_ThermalRct_T *const ThermalRct_M = &(ThermalRct_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(ThermalRct_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
