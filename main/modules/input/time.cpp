#include "time.h"  // Inclusion du fichier d'en-tête de la classe TimeProperties

// Constructeur
TimeProperties::TimeProperties() : rtc() {
    // Initialiser ici si nécessaire
}

// Méthode pour initialiser le RTC
void TimeProperties::init() {
    if (!rtc.begin()) {
#ifdef MODE_SERIAL_DEBUG
        Serial.println("Couldn't find RTC");
#endif
    }
}

// Méthode pour imprimer l'heure et la date
void TimeProperties::loop() {
    DateTime now = rtc.now();
#ifdef MODE_SERIAL_DEBUG
    Serial.print("Date: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    
    Serial.print(" Time: ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    
    Serial.println();
#endif
}
