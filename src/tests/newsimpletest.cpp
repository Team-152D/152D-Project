/* 
 * File:   newsimpletest.cpp
 * Author: Mark
 *
 * Created on May 7, 2014, 5:26:14 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Player.h"

/*
 * Simple C++ Test Suite
 */

void testPlayer() {
    int p0;
    int p1;
    int p2;
    Player player(p0, p1, p2);
    if (true player->mynum()!=1) {
        std::cout << "%TEST_FAILED% time=0 testname=testPlayer (newsimpletest) message=error message sample" << std::endl;
    }
}

void testApply_surface() {
    int p0;
    int p1;
    SDL_Surface* p2;
    SDL_Rect* p3;
    Player player;
    player.apply_surface(p0, p1, p2, p3);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testApply_surface (newsimpletest) message=error message sample" << std::endl;
    }
}

void testCheckCharacters() {
    Player player;
    bool result = player.checkCharacters();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCheckCharacters (newsimpletest) message=error message sample" << std::endl;
    }
}

void testCheckGates() {
    Player player;
    bool result = player.checkGates();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCheckGates (newsimpletest) message=error message sample" << std::endl;
    }
}

void testCheckSwitches() {
    Player player;
    player.checkSwitches();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCheckSwitches (newsimpletest) message=error message sample" << std::endl;
    }
}

void testDraw() {
    Player player;
    player.draw();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDraw (newsimpletest) message=error message sample" << std::endl;
    }
}

void testInput() {
    char* p0;
    Player player;
    player.input(p0);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testInput (newsimpletest) message=error message sample" << std::endl;
    }
}

void testShooting() {
    Player player;
    player.shooting();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testShooting (newsimpletest) message=error message sample" << std::endl;
    }
}

void testUpdate() {
    Player player;
    player.update();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testUpdate (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testPlayer (newsimpletest)" << std::endl;
    testPlayer();
    std::cout << "%TEST_FINISHED% time=0 testPlayer (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testApply_surface (newsimpletest)" << std::endl;
    testApply_surface();
    std::cout << "%TEST_FINISHED% time=0 testApply_surface (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testCheckCharacters (newsimpletest)" << std::endl;
    testCheckCharacters();
    std::cout << "%TEST_FINISHED% time=0 testCheckCharacters (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testCheckGates (newsimpletest)" << std::endl;
    testCheckGates();
    std::cout << "%TEST_FINISHED% time=0 testCheckGates (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testCheckSwitches (newsimpletest)" << std::endl;
    testCheckSwitches();
    std::cout << "%TEST_FINISHED% time=0 testCheckSwitches (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testDraw (newsimpletest)" << std::endl;
    testDraw();
    std::cout << "%TEST_FINISHED% time=0 testDraw (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testInput (newsimpletest)" << std::endl;
    testInput();
    std::cout << "%TEST_FINISHED% time=0 testInput (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testShooting (newsimpletest)" << std::endl;
    testShooting();
    std::cout << "%TEST_FINISHED% time=0 testShooting (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testUpdate (newsimpletest)" << std::endl;
    testUpdate();
    std::cout << "%TEST_FINISHED% time=0 testUpdate (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

