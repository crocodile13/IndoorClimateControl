#include <DHT.h>
#include "modules.h"
#include "input_dht22.h"  // Inclusion du fichier d'en-tête qui contient la déclaration de la classe

// Constructeur
mod_DHT22_GPIO::mod_DHT22_GPIO(int gpioPin)
    : pin(gpioPin), dht(gpioPin, DHT22) {
}

// Méthode d'initialisation
void mod_DHT22_GPIO::init() {
    dht.begin();
#ifdef MODE_SERIAL_DEBUG
    Serial.print(name.c_str());
    Serial.println(" initialisé.");
#endif
}

// Méthode principale pour la boucle de lecture
void mod_DHT22_GPIO::loop() {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
#ifdef MODE_SERIAL_DEBUG
    Serial.print(name.c_str());
    Serial.print(" - Température : ");
    Serial.print(temp);
    Serial.print("°C, Humidité : ");
    Serial.print(hum);
    Serial.println("%");
#endif
}
