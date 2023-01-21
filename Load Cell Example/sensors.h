#pragma once
//-----Internals------
#include "utility.h"
#include "sensor_struct.h"
//-----Internals------

// Include your sensor libraries here
#include "HX711.h"

namespace sensors {

  // Edit these pins to the ones on your load cell.
  const int LOAD_CELL_DOUT_PIN = 2;
  const int LOAD_CELL_SCK_PIN = 3;

  // Sensor and value definitions.
  long data;
  HX711 scale;

  void init()
  {
    scale.begin(LOAD_CELL_DOUT_PIN, LOAD_CELL_SCK_PIN);
  }

  void tare()
  {
    scale.tare();
  }

  void update()
  {
    // Checks whether or not the device is working properly.
    if (scale.is_ready())
    {
      // Gets and outputs the data to the top graph.
      data = scale.read();
      GRAPH("Value", data, TOP);
    }
    else
    {
      PRINT("ERROR -> HX711 Not found!");
    }
  }

}  // namespace sensors
