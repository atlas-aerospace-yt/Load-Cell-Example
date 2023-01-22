# Load Cell Example

This repository contains an example code for interfacing with a load cell sensor using the HX711 amplifier module. The code is written in C++, and is designed to work with most types of load cells that use the HX711 module.

## Features

Calibration of the load cell.
Reading the weight from the sensor.
Serial output of the weight.
Written based off of the [ConsciOS](https://github.com/OrionAerospaceYT/ConsciOS) code base.

## Getting Started

Connect the load cell to the HX711 amplifier module using LOAD_CELL_DOUT_PIN=2 and LOAD_CELL_SCK_PIN=3
Upload the code to your board.
Data should show on the terminal (assuming you are using the [SideKick GUI](https://github.com/OrionAerospaceYT/SideKick).
To calibrate the sensor:
- remove all mass from the scale
- send "calibrate" through terminal
- put a known mass on the scale
- send the mass through terminal
- To keep these settings edit the 
To tare just send "tare" through terminal.

## Dependencies

[SideKick GUI](https://github.com/OrionAerospaceYT/SideKick)
HX711 library

## Contributing

If you want to contribute to this project, please fork the repository and submit a pull request.
