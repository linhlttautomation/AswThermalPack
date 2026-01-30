# SWE1 REQUIREMENTS – ThermalMonitor (ThermalMon)

---

## 1. Scope

The ThermalMonitor component is responsible for monitoring battery thermal conditions and providing a classified thermal status to downstream components.

ThermalMonitor SHALL not perform any control or actuator commands.

---

## 2. Interface Requirements

### REQ-TMON-IF-001
ThermalMonitor SHALL receive battery thermal input signals via `BatteryThermalInput_bus`.

### REQ-TMON-IF-002
ThermalMonitor SHALL output thermal status information via `BatteryThermalStatus_bus`.

### REQ-TMON-IF-003
ThermalMonitor SHALL use enumerated data type `ThermalState_e` for thermal state output.

---

## 3. Sensor Validation Requirements

### REQ-TMON-SENS-001
ThermalMonitor SHALL validate all thermal sensor inputs using `SensorValid`.

### REQ-TMON-SENS-002
If `SensorValid` is FALSE, ThermalMonitor SHALL set `ThermalState` to `THERM_CRITICAL`.

### REQ-TMON-SENS-003
If sensor data is invalid, ThermalMonitor SHALL set `DerateReq` to TRUE.

---

## 4. Temperature Processing Requirements

### REQ-TMON-TEMP-001
ThermalMonitor SHALL use `CellTempMax` as the primary safety temperature reference.

### REQ-TMON-TEMP-002
ThermalMonitor SHALL apply a low-pass filter to the selected temperature signal.

### REQ-TMON-TEMP-003
The filtered temperature SHALL be output as `FilteredTemp`.

### REQ-TMON-TEMP-004
ThermalMonitor SHALL calculate the temperature gradient (`TempGradient`) based on the filtered temperature.

---

## 5. Thermal State Classification Requirements

### REQ-TMON-STATE-001
ThermalMonitor SHALL classify battery thermal condition into one of the following states:
- THERM_UNDER_TEMP  
- THERM_NORMAL  
- THERM_WARNING  
- THERM_OVERHEAT  
- THERM_CRITICAL  

### REQ-TMON-STATE-002
ThermalMonitor SHALL set `THERM_UNDER_TEMP` when filtered temperature is below the minimum operating threshold.

### REQ-TMON-STATE-003
ThermalMonitor SHALL set `THERM_NORMAL` when filtered temperature is within the normal operating range.

### REQ-TMON-STATE-004
ThermalMonitor SHALL set `THERM_WARNING` when filtered temperature exceeds the warning threshold.

### REQ-TMON-STATE-005
ThermalMonitor SHALL set `THERM_OVERHEAT` when filtered temperature exceeds the overheat threshold.

### REQ-TMON-STATE-006
ThermalMonitor SHALL set `THERM_CRITICAL` when filtered temperature exceeds the critical threshold.

---

## 6. Flag Generation Requirements

### REQ-TMON-FLAG-001
ThermalMonitor SHALL set `OverTempWarn` to TRUE when `ThermalState` is `THERM_WARNING` or higher.

### REQ-TMON-FLAG-002
ThermalMonitor SHALL set `OverTempCrit` to TRUE when `ThermalState` is `THERM_CRITICAL`.

### REQ-TMON-FLAG-003
ThermalMonitor SHALL set `UnderTemp` to TRUE when `ThermalState` is `THERM_UNDER_TEMP`.

### REQ-TMON-FLAG-004
ThermalMonitor SHALL set `DerateReq` to TRUE when `ThermalState` is `THERM_OVERHEAT` or higher.

---

## 7. Timing & Execution Requirements

### REQ-TMON-TIME-001
ThermalMonitor SHALL execute cyclically with a configurable sampling time.

### REQ-TMON-TIME-002
ThermalMonitor SHALL update all output signals within one execution cycle.

---

## 8. Initialization Requirements

### REQ-TMON-INIT-001
ThermalMonitor SHALL initialize `ThermalState` to `THERM_NORMAL` at system startup, provided sensor data is valid.

### REQ-TMON-INIT-002
ThermalMonitor SHALL initialize all output flags to FALSE at system startup.

---

## 9. Safety Requirements

### REQ-TMON-SAFE-001
ThermalMonitor SHALL default to a safe state when unexpected or
