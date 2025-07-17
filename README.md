# Provisioner
A basic library to include in your ESP32 code to effect a SoftAP-style WiFi provisioning.


## Quick Start
In your project's library folder:
```bash
    git clone https://github.com/OhioIoT-ESP32-Libraries/Provisioner.git
    rm -rf .git
```
At the top of your main.cpp or main.ino:
```cpp
    #include "provisioner.h"
    Provision provisioner
```
Inside your code:
```cpp
    provisioner.start();
```

## Documentation
For more information, see the YouTube video where this library was live-coded [ESP32 Provisioner](https://put youtube link.com)

## Issues
Report bugs at: <https://github.com/OhioIoT-ESP32-Libraries/Provisioner/issues>


Need tools to build your IoT projects that extend beyond your home or office?  Check out the OhioIoT platform, a cost-effective external platform designed for small-scale IoT projects: [OhioIoT.com](https://www.ohioiot.com).

