
#include<LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // set your LCD connections

void setup() {
lcd.begin(16,2);  // start displaying on lcd
Serial.begin(9600);   // start displaying on serial monitor
}

void loop() {
  float sensor1_volt;  // MQ135 analog input voltage
  float Rs_CO2;     // Rs for 400ppm of CO2(current concentration of CO2 in air)
  float R0;        
  float sensorValue;    // analog readiing of MQ135
  float sensor0_volt;   // MQ2 analog input voltage
  sensorValue = (analogRead(A1));  // MQ135 analog reading in pin A1 of the arduino
  sensor1_volt = sensorValue*(5.0/1023.0);  // corresponding calculation.
  Rs_CO2 = ((5.0*32850)/sensor1_volt)-32850;  // calculation
  R0 = Rs_CO2/0.6230805382;  //   calculation
  sensor0_volt = (analogRead(A0))*(5.0/1023);  // calculation
  Serial.print("V2 =");
  Serial.print(sensor0_volt);
  Serial.print(", V1=");  
  Serial.print(sensor1_volt);
  Serial.print("    ");
  Serial.print(analogRead(A1));
  Serial.print("    ");
  Serial.print("R0 = ");
  Serial. println(R0);
 
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
  delay(1000);
  
  }
