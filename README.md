## Documentation

- [Store page](https://www.elecrow.com/crowpanel-esp32-2-13-e-paper-hmi-display-with-122-250-resolution-black-white-color-driven-by-spi-interface.html?r=cmVsYXRl)
- [Technical wiki](https://www.elecrow.com/wiki/CrowPanel_ESP32_E-Paper_HMI_2.13-inch_Display.html)
- [Github Docs+Examples](https://github.com/Elecrow-RD/CrowPanel-ESP32-2.13-E-paper-HMI-Display-with-122-250)

The processor is the ESP32-S3. I found some other demos for this device online,
but they seemed to render incorrectly. It seems like the EPD protocol changed at
some point (`EPD.cpp`, `EPD_Init.cpp`, etc). The demos from the GitHub above are
working, so use those as reference!

## Building: ESP-IDF

This is the [official devkit](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/index.html) 
for working on ESP32 chips. The documentation seems very comprehensive! 
It was pretty easy to set up: after downloading their installer, you can 
just run their Developer command prompt and all of the following commands 
"just work", no other config needed.

All commands go through the `idf.py` executable with the following modes:

- `set-target esp32s3` to initialize the build environment
- `build` to compile but not upload
- `flash` to compile and upload
- `monitor` to view real-time output from the device

## Building: Arduino IDE

You can also build stuff with Arduino! A lot of people online took this
approach. In fact, the official device demo code all uses Arduino as well.
I found it the best way to get started and make sure I could compile and
run the demos.

However, I found the Arduino IDE to be more difficult to set up than ESP-IDF.
There is some cryptic configuration you need to do before flashing. You need 
to install the `ESP32S3 Dev Module` board. The partition scheme must be set
to `Huge APP (3MB No OTA/1MB SPIFFS)`, the PSRAM must be set to `OPI PSRAM`
Finally, I couldn't get the debugger to work (it fails with unclear errors).

