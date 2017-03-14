#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int led = 13;
int buzzer = 7;
int MQ2 = A0;
int MQ135 = A1;
int Relay = 10;


void setup()
{
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);
  pinMode(MQ2, INPUT);
  pinMode(MQ135, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("ARDUINO UNO AIR ");
  lcd.setCursor(0, 1);
  lcd.print(" MONITOR SHEILD ");
  delay(750);
  lcd.clear();
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
  pinMode(Relay, 10);
  digitalWrite(Relay, LOW);
}

void loop()
{
  lcd.clear();
  float MQ135_volt;
  float MQ2_volt;
  float RS_CO2;
  float R0;
  float Slope;
  float Y_intercept;
  float MQ135Value = (analogRead(MQ135));
  float MQ2Value = (analogRead(MQ2));
  float Y_Value;
  MQ135_volt = MQ135Value * (5.0 / 1023.0);
  MQ2_volt = MQ2Value * (5.0 / 1023.0);
  RS_CO2 = ((5.0 * 32850) / MQ135_volt) - 32850;
  R0 = 28399;
  Slope = -0.370955166;
  Y_intercept = 0.7597917824;
  Y_Value = RS_CO2 / R0;

  double ppm = pow(10, (log10(Y_Value) - Y_intercept) / Slope);
  lcd.setCursor(0, 0);
  lcd.print("CO2 =");
  lcd.setCursor(6, 0);
  lcd.print(ppm);
  lcd.setCursor(13, 0);
  lcd.print("ppm");
  lcd.setCursor(0, 1);
  lcd.print("LPG =");

  if   (MQ2_volt >= 2.10)
  {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(Relay, HIGH);
    lcd.setCursor(6, 1);
    lcd.print(" Detected  ");
    delay(2000);
  }
  if   ( ppm >= 600)
  {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(Relay, HIGH);
    lcd.setCursor(6, 1);
    lcd.print("NO LEAKAGE");
    delay(2000);
  }
  else
  { digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(Relay, LOW);
    lcd.setCursor(6, 1);
    lcd.print("NO LEAKAGE");
  }
  delay(1000);
}
