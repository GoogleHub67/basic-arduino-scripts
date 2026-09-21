# 🤖 Master Arduino Basics Collection

A professional, production-ready framework repository containing **26 essential Arduino firmware templates**. This collection scales from basic digital I/O structures up to advanced bare-metal register optimizations, low-level timing controls, and memory diagnostic tracking.

---

## 📁 Repository Directory Architecture
The codebase is cleanly split into two core divisions to maintain industry standards:
* **`src/`**: Houses all 26 functional sketches. Each `.ino` file is kept inside its mandatory matching folder block to ensure flawless compilation.
* **`docs/`**: Holds helper manuals, error references, and architecture documentation.

```text
basic-arduino-scripts/
├── .gitignore
├── .gitattributes
├── LICENSE
├── README.md
├── docs/
│   ├── faqs.md
│   └── troubleshooting.md
└── src/
    ├── 01_blink/
    ├── 02_button_led/
    └── ... (all 26 folder modules)
```

---

## 🚀 Getting Started & Deployment

1. **Install Software**: Download and install the latest [Arduino IDE](https://arduino.cc).
2. **Download Repository**: Clone this workspace to your desktop machine:
   ```bash
   git clone https://github.com/GoogleHub67/basic-arduino-scripts
   ```
3. **Open Sketches**: Open the `src/` directory, choose any target project folder, and double-click the inner `.ino` file to auto-launch the IDE environment workspace.
4. **Fix Missing Dependencies**: If a script throws a compilation warning, consult the guide inside [docs/troubleshooting.md](docs/troubleshooting.md).

---

## 📊 Master Template Index

| Directory / Folder Name | Level | Primary Concepts & Protocols Covered |
| :--- | :--- | :--- |
| **`01_blink`** | 🟢 Level 1 | Digital Pin Output, `digitalWrite()`, Standard Time Delays |
| **`02_button_led`** | 🟢 Level 1 | Digital Inputs, Hardware Pull-up Resistors (`INPUT_PULLUP`) |
| **`03_serial_print`** | 🟢 Level 1 | UART Serial Diagnostics, Data Logs, Baud Rate Configurations |
| **`04_analog_read`** | 🟢 Level 1 | Analog-to-Digital Conversion (ADC), Potentiometers, Voltage Math |
| **`05_pwm_fade`** | 🟢 Level 1 | Pulse Width Modulation (PWM) Dimming, `analogWrite()`, Loop Arrays |
| **`06_servo_sweep`** | 🟡 Level 2 | Servo Hardware Control, Library Integrations (`<Servo.h>`) |
| **`07_ultrasonic_ranger`**| 🟡 Level 2 | Distance Math, High-Speed Pulse In Timing, Acoustic Telemetry |
| **`08_dht_temp_humidity`**| 🟡 Level 2 | Environmental Telemetry Sensors, External Core Drivers |
| **`11_i2c_lcd`** | 🟡 Level 2 | Inter-Integrated Circuit (I2C) Communication Bus, Display Matrices |
| **`09_millis_no_delay`** | 🔵 Level 3 | Non-blocking Concurrency Systems, Time Deltas via `millis()` |
| **`10_state_machine`** | 🔵 Level 3 | Finite State Machine (FSM) Architectures, System Control Engines |
| **`15_string_parsing`** | 🔵 Level 3 | Data Stream Parsing, Data Extraction, Input Buffer Filtering |
| **`19_array_moving_average`**| 🔵 Level 3 | Digital Signal Smoothing Filters, Circular Shift Arrays |
| **`23_circular_buffer`** | 🔵 Level 3 | Memory-Safe Data Buffering, Prevention of Buffer Overflows |
| **`12_eeprom_save`** | 🎛️ Level 4 | Non-Volatile Memory (EEPROM), Preserving State Across Reboots |
| **`13_software_serial`** | 🎛️ Level 4 | Emulating Virtual Serial UART Lines via Generic Software Pins |
| **`14_interrupt_button`**| 🎛️ Level 4 | Hardware-Level Pin Interrupt Handling, Instant Task Preemption |
| **`16_low_power_sleep`** | 🎛️ Level 4 | Low-Power Battery Management Modes, System Standby Control |
| **`17_analog_write_pseudo`**| 🎛️ Level 4 | Manual Microsecond Signal Modulation Without Software Libraries |
| **`18_spi_eeprom_external`**| 🎛️ Level 4 | Serial Peripheral Interface (SPI) High-Speed Hardware Buses |
| **`20_watchdog_timer`** | 🎛️ Level 4 | Hardware Watchdog Safeties, Anti-Freeze / Automatic Recovery |
| **`21_pid_controller`** | 🎛️ Level 4 | Proportional-Integral-Derivative Real-Time Math Feedback Loops |
| **`22_rotary_encoder`** | 🎛️ Level 4 | Rotational Dials, Quad-State Logic Tracking, Phase Changes |
| **`24_direct_port_manipulation`**| 🎛️ Level 4 | Bare-Metal Port Registry Override, 1-Clock Cycle Pin Switching |
| **`25_timer_interrupts`**| 🎛️ Level 4 | Precision Internal Clock Register Configurations (Timer1 CTC) |
| **`26_heap_fragmentation_check`**| 🎛️ Level 4 | SRAM Heap Integrity Monitoring, Run-Time Memory Leak Auditing |

---

## 🛠️ Recommended Core Hardware Inventory
To test all applications within this master collection successfully, the following elements are recommended:
* **Microcontroller**: Arduino Uno R3, Nano, or fully compatible ATmega328P development board.
* **Input Elements**: Push-Buttons, 10k-ohm Potentiometers, Rotary Encoders.
* **Actuators & Displays**: Standard LEDs, 5V Hobby Servos, 16x2 I2C Character LCD Modules.
* **Sensor Nodes**: HC-SR04 Ultrasonic modules, DHT11 or DHT22 Temperature modules.
* **Passive Kit**: Solderless Breadboards, Jumper Wires, 220-ohm and 10k-ohm current-limiting resistors.

---

## 📜 Open Source Licensing
This repository is licensed under the terms of the open-source **MIT License**. You are free to copy, modify, distribute, and apply these scripts within personal, academic, or commercial embedded firmware environments. See the `LICENSE` file for details.
