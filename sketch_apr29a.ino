#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define FLAME_SENSOR A0
#define SMOKE_SENSOR A1
#define WATER_SENSOR A2
#define RAIN_SENSOR A3

#define BUZZER_FLAME 3
#define BUZZER_SMOKE 4



LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(FLAME_SENSOR, INPUT);
  pinMode(SMOKE_SENSOR, INPUT);
  pinMode(WATER_SENSOR, INPUT);
  pinMode(RAIN_SENSOR, INPUT);
  pinMode(BUZZER_FLAME, OUTPUT);
  pinMode(BUZZER_SMOKE, OUTPUT)

  // Animated Welcome Message
  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("Smart Home!");
  delay(2000);
}

void loop() {
  float temperature = DHT.readTemperature();
  float humidity = DHT.readHumidity();

  int flameValue = analogRead(FLAME_SENSOR);
  int smokeValue = analogRead(SMOKE_SENSOR);
  int waterValue = analogRead(WATER_SENSOR);
  int rainValue = analogRead(RAIN_SENSOR);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 2);
  lcd.print("Flame: ");
  lcd.print(flameValue);

  lcd.setCursor(0, 3);
  lcd.print("Smoke: ");
  lcd.print(smokeValue);

  lcd.setCursor(0, 4);
  lcd.print("Water: ");
  lcd.print(waterValue);

  lcd.setCursor(0, 5);
  lcd.print("Rain: ");
  lcd.print(rainValue);

  // Check flame sensor
  if (flameValue > 500) {
    digitalWrite(BUZZER_FLAME, HIGH);
  } else {
    digitalWrite(BUZZER_FLAME, LOW);
  }

  // Check smoke sensor
  if (smokeValue > 500) {
    digitalWrite(BUZZER_SMOKE, HIGH);
  } else {
    digitalWrite(BUZZER_SMOKE, LOW);
  }

  delay(2000); // Update every 2 seconds
}
