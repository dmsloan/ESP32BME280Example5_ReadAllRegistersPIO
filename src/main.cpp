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
const String mDELIMETER = "";    // cordoba add-in expects a comma delimeted string, added for connection to Excel
const int delayRead = 5000;      // Delay between readings
const String SketchName = "Sketch is called ESP32BME280Example5_ReadAllRegistersPIO"; // 
const String Board = "This board is an Adafruit featheresp32";    // change this in the platformio.ini file
float pressure_correction_offset = 0.0;

//Given a value, print it in HEX with leading 0x and any leading 0s
void printyPrintHex(byte value)
{
  Serial.print("0x");
  if (value < 0x10) Serial.print("0");
  Serial.println(value, HEX);
}

void printRegisters()
{
Serial.print("ID(0xD0): ");
  printyPrintHex(mySensor.readRegister(BME280_CHIP_ID_REG));

  Serial.print("Reset register(0xE0): ");
  printyPrintHex(mySensor.readRegister(BME280_RST_REG));

  Serial.print("ctrl_meas(0xF4): ");
  printyPrintHex(mySensor.readRegister(BME280_CTRL_MEAS_REG));

  Serial.print("ctrl_hum(0xF2): ");
  printyPrintHex(mySensor.readRegister(BME280_CTRL_HUMIDITY_REG));

  Serial.println();

  Serial.println("Displaying all regs:");
  byte memCounter = 0x80;
  for (byte row = 8 ; row < 16 ; row++)
  {
    Serial.print("0x");
    Serial.print(row, HEX);
    Serial.print("0:");

    for (byte column = 0 ; column < 16 ; column++)
    {
      byte tempReadData = mySensor.readRegister(memCounter);

      if(tempReadData < 0x10) Serial.print("0");
      Serial.print(tempReadData, HEX);
      Serial.print(" ");

      memCounter++;
    }
    Serial.println();
  }

  Serial.println();

  Serial.println("Reading all registers from first BME280 designated as mySensor at address 0x77");
  Serial.println("Displaying concatenated calibration words:");
  Serial.print("dig_T1, uint16: ");
  Serial.println(mySensor.calibration.dig_T1);
  Serial.print("dig_T2, int16: ");
  Serial.println(mySensor.calibration.dig_T2);
  Serial.print("dig_T3, int16: ");
  Serial.println(mySensor.calibration.dig_T3);

  Serial.print("dig_P1, uint16: ");
  Serial.println(mySensor.calibration.dig_P1);
  Serial.print("dig_P2, int16: ");
  Serial.println(mySensor.calibration.dig_P2);
  Serial.print("dig_P3, int16: ");
  Serial.println(mySensor.calibration.dig_P3);
  Serial.print("dig_P4, int16: ");
  Serial.println(mySensor.calibration.dig_P4);
  Serial.print("dig_P5, int16: ");
  Serial.println(mySensor.calibration.dig_P5);
  Serial.print("dig_P6, int16: ");
  Serial.println(mySensor.calibration.dig_P6);
  Serial.print("dig_P7, int16: ");
  Serial.println(mySensor.calibration.dig_P7);
  Serial.print("dig_P8, int16: ");
  Serial.println(mySensor.calibration.dig_P8);
  Serial.print("dig_P9, int16: ");
  Serial.println(mySensor.calibration.dig_P9);

  Serial.print("dig_H1, uint8: ");
  Serial.println(mySensor.calibration.dig_H1);
  Serial.print("dig_H2, int16: ");
  Serial.println(mySensor.calibration.dig_H2);
  Serial.print("dig_H3, uint8: ");
  Serial.println(mySensor.calibration.dig_H3);
  Serial.print("dig_H4, int16: ");
  Serial.println(mySensor.calibration.dig_H4);
  Serial.print("dig_H5, int16: ");
  Serial.println(mySensor.calibration.dig_H5);
  Serial.print("dig_H6, int8: ");
  Serial.println(mySensor.calibration.dig_H6);

  Serial.println();


  Serial.println();

  Serial.println("Reading all registers from first BME280 designated as mySensor at address 0x77");
  Serial.println("Displaying concatenated calibration words:");
  Serial.print("dig_T1, uint16: ");
  Serial.println(mySensor1.calibration.dig_T1);
  Serial.print("dig_T2, int16: ");
  Serial.println(mySensor1.calibration.dig_T2);
  Serial.print("dig_T3, int16: ");
  Serial.println(mySensor1.calibration.dig_T3);

  Serial.print("dig_P1, uint16: ");
  Serial.println(mySensor1.calibration.dig_P1);
  Serial.print("dig_P2, int16: ");
  Serial.println(mySensor1.calibration.dig_P2);
  Serial.print("dig_P3, int16: ");
  Serial.println(mySensor1.calibration.dig_P3);
  Serial.print("dig_P4, int16: ");
  Serial.println(mySensor1.calibration.dig_P4);
  Serial.print("dig_P5, int16: ");
  Serial.println(mySensor1.calibration.dig_P5);
  Serial.print("dig_P6, int16: ");
  Serial.println(mySensor1.calibration.dig_P6);
  Serial.print("dig_P7, int16: ");
  Serial.println(mySensor1.calibration.dig_P7);
  Serial.print("dig_P8, int16: ");
  Serial.println(mySensor1.calibration.dig_P8);
  Serial.print("dig_P9, int16: ");
  Serial.println(mySensor1.calibration.dig_P9);

  Serial.print("dig_H1, uint8: ");
  Serial.println(mySensor1.calibration.dig_H1);
  Serial.print("dig_H2, int16: ");
  Serial.println(mySensor1.calibration.dig_H2);
  Serial.print("dig_H3, uint8: ");
  Serial.println(mySensor1.calibration.dig_H3);
  Serial.print("dig_H4, int16: ");
  Serial.println(mySensor1.calibration.dig_H4);
  Serial.print("dig_H5, int16: ");
  Serial.println(mySensor1.calibration.dig_H5);
  Serial.print("dig_H6, int8: ");
  Serial.println(mySensor1.calibration.dig_H6);

  Serial.println();

}

