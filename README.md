# Google Chrome Dinosaur game
![](https://hackster.imgix.net/uploads/attachments/932614/img_6526_xoznxu7H5F.JPG?auto=compress%2Cformat&w=740&h=555&fit=max)

This code was made on [ESP-WROVER-KIT](https://docs.espressif.com/projects/esp-idf/en/latest/hw-reference/get-started-wrover-kit.html) and using [WROVER-KIT-LCD](https://github.com/espressif/WROVER_KIT_LCD) library.
The DinoGame folder needs to be in Arduino's libraries folder.
Aditional information about the project is [here](https://www.hackster.io/brzi/google-chrome-dinosaur-game-on-3-4-tft-c8ad88).

(some legal stuff) I do not own the rights to this game I just did this out of fun (/some legal stuff)

## Porting to M5Stack
 <img src="./Dinosaur_M5stack.jpg" width="320" height="320">

- Change LCD pin definition in WROVER_KIT_LCD.cpp
~~~cpp
#define WROVER_CS               14
#define WROVER_DC               27
#define WROVER_RST              33
#define WROVER_SCLK             18
#define WROVER_MOSI             23
#define WROVER_MISO             19
#define WROVER_BL               32
~~~
- Change LCD width & height in WROVER_KIT_LCD.h
~~~cpp
#define WROVER_WIDTH       320
#define WROVER_HEIGHT      240
~~~
- Change button pin in T0Rex_TFT.ino
