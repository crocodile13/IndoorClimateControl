#include <Arduino.h>  // Nécessaire pour String, Serial, millis(), et d'autres fonctions Arduino
#include "config.h"

#ifdef MODULES
#ifndef MODULES_H
#define MODULES_H

//#include <Arduino.h>  // Inclut la bibliothèque Arduino, nécessaire pour String

// Classe de base pour les modules
class module_base {
public:
    String name;        // Nom du module, utilise String d'Arduino
    int moduleRefresh = 60000; // Temps de rafraîchissement (par défaut 60s)
    String errorLog;    // Log d'erreurs, utilise String d'Arduino
    unsigned long lastExecution = 0; // Temps de la dernière exécution en millisecondes
    virtual void init() = 0; // Méthode d'initialisation pure virtuelle
    virtual void loop() = 0; // Méthode de boucle principale pure virtuelle
    virtual ~module_base() = default; // Destructeur virtuel pour gérer correctement la destruction des sous-classes
};


// Classe pour gérer une "heap" de modules
class module_heap {
public:
    int heapRefreshTime = 60000;      // Temps de rafraîchissement global
    String errorLog;                  // Log d'erreurs
    
    // a l'occaz utiliser le referencement pour tout les arguments pour se gagner quelques octets.
    int addModule(const String& moduleName, int moduleRefresh, module_base* module, bool callInit = true); // Ajouter un module à la liste
    int execHeap();                     // Exécuter tous les modules
    int removeModule(const String& moduleName); // Supprimer un module par nom
    ~module_heap(); // Destructeur pour libérer la mémoire allouée
private:
    module_base** modules = nullptr; // Pointeur vers un tableau dynamique de modules
    int moduleCount = 0; // Nombre de modules dans le tableau
    int moduleCapacity = 0; // Capacité actuelle du tableau
    void resizeModulesList(int newCapacity);
};

#endif
#endif
