#pragma once

/**
 *  Chiron SKR3/SKR3EZ Configuration
 *  Created by Xstasy 
 **/

// Printer's unique ID, used by some programs to differentiate between machines.
// Choose your own or use a service like https://www.uuidgenerator.net/version4
#define MACHINE_UUID "0fa7beef-1337-c0de-4eaa-ca434a2bb00b"

#define DRIVER_TYPE     "TMC2209"   // Driver type :['TMC2209', 'TMC5160', 'A4988', 'A5984', 'DRV8825', 'LV8729', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2160', 'TMC2208', 'TMC26X', 'TMC2660', 'TMC5130']
#define X_DRIVER_TYPE   TMC2209     // X Axis Driver
#define Y_DRIVER_TYPE   TMC2209     // Y Axis Driver
#define Z_DRIVER_TYPE   TMC2209     // Z Axis Left Driver
#define Z2_DRIVER_TYPE  TMC2209     // Z Axis Right Driver (Uses E1)
#define E0_DRIVER_TYPE  TMC2209     // Extruder Driver

// Additional features
//#define FIXED_PROBE               // Enable to use the Chiron Magnetic Probe
#define BLTOUCH                     // Disable to use the fixed/manual probe.
// If both BLTOUCH and FIXED_PROBE is disabled it assumes that you're manually probing.

#define USE_UBL                     // Disable for BBL
#define GRID_SIZE       10          // How many points to probe in each direction? Max 15 for UBL, 9 for BBL, 3 for manual probing.

// The size of the printable area (these settings shouldn't need changing unless linear rails etc)
#define X_MIN_POS -10
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_BED_SIZE 400
#define Y_BED_SIZE 400
#define Z_MAX_POS 455
#define X_MAX_POS X_BED_SIZE + 10
#define Y_MAX_POS Y_BED_SIZE + 10

// Most probes should stay away from the edges of the bed, but
// with NOZZLE_AS_PROBE this can be negative for a wider probing area.
#define PROBING_MARGIN 17

/**
 * 
 *  Chiron SKR3 Configuration end, the rest of the settings below are
 *  Tuned to the original parameters of the original Chiron.
 *  Endstop directions, Motor directions, fans, and the RGB strip has
 *  been enabled (but is optional to use, configured by default for WS2811 BGR)
 *  Bed size has been set and sane defaults for probing and homing.
 **/


/**
 * Serial Port Configuration
 **/

#define BAUD_RATE_GCODE     // Enable G-code M575 to set the baud rate

#define SERIAL_PORT 1
#define BAUDRATE 115200     // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]

#define SERIAL_PORT_2 -1
#define BAUDRATE_2 115200   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]

// Used for TFT Display
#define SERIAL_PORT_3 3
#define BAUDRATE_3 115200   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]


// Temperature sensors
#define TEMP_SENSOR_0   1
#define TEMP_SENSOR_1   1
#define TEMP_SENSOR_BED 1

// Bed max temp
#define BED_MAXTEMP      100

//===========================================================================
//============================= PID Settings ================================
//===========================================================================
#define PIDTEMP          // See the PID Tuning Guide at https://reprap.org/wiki/PID_Tuning

#define BANG_MAX 255     // Limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // Limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#define PID_K1 0.95      // Smoothing factor within any PID loop

#if ENABLED(PIDTEMP)
  //#define PID_DEBUG             // Print PID debug data to the serial port. Use 'M303 D' to toggle activation.
  #define DEFAULT_Kp  20.00
  #define DEFAULT_Ki   0.50
  #define DEFAULT_Kd 106.55
#endif

//===========================================================================
//====================== PID > Bed Temperature Control ======================
//===========================================================================
#define PIDTEMPBED
#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current

#if ENABLED(PIDTEMPBED)
  #define DEFAULT_bedKp   97.10
  #define DEFAULT_bedKi    1.41
  #define DEFAULT_bedKd 1675.16
  // FIND YOUR OWN: "M303 E-1 C8 S90" to run autotune on the bed at 90 degreesC for 8 cycles.
#endif // PIDTEMPBED

//===========================================================================
//============================== Endstop Settings ===========================
//===========================================================================
#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG

// Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
#define X_MIN_ENDSTOP_INVERTING true        // Set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING true        // Set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define I_MIN_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define J_MIN_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define K_MIN_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define U_MIN_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define V_MIN_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define W_MIN_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING true        // Set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define I_MAX_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define J_MAX_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define K_MAX_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define U_MAX_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define V_MAX_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define W_MAX_ENDSTOP_INVERTING false       // Set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING false // Set to true to invert the logic of the probe.

/**
 * Default Axis Steps Per Unit (linear=steps/mm, rotational=steps/°)
 * Override with M92
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 100, 400, 415 }

/**
 * Default Max Feed Rate (linear=mm/s, rotational=°/s)
 * Override with M203
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_FEEDRATE          { 100, 100, 20, 60 }

/**
 * Default Max Acceleration (speed change with time) (linear=mm/(s^2), rotational=°/(s^2))
 * (Maximum start speed for accelerated moves)
 * Override with M201
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_ACCELERATION      { 350, 350, 50, 20000 }

// Junction deviation
#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.018 // (mm) Distance from real junction edge
  #define JD_HANDLE_SMALL_SEGMENTS    // Use curvature estimation instead of just the junction angle
  // for small segments (< 1mm) with large junction angles (> 135°).
#endif

// Nozzle to probe offset
#if ENABLED(BLTOUCH)
  #define NOZZLE_TO_PROBE_OFFSET { -28.2, -3.32, -3.36 }
#else
  #define NOZZLE_TO_PROBE_OFFSET { 0, 0, -17.27 }
#endif

#define MULTIPLE_PROBING 2
#define EXTRA_PROBING    1

#include "Extra.h"