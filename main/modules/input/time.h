#ifndef TIME_H
#define TIME_H

#include "config.h"  // Inclusion du fichier de configuration
#include "modules.h"  // Inclusion de la classe module_base

#ifdef CONF_TIME_I2C
#include <Wire.h>
#include <RTClib.h>  // Librairie pour gérer le module RTC

class TimeProperties : public module_base {
public:
    TimeProperties();  // Constructeur
    void init() override;  // Initialisation du RTC
    void loop() override;  // Affiche la date et l'heure

private:
    RTC_DS3231 rtc;   // Instance du module RTC
};

#endif  // CONF_TIME_I2C

#ifdef CONF_TIME_GPIO
// Fonction non écrite pour la configuration GPIO
#endif

#endif  // TIME_H
