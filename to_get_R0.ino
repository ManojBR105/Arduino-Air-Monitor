
#include"LiquidCrystal.h"


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
lcd.begin(16,2);
Serial.begin(9600);
}

void loop() {
  float sensor1_volt;
  float Rs_CO2;
  float R0;
  float sensorValue;
  float sensor0_volt;
  sensorValue = (analogRead(A1));
  sensor1_volt = sensorValue*(5.0/1023.0);
  Rs_CO2 = ((5.0*32850)/sensor1_volt)-32850;
  R0 = Rs_CO2/0.6230805382;
  sensor0_volt = (analogRead(A0))*(5.0/1023);
  Serial.print(sensor0_volt);
  Serial.print("    ");  
  Serial.print(sensor1_volt);
  Serial.print("    ");
  Serial.print(analogRead(A1));
  Serial.print("    ");
  Serial.print("R0 = ");
  Serial. println(R0);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("R0 =");
  lcd.setCursor(5,0);
  lcd.print(R0);
  lcd.setCursor(0,1);
  lcd.print("V1=");
  lcd.setCursor(4,1);
  lcd.print(sensor1_volt);
  lcd.setCursor(8,1);
  lcd.print("V2=");
  lcd.setCursor(12,1);
  lcd.print(sensor0_volt);
  
  
  }
// put your main code here, to run repeatedly:


