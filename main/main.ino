// main.cpp
#include <Arduino.h>
#include "config.h"
#include "buildConfig.h"

module_heap heap;

void setup() {
    Serial.begin(9600);

#ifdef MODE_SERIAL_DEBUG
    Serial.println("Démarrage des modules...");
#endif

    // Ajouter des modules
    //heap.addModule("nom arbitraire" , <refraichissement en ms> , <new maFonctionSpecifique(arg1,arg2...)> , <executer init a la creation, optionnel, default=true>);
    heap.addModule("dht22_module_1" , 30000 , new mod_DHT22_GPIO(4), true);

    
}

void loop() {
    // Exécuter les modules dans la heap
    heap.execHeap();
    delay(1000); // Pause entre chaque exécution
}
