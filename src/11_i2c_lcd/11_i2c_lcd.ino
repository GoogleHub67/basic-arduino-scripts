// Prints textual values to an 16x2 LCD character matrix using I2C bus lines
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set address to 0x27

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); // Column 0, Row 0
  lcd.print("Hello GitHub!");
  lcd.setCursor(0, 1); // Column 0, Row 1
  lcd.print("System Active");
}

void loop() {
  // Display remains static
}
