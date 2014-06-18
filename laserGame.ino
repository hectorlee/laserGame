// laserGame.ino
// This game requires a LDR, laser pointer, LCD shield and an Arduino UNO

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

float startTime;
float endTime;

void setup() {
  lcd.begin(16,2);
  startGame();
}

void loop() {
  showTime();
  if(analogRead(1) > 900) {
    hit();
  }
  delay(10);
  // lcd.clear();
}

void showInstructions() {
  lcd.setCursor(0,0);
  lcd.print("Hit target with");
  lcd.setCursor(0,1);
  lcd.print("a laser pointer");
}

void hit() {
  endTime = millis() - startTime;
  char endTimeAsString[10];
  dtostrf(endTime/1000, 1, 2, endTimeAsString);
  lcd.setCursor(0,0);
  lcd.print("HIT! HIT! HIT!");
  lcd.setCursor(0,1);
  lcd.print("Time: " + String(endTimeAsString));
  delay(5000);
  startGame();
}

void startGame() {
  lcd.clear();
  showInstructions();
  delay(2000);
  lcd.clear();
  lcd.print("Ready");
  delay(1000);
  lcd.clear();
  lcd.print("3");
  delay(1000);
  lcd.clear();
  lcd.print("2");
  delay(1000);
  lcd.clear();
  lcd.print("1");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("START");
  delay(100);
  startTimer();
}

void startTimer() {
  startTime = float(millis());
}

void showTime() {
  lcd.setCursor(0,0);
  char intervalAsString[10];
  float interval = millis() - startTime;
  dtostrf(interval/1000, 1, 2, intervalAsString);
  lcd.print(String(intervalAsString) + " seconds");
}
