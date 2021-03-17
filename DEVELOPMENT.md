# Development

The current iteration of this project uses the ESP32-Pico-Kit, a small
microcontroller built on the Arduino platform with WiFi capability.

Previously, our robots were compiled and flashed using the Arduino IDE (and
still can, probably). As of now, we are using the [makeEspArduino
project](https://github.com/plerup/makeEspArduino).

---

## Installing and Building

Below are the instructions for each OS (if provided) for building the project
and flashing it to your device. We assume you've made your own repository with
the `Use this template` button on the DemobotESPTemplate repository.

---

### Linux

#### Setup

```bash
#1. Clone your repo in a place of your choice. We'll use Dancebot as an example project.
cd <PATH> # for example, ~/Github/RAS/
git clone https://github.com/ut-ras/Dancebot.git --recursive
# The --recursive tag initializes any provided dependency repositories
# in the inc/ folder.

#2. Install any required python dependencies.
cd <PATH>/Dancebot/
pip3 install -r requirements.txt

#3. Clone the makeEspArduino repo and ESP32 library and put it somewhere near.
cd <PATH>
git clone https://github.com/plerup/makeEspArduino.git
git clone https://github.com/espressif/arduino-esp32.git esp32

#4. Install the ESP environmental tools.
cd <PATH>/esp32
git submodule update --init
cd <PATH>/esp32/tools
python3 get.py
```

#### Demo Test

```bash
# The next set of commands tests whether you can flash to the board successfully.
cd <PATH>/makeEspArduino
make -f makeEspArduino.mk ESP_ROOT=<PATH>/esp32 CHIP=esp32 DEMO=1 flash

# Then try connecting to the device after seeing it hard reset with the screen command:
screen /dev/ttyUSB0 115200 # Your port may be different from /dev/ttyUSB0.

# You should see the results of the example WiFiScan.ino sketch, which can be
# found here: https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WiFi/examples/WiFiScan/WiFiScan.ino.

# To exit the screen utility, type ctrl+a, and then `:exit` and press enter.
```

#### Setting Up the espmake32 Command

```bash
# Now we can alias a make command for compiling and flashing binaries on demand.
cd <PATH>/makeEspArduino
# A suggestion for the path is to use the absolute path instead of relative
# (i.e., ../). This will allow you to be able to call this command anywhere.
make -f makeEspArduino.mk ESP_ROOT=<PATH>/esp32 CHIP=esp32 install

# Run the compiling command on one of their examples.
espmake32 SKETCH="<PATH>/esp32/libraries/WiFi/examples/WiFiScan/WiFiScan.ino"

# This compiles the .ino into an executable and stashes it in a place like
# `/tmp/mkESP/WiFiScan_esp32/WiFiScan.bin`.
# To flash, run the same command but with the flash suffix like follows:
espmake32 SKETCH="<PATH>/libraries/WiFi/examples/WiFiScan/WiFiScan.ino" flash

# Try connecting again with the screen command after the ESP flashes
screen /dev/ttyUSB0 115200 # Your port may be different from /dev/ttyUSB0.

# An alternative is to use the command espmake32 monitor.
espmake32 monitor # ctrl+] to exit.

# If it works, you should be set up for building your ino sketches natively!
```

#### Building the Project Repository

```bash
# To build your project repository, cd do your repo, and call the espmake32
# command from the root of your repo.
cd <PATH>/Dancebot
espmake32 SKETCH="./src/HelloWorld.ino" LIBS="./inc/" BUILD_DIR="./build/"

# You should be able to see the output of the build files in the build directory
# for the project.
```

#### Using the Built-in Script

The previous steps described above are a helpful primer on what goes on when
setting up the build tools and environment.

In the spirit of the word Automation in R(A)S, I've provided a build script for
once you complete step 'Building the Project Repository' for subsequent builds.

```bash
bash run.sh -h # Provides help information.
bash run.sh -c # Compiles the project and puts build artifacts into /build/.
bash run.sh -f # Compiles and flashes the project to the ESP32 if it is connected.
bash run.sh -m # Opens the serial monitor in the CLI if the ESP32 is connected.
```

Remember that you can go into run.sh and edit the SKETCH_PATH to swap to
compiling one of the examples for the `inc/` repositories, or if you have another
`sketch.ino` in the `src/` folder.

#### Includes

Sometimes, your project might use more than the provided include libraries. For
example, the Dancebot project uses madhephaestus'
[ESP32Servo](https://github.com/madhephaestus/ESP32Servo) library.
To add the dependency to your project, go the includes folder and add it as a
submodule!

```bash
cd <PATH>/Dancebot/inc/
git submodule add <URL>
# i.e. git submodule add https://github.com/madhephaestus/ESP32Servo.git
```

You'll be up to date to the most recent version as of cloning, and whenever you
want to update to the latest and greatest, you can call the following:

```bash
cd <PATH>/Dancebot

# If you haven't used the --recursive flag in the setup section.
git submodule update --init
# After you've initialized the submodules at least once.
git submodule update --remote
```
