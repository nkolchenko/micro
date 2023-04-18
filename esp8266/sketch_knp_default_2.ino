#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;
LiquidCrystal_I2C lcd(0x3F, 20, 4);

void setup() {

  lcd.begin();

  // Turn on the backlight.
  lcd.backlight();

  // Move the cursor 5 characters to the right and zero characters down (line 1).
  lcd.setCursor(5, 0);

  // Print HELLO to the screen, starting at 5,0.
  lcd.print("HELLO");

  // Move the cursor to the next line and print
  // WORLD.
  lcd.setCursor(5, 1);
  lcd.print("WORLD");

  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(74880);
  delay(10);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("r2d2-ng", "tcmrjdf!wifi");

  Serial.println();
  Serial.println();
  Serial.print("Looking for a WiFi: ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  lcd.setCursor(2, 3);
  lcd.print(WiFi.localIP());
  delay(500);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED off
  delay(1200);                      // Wait for a 1.2 seconds
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on by making the voltage HIGH
  delay(800);                      // Wait for two seconds
}
