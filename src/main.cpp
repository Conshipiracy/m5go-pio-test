#include <M5Stack.h>

void setup() {
  // Initialize M5Stack
  M5.begin();

  // Fill screen with black background
  M5.Lcd.fillScreen(BLACK);

  // Write hello world on the screen
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(50, 50);
  M5.Lcd.print("Hello World!");

  // Draw a circle (x, y, radius, color)
  M5.Lcd.fillCircle(160, 120, 50, RED);
}

void loop() {
    // Required, but empty
}