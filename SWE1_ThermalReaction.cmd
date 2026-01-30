# SWE1 REQUIREMENTS – ThermalReaction (ThermalRct)

---

## 1. Scope

The ThermalReaction component is responsible for deciding thermal protection actions based on battery thermal status provided by ThermalMonitor.

ThermalReaction SHALL generate thermal control commands and protection requests but SHALL NOT directly control hardware actuators.

---

## 2. Interface Requirements

### REQ-TRCT-IF-001
ThermalReaction SHALL receive thermal status information via `BatteryThermalStatus_bus`.

### REQ-TRCT-IF-002
ThermalReaction SHALL output thermal reaction commands via `BatteryThermalCmd_bus`.

### REQ-TRCT-IF-003
ThermalReaction SHALL use enumerated data types for all command outputs where applicable.

---

## 3. Thermal State Handling Requirements

### REQ-TRCT-STATE-001
ThermalReaction SHALL evaluate the input `ThermalState` every execution cycle.

### REQ-TRCT-STATE-002
ThermalReaction SHALL base all reaction decisions primarily on `ThermalState`.

### REQ-TRCT-STATE-003
ThermalReaction SHALL support the following thermal states:
- THERM_UNDER_TEMP  
- THERM_NORMAL  
- THERM_WARNING  
- THERM_OVERHEAT  
- THERM_CRITICAL  

---

## 4. Reaction Logic Requirements

### REQ-TRCT-ACT-001
When `ThermalState` is `THERM_NORMAL`, ThermalReaction SHALL request normal operation without any derating or protection actions.

### REQ-TRCT-ACT-002
When `ThermalState` is `THERM_UNDER_TEMP`, ThermalReaction SHALL request limitation of charging power.

### REQ-TRCT-ACT-003
When `ThermalState` is `THERM_WARNING`, ThermalReaction SHALL request thermal derating.

### REQ-TRCT-ACT-004
When `ThermalState` is `THERM_OVERHEAT`, ThermalReaction SHALL request:
- Strong power derating  
- Activation of cooling request  

### REQ-TRCT-ACT-005
When `ThermalState` is `THERM_CRITICAL`, ThermalReaction SHALL request:
- Immediate power shutdown  
- Battery protection action  

---

## 5. Command Output Requirements

### REQ-TRCT-CMD-001
ThermalReaction SHALL generate `DerateCmd` to request reduction of charge and discharge power.

### REQ-TRCT-CMD-002
ThermalReaction SHALL generate `CoolingReq` to request activation of the battery cooling system.

### REQ-TRCT-CMD-003
ThermalReaction SHALL generate `ShutdownReq` when a critical thermal condition is detected.

### REQ-TRCT-CMD-004
ThermalReaction SHALL generate `ContactorCmd` using enumerated type `ContactorCmd_e`.

---

## 6. Derating Strategy Requirements

### REQ-TRCT-DERATE-001
ThermalReaction SHALL apply progressive derating based on the severity of the thermal state.

### REQ-TRCT-DERATE-002
ThermalReaction SHALL ensure derating requests are reversible when thermal conditions return to normal.

---

## 7. Safety & Fallback Requirements

### REQ-TRCT-SAFE-001
If thermal status input data is invalid or unavailable, ThermalReaction SHALL default to a safe reaction state.

### REQ-TRCT-SAFE-002
The safe reaction state SHALL request:
- Power derating  
- Cooling activation  

### REQ-TRCT-SAFE-003
ThermalReaction SHALL prioritize safety over performance under all conditions.

---

## 8. Timing & Execution Requirements

### REQ-TRCT-TIME-001
ThermalReaction SHALL execute cyclically with the same sampling time as ThermalMonitor.

### REQ-TRCT-TIME-002
ThermalReaction SHALL update all command outputs within one execution cycle.

---

## 9. Initialization Requirements

### REQ-TRCT-INIT-001
ThermalReaction SHALL initialize all command outputs to a safe inactive state at system startup.

### REQ-TRCT-INIT-002
ThermalReaction SHALL not issue shutdown or contactor open commands during initialization unless explicitly requested.

---

## 10. Diagnostic & Traceability Requirements

### REQ-TRCT-DIAG-001
ThermalReaction SHALL provide internal status signals for diagnostic and testing purposes.

### REQ-TRCT-DIAG-002
Each reaction logic SHALL be traceable to a corresponding requirement ID.

---

## 11. Safety Classification

### REQ-TRCT-SAFETY-001
ThermalReaction SHALL be developed according to automotive functional safety guidelines.

---