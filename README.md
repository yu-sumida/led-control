# Virtual LED Controller (C language)

For Japanese, see [README_ja.md](./README_ja.md)

## Overview
This is a C program that allows you to control the ON/OFF state of 8 virtual LEDs from the command line.  
The LED states can be saved to and loaded from a file.

## Features
- Control the ON/OFF state of each LED
- Display the current state of all LEDs
- Save and load the LED states from a file
- Input error handling
- Simple command-line user interface

## Commands

| Command | Description                         |
|:-------:|:-----------------------------------|
| `on`    | Turns ON the specified LED (0-7)   |
| `off`   | Turns OFF the specified LED (0-7)  |
| `show`  | Displays the current LED states    |
| `save`  | Saves the current state to a file  |
| `load`  | Loads the LED states from a file   |
| `exit`  | Exits the program                  |

## Example usage

```sh
Enter command: on
Enter LED number (0-7): 3
LED 3 turned ON
Enter command: show
Current LED states: 0 0 0 1 0 0 0 0
Enter command: save
LED states saved to led_control.txt
Enter command: load
LED states loaded from led_control.txt
Enter command: exit
