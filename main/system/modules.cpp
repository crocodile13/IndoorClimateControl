#include "modules.h"
#include <Arduino.h>  // Nécessaire pour String, Serial, millis(), et d'autres fonctions Arduino

#ifdef MODULES

// Fonction pour réallouer la mémoire pour le tableau dynamique de modules
void module_heap::resizeModulesList(int newCapacity) {
    module_base** newModules = (module_base**)realloc(modules, newCapacity * sizeof(module_base*));
    if (newModules) {
        modules = newModules;
        moduleCapacity = newCapacity;
    } else {
        errorLog = "Erreur de réallocation mémoire.";
#ifdef MODE_SERIAL_DEBUG
        Serial.println("Erreur de réallocation mémoire.");
#endif
    }
}

// Ajouter un module à la liste
int module_heap::addModule(const String& moduleName, int moduleRefresh, module_base* module, bool callInit) {
    if (module) {
        // Si le tableau est plein, augmenter la capacité de 1
        if (moduleCapacity == moduleCount) {
            moduleCapacity++;  // Augmente de 1
            modules = (module_base**) realloc(modules, moduleCapacity * sizeof(module_base*));  // Réallouer avec la nouvelle capacité
            if (modules == nullptr) {
                errorLog = "Erreur de réallocation mémoire.";
                return -1; // Erreur de réallocation
            }
        }
        // Affecter le nom et le temps de rafraîchissement au module
        module->name = moduleName;
        module->moduleRefresh = moduleRefresh;
        modules[moduleCount] = module;  // Ajouter le module au tableau
        moduleCount++;  // Incrémenter le nombre de modules
#ifdef MODE_SERIAL_DEBUG
        Serial.print("Module ajouté : ");
        Serial.println(module->name.c_str());
#endif
        // Initialiser le module si nécessaire
        if (callInit) {
            module->init(); // Appeler init() si spécifié
#ifdef MODE_SERIAL_DEBUG
            Serial.print("Initialisation de : ");
            Serial.println(module->name.c_str());
#endif
        }
        return 0; // Succès
    }
    errorLog = "Erreur : module invalide.";
#ifdef MODE_SERIAL_DEBUG
    Serial.println("Erreur : module invalide.");
#endif
    return -1; // Erreur
}


// Exécuter tous les modules
int module_heap::execHeap() {
    unsigned long currentMillis = millis();

    for (int i = 0; i < moduleCount; ++i) {
        module_base* module = modules[i];
        if (module) {
            // Vérifier si le module peut être exécuté
            if (currentMillis - module->lastExecution >= module->moduleRefresh) {
#ifdef MODE_SERIAL_DEBUG
                Serial.print("Exécution du module : "); 
                Serial.println(module->name.c_str());
#endif
                module->loop(); // Exécute la méthode loop du module
                module->lastExecution = currentMillis; // Mise à jour du dernier temps d'exécution
            }
        } else {
#ifdef MODE_SERIAL_DEBUG
            Serial.println("Module invalide trouvé.");
#endif
        }
    }
    return 0;
}

// Supprimer un module par son nom
int module_heap::removeModule(const String& moduleName) {
    for (int i = 0; i < moduleCount; ++i) {
        module_base* module = modules[i];
        if (module && module->name == moduleName) {
            delete module; // Libérer la mémoire associée au module
            // Déplacer les éléments suivants pour "écraser" le module supprimé
            for (int j = i; j < moduleCount - 1; ++j) {
                modules[j] = modules[j + 1];
            }
            modules[moduleCount - 1] = nullptr; // S'assurer que la dernière position est vide
            --moduleCount; // Décrémenter le nombre de modules

#ifdef MODE_SERIAL_DEBUG
            Serial.print("Module supprimé : ");
            Serial.println(moduleName.c_str());
#endif
            return 0; // Succès
        }
    }
    errorLog = "Module non trouvé : " + moduleName;
#ifdef MODE_SERIAL_DEBUG
    Serial.println("Erreur : module non trouvé.");
#endif
    return -1; // Erreur, module non trouvé
}

// Destructeur pour libérer la mémoire allouée dynamiquement ... a priori yen aura jamais besoin mais bon ca coute rien de le laisser la ...
module_heap::~module_heap() {
    // Libérer chaque module alloué
    for (int i = 0; i < moduleCount; ++i) {
        delete modules[i];
    }
    // Libérer le tableau lui-même
    free(modules);
}

#endif
