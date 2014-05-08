/* 
 * File:   newsimpletest2.cpp
 * Author: Blaize
 *
 * Created on May 8, 2014, 9:21:32 AM
 */

#include <stdlib.h>
#include <iostream>
#include "../MobileBoxes.h"
using namespace std;

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "newsimpletest2 test 1" << std::endl;
}

void test2() {
    PushBox pus(192, 544);
    cout<<pus.getCord().x<<' '<<pus.getCord().y<<endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest2" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    test2();

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

