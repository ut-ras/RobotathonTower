/**
 * Author: Matthew Yu
 * Last Modified: 03/17/21
 * Project: Dancebot
 * File: RoboTower.ino
 * Description: The Tower of William C. Powers
 * Organization: UT IEEE RAS
 */
#include <Arduino.h>
#include <DemobotNetwork.h>
#include <DemobotServer.h>
#include <DemobotClient.h>

/** Network instantiation. */
DemobotNetwork *network;
DemobotServer *server;
DemobotClient *client;

void setup() {
    Serial.begin(115200);
    Serial.println("DancebotESP32.ino.");
    /* Give some time to open up the serial monitor. */
    delay(5000); // 5 seconds

    /* Set up the network and server. */

    /* Set up the Tower object. */

}

void loop() {
    /* Every 200 ms, send an asynchronous request to the server for the latest
     *state to update the Tower object. */

    /* The rest of the time, just operate as normal. */
}
