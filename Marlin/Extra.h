#pragma once

// Author info of this build printed to the host during boot and M115
#define STRING_CONFIG_H_AUTHOR "(Xstasy)" // Who made the changes.

// Name displayed in the LCD "Ready" message and Info menu
#if ENABLED(BLTOUCH)
  #define PROBE_TYPE "BLTouch"
  #if ENABLED(USE_UBL)
    #define MESH_TYPE "UBL"
  #else
    #define MESH_TYPE "BBL"
  #endif
#elif ENABLED(FIXED_PROBE) 
  #define PROBE_TYPE "Fixed Probe"
  #define MESH_TYPE "BBL"
#else
  #define PROBE_TYPE "Manual Probe"
  #define MESH_TYPE "MBL"

#endif

#if MB(BTT_SKR_V3_0_EZ)
  #define EZ "EZ"
#else
  #define EZ ""
#endif

#define PRINTER_NAME "Chiron SKR3" EZ " " DRIVER_TYPE " " MESH_TYPE " " PROBE_TYPE
#define CUSTOM_MACHINE_NAME PRINTER_NAME