void printReadings()
{
  Serial.print("Humidity: ");
  Serial.print(mDELIMETER);
  Serial.print(mySensor.readFloatHumidity(), 0);
  Serial.print(mDELIMETER);

  Serial.print(" Pressure: ");
  Serial.print(mDELIMETER);
  Serial.print(mySensor.readFloatPressure()/100, 2);
  Serial.print(" hPa");
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
  Serial.print(mySensor1.readFloatPressure()/100, 2);
  Serial.print(" hPa");
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
}

void printDiff()
{
  Serial.print("Humidity Diff: ");
  Serial.print(mDELIMETER);
  Serial.print(mySensor.readFloatHumidity()-mySensor1.readFloatHumidity(), 2);
  Serial.print(mDELIMETER);

  Serial.print(" Pressure Diff: ");
  Serial.print(mDELIMETER);
  Serial.print(((mySensor.readFloatPressure()-mySensor1.readFloatPressure())/100)-pressure_correction_offset, 2);
  Serial.print(" hPa  ");
  Serial.print(mDELIMETER);

  Serial.print((((mySensor.readFloatPressure()-mySensor1.readFloatPressure())/100)-pressure_correction_offset)*0.40146, 2);
  Serial.print(" inH2O ");
  Serial.print(mDELIMETER);

  Serial.print(" Alt Diff: ");
  Serial.print(mDELIMETER);
  //Serial.print(mySensor.readFloatAltitudeMeters(), 1);
  Serial.print(mySensor.readFloatAltitudeFeet()-mySensor1.readFloatAltitudeFeet(), 2);
  Serial.print(mDELIMETER);

  Serial.print(" Temp Diff: ");
  Serial.print(mDELIMETER);
  //Serial.print(mySensor.readTempC(), 2);
  Serial.print(mySensor.readTempF()-mySensor1.readTempF(), 2);
  Serial.print(mDELIMETER);
  Serial.println();
  Serial.println();
}

void setup()
{
  Serial.begin(115200);
  while(!Serial); //Needed for printing correctly when using a Teensy
  Serial.println(SketchName);
  Serial.println(Board);
  Serial.println("Reading all registers from first BME280 designated as mySensor at address 0x76");

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

mySensor.setReferencePressure(101770); //given in milibars example 1013.25 is represented as 101325 which is the standard
mySensor1.setReferencePressure(101770);

printRegisters();
}

void loop()
{
  //Each loop, take a reading.
  printReadings();
  printDiff();
  delay(delayRead);
  Serial.print("The reference pressure is ");
  Serial.println(mySensor.getReferencePressure());

  // The following block lets you change the Reference Pressure so the altimiter is more accurate
  if (Serial.available() > 0) {
    char buffer[] = {' ',' ',' ',' ',' ',' '}; // Receive up to 6 bytes
//    while (!Serial.available()); // Wait for characters
    Serial.readBytesUntil('\n', buffer, 7); // \n is a carriage return, buffer is the array to store the bytes in, 6 is the number of bytes to read
    int incomingValue = atoi(buffer);
    Serial.println(incomingValue);
    mySensor.setReferencePressure(incomingValue);
    mySensor1.setReferencePressure(incomingValue);
    Serial.println(mySensor.getReferencePressure());
    Serial.println(mySensor1.getReferencePressure());
    Serial.println(incomingValue);
  }
  // Serial.println(mySensor1.getReferencePressure(),DEC);
  // Serial.println(mySensor1.getReferencePressure(),HEX);
  // Serial.println(mySensor1.getReferencePressure(),OCT);
  // Serial.println(mySensor1.getReferencePressure(),BIN);

}

