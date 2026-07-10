#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SENSOR_PIN A0
#define GREEN_LED 5
#define BUZZER 2
#define RED_LED 3
#define RELAY 4

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int THRESHOLD = 400;
const int BEEP_DELAY = 300;

bool buzzerOn = false;
unsigned long lastBeepTime = 0;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAY, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("ALCOHOL DETECTOR");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();

  Serial.println("System Ready");
}

void loop() {

  int sensorValue = analogRead(SENSOR_PIN);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // Alcohol detected
  if (sensorValue >= THRESHOLD) {
    
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
delay(2000);
    // Turn ON relay (fan runs)
    digitalWrite(RELAY, LOW);

    // Beeping buzzer
    if (millis() - lastBeepTime >= BEEP_DELAY) {
      lastBeepTime = millis();
      buzzerOn = !buzzerOn;
      digitalWrite(BUZZER, buzzerOn);
    }

    lcd.setCursor(0, 0);
    lcd.print("!! ALERT !!     ");
    lcd.setCursor(0, 1);
    lcd.print("ALCOHOL FOUND   ");

    Serial.println("Alcohol Detected - Fan ON");

  }

  // Safe condition
  else {

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    delay(2000);

    // Turn OFF relay (fan stops)
    digitalWrite(RELAY, HIGH);

    digitalWrite(BUZZER, LOW);
    buzzerOn = false;

    lcd.setCursor(0, 0);
    lcd.print("STATUS: SAFE    ");
    lcd.setCursor(0, 1);
    lcd.print("ALCOHOL: NONE   ");

    Serial.println("Safe - Fan OFF");
  }
}