#ifndef DHT22_H
#define DHT22_H
#include "modules.h"  // Inclut la classe module_base
#include <DHT.h>       // Librairie DHT pour Arduino

#ifdef CONF_DHT22_GPIO

class mod_DHT22_GPIO : public module_base {
private:
    int pin;           // Pin GPIO connecté au capteur DHT22
    DHT dht;           // Instance de la classe DHT pour gérer le capteur

public:
    // Constructeur
    mod_DHT22_GPIO(int gpioPin);  // Utilisation de String

    // Méthodes héritées
    void init() override; // Méthode d'initialisation
    void loop() override; // Méthode principale pour le traitement en boucle
};

#elif defined(CONF_DHT22_I2C)
// Fonction non écrite ...

#else
#warning "Aucune configuration valide pour DHT22 n'a été définie."
#endif

#endif
