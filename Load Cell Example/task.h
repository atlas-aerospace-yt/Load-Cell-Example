#pragma once

//-----Internals------
#include "sensors.h"
#include "actuators.h"
#include "sub_task.h"
#include "utility.h"
#include "sidekick.h"
//-----Internals------

// Tasks go here-- this keeps the main file clean and focused on the "flow" of tasks
// Our general functions will be defined here things like our main loops
// Long sections of code or repeated code loops can be moved to sub_task.h

// The functions in place here can be changed to suit your needs
// The ones listed here serve as inspiration--feel free to change them as you need -- but remember to change your Tasks in main.h
namespace task
{

    // Globals can be defined here
    String process;

    // Can be used for code that only runs once
    // This can also be run multiple times by changing the code flow in main.h
    void Setup()
    {
      sensors::init();
    }

    // Can be used to automatically test actuators
    // Very useful for quick plug and play testing
    void ActuatorTest()
    {
    }

    // Can be used to print sensor values and any other required calibration
    void Calibration()
    {
    }

    // Code that loops
    void Loop()
    {
      process = subtask::update();

      if (process == "tare")
      {
        PRINT("Taring...");
        END_LOG;
        sensors::tare();
        delay(2000);
      }
      if (process == "calibrate")
      {
        PRINT("Calibrating...");
        END_LOG;
        sensors::calibrate();
        delay(1000);
      }
      sensors::update();

      delay(50);

    }

} // namespace task
