#include "config.h"

//CORE
//#include "modules.h"  // Inclut la classe module_base

// gestions automatiques des headers specifiques en fonction de la plateforme
#ifdef AUTO_PLATEFORME
    #ifdef ESP32
        #define PLATFORM_NAME "ESP32"
        #define MULTITHREAD
    #elif defined(ESP8266)
        #define PLATFORM_NAME "ESP8266"
        #define PSEUDO_MULTITHREAD
    #elif defined(ARDUINO)
        #define PLATFORM_NAME "Arduino"
        #define PSEUDO_MULTITHREAD
    //#elif defined(__linux__)
    //    #define PLATFORM_NAME "Raspberry Pi"
    #else
        #error "Unsupported platform"
    #endif
#endif



#ifdef INCLUDE_TIME
    #include "time.h"
#endif

//#ifdef INCLUDE_SENSOR
//    #include "sensor.h"
//#endif
  
#ifdef INCLUDE_DHT22
    #include "input_dht22.h"
#endif
