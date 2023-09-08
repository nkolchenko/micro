#include <LiquidCrystal_PCF8574.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Wire.h>

#define SEALEVELPRESSURE_HPA (1014.00)

Adafruit_BME280 bme;
unsigned long delayTime;

LiquidCrystal_PCF8574 lcd(0x3F);
char lcdDisplay[4][20]; 

void setup() {
  Wire.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  delay(10);

  bool status;
  delayTime = 1000;

  lcd.begin(20,4); //Initializes the interface to the LCD screen
  lcd.setBacklight(128); 
  lcd.clear(); //Clears the LCD screen and positions the cursor in the upper-left corner.
  lcd.print("HELLO");
  delay(delayTime);
  lcd.clear();
  status = bme.begin(); 
  if (!status) {
      lcd.print("BME280 NOT FOUND");
      while (1);
    }
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  printValues();
  delay(delayTime);
}

void printValues() {

  lcd.home(); //Positions the cursor in the upper-left of the LCD.
  lcd.print("TEMP: ");
  lcd.print(bme.readTemperature());
  lcd.print(" *C");
  
  lcd.setCursor(0, 1);
  lcd.print("PRESSURE: ");
  lcd.print(bme.readPressure() / 100.0F);
  lcd.print(" hPa");

  lcd.setCursor(0, 2);
  lcd.print("ALTITUDE: ");
  lcd.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  lcd.print(" M");

  lcd.setCursor(0, 3);
  lcd.print("HUMIDITY: ");
  lcd.print(bme.readHumidity());
  lcd.print(" %");
}
