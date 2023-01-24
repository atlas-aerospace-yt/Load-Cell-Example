#pragma once
//-----Internals------
#include "utility.h"
#include "sensor_struct.h"
//-----Internals------

// Include your sensor libraries here
#include "HX711.h"

// Definitions to Edit
#define LOAD_CELL_DOUT_PIN 2
#define LOAD_CELL_SCK_PIN 3

#define offset_val 0
#define multiplier_val 1

namespace sensors {

  // Sensor and value definitions.
  long data;
  HX711 scale;

  // Sensor calibration definitions
  float cal_reading = 0;
  float offset = offset_val;
  float multiplier = multiplier_val;

  // User input definitions
  int input_char;
  int cal_input = -123;
  String cal_string = "";

  void init()
  {
    scale.begin(LOAD_CELL_DOUT_PIN, LOAD_CELL_SCK_PIN);
  }

  void tare()
  {
    cal_reading = 0;

    if (scale.is_ready())
    {
      cal_reading = scale.read();
    }

    offset = -cal_reading;
  }

  void calibrate()
  {
    tare();

    PRINT("Enter the mass of the object on the load cell --> grams");
    END_LOG;

    while (true)
    {
      while (Serial.available() > 0)
      {
        input_char = Serial.read();
        if (isDigit(input_char)) {
          cal_string += (char)input_char;
        }
      }

      if (cal_string != "")
      {
        cal_input = cal_string.toInt();
        cal_string = "";
        break;
      }
    }

    PRINT("Calibrating for: ")
    PRINT(cal_input);
    PRINT("g");
    END_LOG;

    cal_reading = 0;

    if (scale.is_ready())
    {
      cal_reading = scale.read() + offset;
    }

    if (cal_reading != 0)
    {
      multiplier = cal_input / cal_reading;
      PRINT("Offset: ");
      PRINT(offset);
      PRINT(", Multiplier: ");
      PRINT(multiplier);
      END_LOG;
    }
    else
    {
      PRINT("Error: No mass on the scale");
      END_LOG;
    }
  }

  void update()
  {
    // Checks whether or not the device is working properly.
    if (scale.is_ready())
    {
      // Gets and outputs the data to the top graph.
      data = (scale.read() + offset) * multiplier;
      GRAPH("Value", data, TOP);
    }
    else
    {
      PRINT("No HX711 detected.");
    }
  }
}  // namespace sensors
