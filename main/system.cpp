/*

#ifndef SYSTEM
#define SYSTEM

#include <Arduino.h>

class boxSystem {
private:
  int pin;
  // ### TIME ###
  //int week=0;
  bool isDay=1; //1=day, 0=night
  byte T_year=0;
  byte T_month=0;
  byte T_day=0;//full day!
  byte T_hour=0;
  byte T_minute=0;
  byte T_second=0;
  //int realTime=0;
  int startHoureReal=0; //Debut du jour par rapport a l'heure réelle.
//  unsigned long elapsedTime = millis();      // Temps ecoulé depuis le debut du programme
//  unsigned int cycleDuration = 0;            // Temps ecoulé depuis le dernier refreshStatus()
  const int sizeX = 0;
  const int sizeY = 0;
  const int sizeZ = 0;
  // ############
  int phase = 0; // 0=germination 1=plantule 2=vegetatif 3=floraison 4=sechage 5=rien => correspond aux cases des tableau de goal
  bool error = 0;
  char errorMessage[50]={0}; // max 50 caracteres (+ \0) !!!!

struct actionersStates {
  float vitesseMoteur=DEFAULT_SPEED;
  bool atomizer=0;
  bool heater=0;
  bool colder=0;
  bool deshumidificateur=0;
};
struct sensorsStates {
  int select=0; //case actuelle dans le roulement des cases prevut pour tableau circulaire
  float temperatureInt[HISTORY_SENSOR]={0};
  float relativeHumidityInt[HISTORY_SENSOR]={0};
  float temperatureExt[HISTORY_SENSOR]={18};
  float relativeHumidityExt[HISTORY_SENSOR]={20};
  float dirtHumidity[HISTORY_SENSOR]={0};
};




public:
//    LED(int p);
//    void on();
//    void off();
//    void blink(int delayMs);
};

#endif

*/
