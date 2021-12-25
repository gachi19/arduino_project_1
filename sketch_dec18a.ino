#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  Serial.begin(9600);
}

void loop() {
  float T = analogRead(A0);
  float H = analogRead(A1);

  lcd.backlight();
  lcd.display();
  lcd.print("T: ");
  lcd.print( -66.875 + 218.75 * T / 1024);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("H: ");
  lcd.print( -12.5 + 125 * H / 1024);
  lcd.print("%");
  
  Serial.print("T: ");
  Serial.print( -66.875 + 218.75 * T / 1024);
  Serial.print("C");
  Serial.print("\tH: ");
  Serial.print( -12.5 + 125 * H / 1024);
  Serial.println("%");
  delay(100); //1초마다 Refresh
  lcd.clear();
}
