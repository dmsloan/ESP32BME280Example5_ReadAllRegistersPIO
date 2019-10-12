#include <Arduino.h>

/*
  Read all the regigsters of the BME280
  BME280 Arduino and Teensy example
  Marshall Taylor @ SparkFun Electronics
  May 20, 2015

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14348 - Qwiic Combo Board
  https://www.sparkfun.com/products/13676 - BME280 Breakout Board

  This example outputs all the functional registers from the BME280. This can be handy
  for troubleshooting.

  This sketch configures the BME280 to read all measurements.  The sketch also
  displays the BME280's physical memory and what the driver perceives the
  calibration words to be.
*/

#include <Wire.h>

#include <SparkFunBME280.h>
BME280 mySensor;
BME280 mySensor1;

// Constants that appear in the serial message.
const String mDELIMETER = ",";            // cordoba add-in expects a comma delimeted string

//Given a value, print it in HEX with leading 0x and any leading 0s
void printyPrintHex(byte value)
{
  Serial.print("0x");
  if (value < 0x10) Serial.print("0");
  Serial.println(value, HEX);
}

void setup()
{
  Serial.begin(115200);
  while(!Serial); //Needed for printing correctly when using a Teensy
  Serial.println("Sketch is called ESP32BME280Example5_ReadAllRegistersPIO");

  Wire.begin();
  
    //***BME280/BMP280 Driver settings********************************//
    //commInterface can be I2C_MODE or SPI_MODE
    //specify chipSelectPin using arduino pin names
    //specify I2C address.  Can be 0x77(default) or 0x76
  mySensor.settings.I2CAddress = 0x76; //six lead purple board address, sensor is a BMP280 that does NOT have Humidity
  mySensor1.settings.I2CAddress = 0x77; //six lead purple board address, sensor is a BMP280 that does NOT have Humidity
  //mySensor.settings.I2CAddress = 0x76; //four lead purple board address, sensor is a BME280 that DOES have Humidity

  if (mySensor.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The 0 sensor did not respond. Please check wiring.");
    while (1); //Freeze
  }

  if (mySensor1.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The 1 sensor did not respond. Please check wiring.");
    while (1); //Freeze
  }

}

void loop()
{
  //Each loop, take a reading.
  Serial.print(mDELIMETER);
  Serial.print("Humidity: ");
  Serial.print(mDELIMETER);
  Serial.print(mySensor.readFloatHumidity(), 0);
  Serial.print(mDELIMETER);

  Serial.print(" Pressure: ");
  Serial.print(mDELIMETER);
  Serial.print(mySensor.readFloatPressure(), 0);
  Serial.print(mDELIMETER);

  Serial.print(" Alt: ");
  Serial.print(mDELIMETER);
  //Serial.print(mySensor.readFloatAltitudeMeters(), 1);
  Serial.print(mySensor.readFloatAltitudeFeet(), 1);
  Serial.print(mDELIMETER);

  Serial.print(" Temp: ");
  Serial.print(mDELIMETER);
  //Serial.print(mySensor.readTempC(), 2);
  Serial.print(mySensor.readTempF(), 2);
  Serial.print(mDELIMETER);

  Serial.print("   Humidity1: ");
  Serial.print(mDELIMETER);
  Serial.print(mySensor1.readFloatHumidity(), 0);
  Serial.print(mDELIMETER);

  Serial.print(" Pressure1: ");
  Serial.print(mDELIMETER);
  Serial.print(mySensor1.readFloatPressure(), 0);
  Serial.print(mDELIMETER);

  Serial.print(" Alt1: ");
  Serial.print(mDELIMETER);
  //Serial.print(mySensor.readFloatAltitudeMeters(), 1);
  Serial.print(mySensor1.readFloatAltitudeFeet(), 1);
  Serial.print(mDELIMETER);

  Serial.print(" Temp1: ");
  Serial.print(mDELIMETER);
  //Serial.print(mySensor.readTempC(), 2);
  Serial.print(mySensor1.readTempF(), 2);
  Serial.print(mDELIMETER);

  Serial.println();

  delay(1000);
}

