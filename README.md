# IndoorClimateControl

## Description
**IndoorClimateControl** is a project initially designed for thermal and hygrostatic regulation in semi-closed environments (meaning the exchange with the outside is controlled). The system is intended to be flexible, modular, and resilient. It uses a set of modules, virtually separated into input, output, and compute categories, each interconnected following a nodal design. The target platforms are ESP32, ESP8266, and Arduino (ATMega).

## Global Functioning

### System Architecture
The system relies on a modular architecture where each module represents a distinct functionality or component. Each module is a class that inherits from `module_base`. They implement two essential methods:
1. **init()**
2. **loop()**

Modules are dynamically added to a central array called `module_heap`, allowing periodic execution, and supporting multithreading depending on the platform. In the `config.h` file, you can enable the desired modules via preprocessor directives.

## Adding a Module

### Step 1: Create a New Module
To add a new module, you need to create a class that inherits from `module_base` and implements the `init()` and `loop()` methods.

### Step 2: Add the Module in the Main Code
Once the module is created, it can be added to the "heap" in the `main.cpp` file by calling the `addModule()` method as follows:
```cpp
object.addModule("arbitrary name", <refresh rate in ms>, <new mySpecificFunction(arg1, arg2...)>, <execute init on creation, optional, default=true>);
