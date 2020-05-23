/**
 * Author: Matthew Yu
 * Last Modified: 05/22/20
 * Project: Demobot Template
 * File: DancebotESP32.ino
 * Description: TODO: Update the file name, project name, and description here.
 * Organization: UT IEEE RAS
 */
#include <Arduino.h>
#include "DemobotAPI.h"     // grab abstracted robot API - we fill in this for each robot
#include "WebController.h"  


/** 
 * Example flow for a Demobots sketch with an ESP32:
 * setup() {
 *   initializeRobot()
 *   setupWifi()
 * }
 * 
 * loop() {
 *   move
 *   look for update from server
 *   update robot state
 * }
 */

void setup() {
    delay(5000); //give time for me to open up serial monitor
    setupWifi();
    initializeRobot();
}

void loop() {
    static int lastMsgTime = 12000; // start 12 seconds into bootup

    move();

    // send GetState request to server and update the robot state
    int time = millis();
    if(/** TODO: ADD ANY EXTRA CONDITIONS HERE **/ ((time - lastMsgTime) > UPDATE_WAIT)) {
        updateState(getState());
        lastMsgTime = time;
    }
}
