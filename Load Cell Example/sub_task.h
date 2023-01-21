#pragma once

#include "utility.h"

// This is where we place long functions or repeated code
/*Say hypothetically you have a filtering process you apply to your data 10
times for a loop (its a hypothetical) you might do that in here to keep the
task.h file cleaner
*/
namespace subtask {

  // sub_task definitions
  String user_input;

  String update()
  {
    if (Serial.available())
    {
      user_input = Serial.readString();
      user_input.trim();

      return user_input;
    }
    return "";
  }

}  // namespace subtask
