# 🛠️ Technical Troubleshooting Guide

This guide covers common compiler errors, hardware communication issues, and upload failures encountered while working with this repository.

---

## 💻 1. Compiler & Library Errors

### ❌ Error: `No such file or directory` (e.g., `DHT.h` or `LiquidCrystal_I2C.h`)
* **Cause:** The sketch requires an external driver library that is not yet installed in your local Arduino IDE workspace.
* **Fix:** 
  1. Open the Arduino IDE.
  2. Navigate to **Tools > Manage Libraries...**
  3. Search for the missing library name (e.g., type "DHT sensor library" or "LiquidCrystal I2C").
  4. Click **Install**, then restart the IDE and verify the sketch again.

### ❌ Error: `expected ';' before '...'`
* **Cause:** A syntax violation where a statement line is missing its terminating semicolon.
* **Fix:** Look closely at the error compiler log box at the bottom of the screen. It will pinpoint the exact line number. Inspect the line directly above it and ensure a semicolon (`;`) is present.

---

## 🔌 2. Hardware Connection & Upload Failures

### ❌ Error: `avrdude: stk500_getsync(): not in sync: resp=0x00`
* **Cause:** The IDE cannot communicate with the microcontroller board chip over the designated USB COM serial channel port.
* **Fix Checklists:**
  * **Incorrect Board Target:** Verify that your current target hardware selection under **Tools > Board** precisely matches the physical hardware chip plugged into your desk (e.g., Arduino Uno vs. Arduino Nano).
  * **Wrong COM Port:** Navigate to **Tools > Port** and ensure you select the active numeric serial port assigned to your plugged-in USB cable (it typically vanishes if you pull the plug out).
  * **Old Bootloader Issues (Arduino Nano Clones):** If you are running an older or generic low-cost Nano board variant, go to **Tools > Processor** and switch the toggle selection over to **"ATmega328P (Old Bootloader)"**.

### ❌ Problem: The Serial Monitor port menu is greyed out completely
* **Cause:** Missing hardware drivers for USB-to-Serial converter chips (like the common CH340G or FTDI chips found on low-cost development boards).
* **Fix:** Search online and download the driver matching your board's converter chip (e.g., "CH340 driver windows/mac"). Install the package, reboot your operating system, and open the IDE again.

---

## 🛑 3. Runtime Code & Behavior Glitches

### ❌ Problem: The board randomly freezes or reboots every few seconds
* **Cause:** The system is falling victim to a hardware reset loop, typically caused by a current surge (short circuit) or the internal hardware watchdog timer trigger (`20_watchdog_timer`).
* **Fix:** Unplug all external jumper links instantly. Double-check your hardware wiring layouts against standard component layouts to ensure a positive line (VCC/5V) isn't accidentally bridging straight into a system Ground plane (GND) channel pin.
