#!/usr/bin/python3

import time
import lcd_i2c
import board
import busio
import adafruit_bme280
#from datetime import datetime

i2c = busio.I2C(board.SCL, board.SDA)
bme280 = adafruit_bme280.Adafruit_BME280_I2C(i2c)

def main():
    # Main program block

    # Initialise display
    lcd_i2c.lcd_init()

    while True:
        temp = bme280.temperature
        humidity = bme280.humidity

        # Send to LCD
        lcd_i2c.lcd_string("Temperature: "+"{:.1f}".format(temp)+" C", lcd_i2c.LCD_LINE_1)
        lcd_i2c.lcd_string("Humidity: "+"{:.1f}".format(humidity)+" %", lcd_i2c.LCD_LINE_2)

        time.sleep(3)

if __name__ == '__main__':

  try:
    main()
  except KeyboardInterrupt:
    pass
  finally:
    lcd_i2c.lcd_byte(0x01, LCD_CMD)

