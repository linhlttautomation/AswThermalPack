# Battery Thermal Management System (MATLAB/Simulink)

## 1. Introduction

This repository contains a **Battery Thermal Management System (BTMS)** model developed using **MATLAB/Simulink**.  
The project focuses on monitoring and protecting an electric vehicle (EV) battery pack against unsafe thermal conditions.

The design follows a **Monitor–Reaction architecture**, ensuring a clear separation between:
- Thermal condition evaluation (Monitoring)
- Protective and control decision-making (Reaction)

This architecture improves safety, maintainability, and scalability, and aligns with **automotive functional safety concepts (ISO 26262)**.

---

## 2. System Architecture Overview

The high-level architecture of the system is illustrated below:


### Architectural Roles
- **Sensors**: Acquire raw temperature and current measurements
- **ThermalMonitor**: Evaluates battery thermal conditions (no control actions)
- **ThermalReaction**: Determines protective actions based on thermal state
- **Actuators**: Execute physical actions (cooling, heating, isolation)

---

## 3. Project Scope

### In Scope
- Thermal signal monitoring
- Temperature filtering and validation
- Thermal state classification
- Thermal protection decision logic

### Out of Scope
- Detailed battery electrochemical modeling
- Hardware driver implementation
- Vehicle-level energy management

---

## 4. ThermalMonitor Subsystem

### Purpose
The **ThermalMonitor** subsystem is responsible for evaluating the battery thermal condition based on sensor inputs.  
It does **not** perform any control or actuator commands.

### Key Functions
- Sensor validity checking
- Temperature signal filtering
- Temperature gradient calculation
- Thermal state classification

---

### 4.1 Input Interface  
**Bus Name:** `BatteryThermalInput_bus`

| Signal Name | Unit | Description |
|------------|------|-------------|
| CellTempMax | °C | Maximum temperature measured among all battery cells |
| CellTempMin | °C | Minimum temperature measured among all battery cells |
| PackTemp | °C | Average temperature of the battery pack |
| AmbientTemp | °C | Ambient environmental temperature surrounding the battery |
| ChargeCurrent | A | Current flowing into the battery during charging |
| DischargeCurrent | A | Current flowing out of the battery during discharging |
| SensorValid | – | Indicates whether thermal sensor data is valid |

---

### 4.2 Output Interface  
**Bus Name:** `BatteryThermalStatus_bus`

| Signal Name | Description |
|------------|-------------|
| ThermalState | Classified thermal state of the battery pack |
| FilteredTemp | Filtered and stabilized battery temperature |
| TempGradient | Rate of temperature change over time (°C/s) |
| OverTempWarn | Indicates temperature exceeds warning threshold |
| OverTempCrit | Indicates temperature exceeds critical threshold |
| UnderTemp | Indicates temperature below minimum operating limit |
| DerateReq | Request to reduce charging and discharging power |

---

### 4.3 Thermal State Enumeration

**Enum Name:** `ThermalState_e`

| State | Description |
|------|-------------|
| THERM_UNDER_TEMP | Battery temperature below allowed operating range |
| THERM_NORMAL | Battery temperature within normal operating range |
| THERM_WARNING | Battery temperature elevated, approaching unsafe limits |
| THERM_OVERHEAT | Battery temperature exceeds safe operating limit |
| THERM_CRITICAL | Battery temperature dangerously high, immediate protection required |

---

## 5. ThermalReaction Subsystem

### Purpose
The **ThermalReaction** subsystem determines protective and mitigation actions based on the thermal status provided by the ThermalMonitor.

### Key Functions
- State-based decision making
- Thermal protection logic
- Fault latching and hysteresis handling
- Fail-safe behavior implementation

---

### 5.1 Input Interface  
**Bus Name:** `BatteryThermalStatus_bus`

Consumed directly from the ThermalMonitor output.

---

### 5.2 Output Interface  
**Bus Name:** `BatteryThermalCmd_bus`

| Signal Name | Unit | Description |
|------------|------|-------------|
| CoolingFanCmd | – | Command to enable or disable cooling fan |
| PumpSpeedCmd | % | Requested cooling pump speed |
| ChargeCurrentLimit | A | Maximum allowed charging current |
| DischargeCurrentLimit | A | Maximum allowed discharging current |
| BatteryContactorCmd | – | Command to open or close battery contactor |
| BatteryHeaterCmd | – | Command to activate battery heating |
| FaultLatch | – | Latched thermal fault requiring system reset |

---

## 6. Actuators

The actuator layer represents physical components controlled by the system, including:
- Cooling fans
- Cooling pumps
- Battery heaters
- Battery contactors
- Power derating mechanisms

---

## 7. Design Principles

- Clear separation of monitoring and control responsibilities
- Interface-based communication using Simulink Bus objects
- Safety-oriented design with deterministic behavior
- Suitable for Embedded C and AUTOSAR integration
- Scalable and reusable subsystem structure

---

## 8. Tools and Technologies

- MATLAB
- Simulink
- Stateflow
- Embedded Coder (optional)
- System Composer (optional)

---

## 9. Testing and Validation (Planned)

- Model-in-the-Loop (MIL) testing
- Signal fault injection
- Thermal boundary condition testing
- State transition verification

---

## 10. Future Extensions

- AUTOSAR Software Component (SWC) mapping
- Hardware-in-the-Loop (HIL) testing
- Advanced thermal prediction models
- Diagnostic and fault management integration

---

## 11. Conclusion

This project provides a **robust, safety-oriented Battery Thermal Management System model** suitable for automotive and embedded applications.  
By applying a Monitor–Reaction architecture and standardized interfaces, the model ensures clarity, extensibility, and production readiness.

---

## 12. License

This project is intended for educational, research, and internal development purpos
