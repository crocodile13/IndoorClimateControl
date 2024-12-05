# IndoorClimateControl

## Description
**IndoorClimateControl** est un projet initialement pensé pour la régulation thermique et hygrostatique de milieux semi clos (entendez par la que l'echange avec l'exterieur est controlé). Le système se veut flexible, modulaire et resiliant. Il utilise un ensemble de modules, virtuelement séparés entre input, output et compute, chacuns interconnectés selon une conception nodale. Les plateformes cibles sont ESP32, ESP 8826 et Arduino (ATMega).



## Fonctionnement Global

### Architecture du Système
Le système repose sur une architecture modulaire où chaque module représente une fonctionnalité ou un composant distinct. Chaque modules sont des classes et heritent de `module_base`. Ils implémente deux méthodes essentielles :
1. **init()**
2. **loop()**
Les modules sont ajoutés dynamiquement à un tableau central appelé `module_heap`, permetant un exécution périodique, suportant en fonction de la plateforme le multithreading.
Dans le fichier `config.h`, vous pouvez activer les modules souhaités via des directives préprocesseurs.


## Ajouter un Module

### Étape 1 : Créer un Nouveau Module
Pour ajouter un module, vous devez créer une nouvelle classe qui hérite de `module_base` et implémente les méthodes `init()` et `loop()`.

### Étape 2 : Ajouter le Module dans le Code Principal
Une fois le module créé, il peut être ajouté à la "heap" dans le fichier `main.cpp` en appelant la méthode `addModule()` tel que: object.addModule("nom arbitraire" , <refraichissement en ms> , <new maFonctionSpecifique(arg1,arg2...)> , <executer init a la creation, optionnel, default=true>);

### Étape 3 : Configurer le Module dans `config.h`

## Structure du Projet

Le projet est structuré de manière à séparer la logique des modules de la gestion du système global. Voici les principaux fichiers et leur rôle :
System:
- **main.cpp** : Le fichier principal contenant la boucle de programme et la logique d'ajout des modules.
- **config.h** : Contient les configurations globales, y compris l'activation des modules.
- **buildConfig.h** : Contient les configurations spécifiques à la plateforme.
- **modules.h / modules.cpp** : Contient la classe de base `module_base` et la gestion de la "heap" de modules.
Modules:
- **input_dht22.h / input_dht22.cpp** : Exemple de module pour le capteur DHT22 (ce fichier peut être remplacé ou étendu pour d'autres types de capteurs).
- [...]



De par sa structure modulaire le projet me semble extensible a bien d'autres usages, en particulier en domotique.

Gros bisous.
