/**
 * Author: Matthew Yu
 * Last Modified: 05/22/20
 * Project: Demobot Template
 * File: DancebotAPI.h
 * Description: Demobot API to drive hardware with using a state structure
 * Organization: UT IEEE RAS
 */
#ifndef DEMOBOTAPI_H
#define DEMOBOTAPI_H

/**************** TODO: ADD ANY ROBOT SPECIFIC HEADER FILES HERE *****************/
#include "RobotConfig.h"

void initializeRobot();
void move();
void updateState(String state);
/**************** TODO: ADD ANY HELPER FUNCTIONS AS NECESSARY ***************/

#endif