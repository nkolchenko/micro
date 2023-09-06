# esp8266

Some sketches/scripts/etc I did for my Lolin ESP8266 NodeMCU v3 dev-board. 

The fastest and easiest way to proceed with it is to: 
* install CH340G driver from https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver
* install [Arduino IDE](
http://arduino.esp8266.com/stable/package_esp8266com_index.json) :) and insert Link for .json NodeMCU package files
from this [how-to](http://www.instructables.com/id/Programming-ESP8266-ESP-12E-NodeMCU-Using-Arduino-/).

I'm using I2C 4x20 display module based on PCF8574AT IC2 convertor (i2c address is 0x3F) . 5 volts 
If you have a PCF8574AT IC2, Adress is 0x3F, for those who have a problem with not seeing anything. To find your number look at the black CHIP of the IC2.
PCF8574 -> address 0x20
PCF8574A - > address 0x38
PCF8574AT -> address 0x3F

# raspberry

Set of small scripts for Raspberry Pi and different sensors/addons
