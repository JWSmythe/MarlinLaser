/**
-jws 20220127 
This is for the Creality 4.2.7, reconfigured for the laser engraver. I'm
overriding here, rather than making a lot of changes to the other files. It's
cleaner.
(c) 2022 -jws https://jwsmythe.com
*/ 
#pragma once
// ===== Free up pins =========================================================
// -jws 20220130 - Turn off the stock PWM fan on PA0.   It's the one marked
// K-FAN1 and K-FAN2 on the mainboard.  They're actually just to places to
// plug into on the same pin. 
#undef FAN_PIN                        
#define FAN_PIN          PC9

// -jws 20220130 Remapping unused but required devices to unused pins.  
// Marlin requires 4 steppers to be defined, even if we are only using 2.
// By moving them, we can assign the pins to other devices.  Like dual 
// extruders for X or Y.  Our machine has dual Y motors, but they're just
// wired in parallel.  We may split them up later.

// All the steppers share one enable pin, so there's nothing to do with that.
// Step PC8 and PC9 are unused controller pins, not connected to anything.
// We're using PC8 for outputs, and PC9 for inputs.  That's so we don't upset
// the controller by using multiple modes.
// ===== Disabled Outputs ====================================================
// Extruder stepper
#undef E0_STEP_PIN
#define E0_STEP_PIN                    PC8 // was PB4
#undef E0_DIR_PIN
#define E0_DIR_PIN                     PC8 // was PB3
// Z stepper
#undef Z_STEP_PIN
#define Z_STEP_PIN                     PC8 // was PB6
#undef Z_DIR_PIN 
#define Z_DIR_PIN                      PC8 // was PB5

// Extruder
#undef HEATER_0_PIN
#define HEATER_0_PIN                    PC8 // was PA1

// Bed Heater
#undef HEATER_BED_PIN
#define HEATER_BED_PIN                 PC8 // Was PA2
// ===== Disabled Inputs ======================================================
// -jws 20220130 Remapping hotend temp sensors.  It is required if there is an
// extruder, and it won't let us set EXTRUDERS to 0. It is still required, 
// even if TEMP_SENSOR_0 is 999.
#undef TEMP_0_PIN
#define TEMP_0_PIN                     PC9 // was PC5   // TH1

// -jws 20220130 No bed. No bed heater. No thermister. No temperature read.
#undef TEMP_BED_PIN
#define TEMP_BED_PIN                   PC9  // was PC4   // TB1

// ===== Assigning Laser Pins =================================================

// -jws 20220125 LASER_ENA powers the laser.   LASER_PWM is the signal to fire.

// -jws 20220131 - Ports for LASER_ENA 
// Put the laser power on a port (PA1, PA2, or PA0), so you can kill power. 
// If you have a laser with a separate enable pin, you could use pretty much
// any unused pin.
// undef first, in case it was already defined somewhere. 
#undef SPINDLE_LASER_ENA_PIN
//#define SPINDLE_LASER_ENA_PIN   PA0  // PA0 - K-FAN1/K-FAN2
#define SPINDLE_LASER_ENA_PIN   PA1  // PA1 - Hotend Heat
//#define SPINDLE_LASER_ENA_PIN   PA2  // PA2 - Bed Heat
//#define SPINDLE_LASER_ENA_PIN   PC5  // TH1 - Hotend Thermister - Low current pin!


// -jws 20220130 - Ports for LASER_PWM
// undef first, in case it was already defined somewhere. 
#undef SPINDLE_LASER_PWM_PIN
// ----- Bad -----
//#define SPINDLE_LASER_PWM_PIN   PA1   // PA1 - Hotend Heat - A very dirty waveform.  
//#define SPINDLE_LASER_PWM_PIN   PA4   // PA4 - Filament runout - No output at all.
//#define SPINDLE_LASER_PWM_PIN   PC4   // PC4 - Thermister - Bed - No output
//#define SPINDLE_LASER_PWM_PIN   PC5   // PC5 - Thermister - Hotend - No output
// ----- Good -----
//#define SPINDLE_LASER_PWM_PIN   PA0   // Stock fan. 
#define SPINDLE_LASER_PWM_PIN   PB0   // BLTouch IN PWM pin.  The center pin.  Very clean waveform.
//#define SPINDLE_LASER_PWM_PIN   PB1   // BLTouch OUT Trigger pin.  The far right pin.
//#define SPINDLE_LASER_PWM_PIN   PC6   // Clean waveform.  Use the "Pin 27 board" adapter for Ender 3 and CR10, on the LCD connector.
                                        // This is the beeper pin. You will also have to undef BEEPER_PIN.  
                                        // This *will* go active for a second when the machine boots.  Hardware based, not firmware.  
                                        // There's no way to disable it. PC6 *MUST* be used with a real LASER_ENA pin!!!

