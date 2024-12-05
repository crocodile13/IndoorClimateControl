// config.h
#ifndef CONFIG_H
#define CONFIG_H

// == LOG MODES ==
#define MODE_SERIAL_DEBUG

// == PLATEFORME ==
// It is not recommended to disable AUTO_PLATEFORME. Better way is edit AUTO_PLATEFORME system in buildConfig.h.
// If you want to disable AUTO_PLATEFORME, you have to manualy define macros like MULTITHREAD, PSEUDO_MULTITHREAD, and others librairies.
#define AUTO_PLATEFORME
#ifndef AUTO_PLATEFORME
    // Example:
    //#define PLATFORM_NAME "ESP32"
    //#define MULTITHREAD // or PSEUDO_MULTITHREAD if not suported
    //include Arduino.h
    // [...]
#endif

/* ========================== */

// == MODULES (NODES) ==

// == CORE ==
#define MODULES

// == INPUT ==

#define INCLUDE_TIME
#ifdef INCLUDE_TIME
//#define CONF_TIME_GPIO
#define CONF_TIME_I2C
#endif
/* ========================== */
#define INCLUDE_DHT22
#ifdef INCLUDE_DHT22
#define CONF_DHT22_GPIO
//#define CONF_DHT22_I2C
#endif
/* ========================== */
//#define INCLUDE_SD
//#ifdef INCLUDE_SD
//#define CONF_SD_GPIO
//#define CONF_SD_I2C
//#endif

// == OUTPUT ==

// == COMPUTE ==
#define PID_INCR


#endif
