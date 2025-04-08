# OLED02A Module

The **OLED02A** is MLAB module with a 1.3-inch OLED display with the SH1106 controller.

## Features
- **Display**: 1.3-inch OLED with a resolution of 128x64 pixels.
- **Controller**: SH1106.
- **Interface**: I²C with standard pinout:
  1. `GND`: Ground.
  2. `SDA`: Serial Data.
  3. `3V3`: 3.3V power supply.
  4. `SCL`: Serial Clock.
  5. `GND`: Ground.
- **Power Requirements**: 3.3V supply voltage.
- **Address Configuration**: Default I²C address is `0x3C`. A jumper allows switching to an alternative address of `0x3D`.
- **Mounting**: It can be mounted horizontaly as standard MLAB module. With a 3D-printed holeder, module can be placed vertically.

## Pin Configuration: Standard MLAB I2C
1. `GND`: Ground.
2. `SDA`: Serial Data.
3. `3V3`: 3.3V power supply.
4. `SCL`: Serial Clock.
5. `GND`: Ground.

## I²C Address Selection
The OLED02A module's default I²C address is `0x3C`. To change the address to `0x3D`, connect the onboard jumper.
