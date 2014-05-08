/* 
 * File:   newsimpletest1.cpp
 * Author: Sammy
 *
 * Created on May 7, 2014, 5:58:22 PM
 */

#include <stdlib.h>
#include <iostream>
#include "../Player.h"

/*
 * Simple C++ Test Suite
 */

void testPlayer( )
{
	int p0;
	int p1;
	int p2;
	Player player( p0, p1, p2 );
	if ( true /*check result*/ )
	{
		std::cout << "%TEST_FAILED% time=0 testname=testPlayer (newsimpletest1) message=error message sample" << std::endl;
	}
}

void testApply_surface( )
{
	int p0;
	int p1;
	SDL_Surface* p2;
	SDL_Rect* p3;
	Player player;
	player.apply_surface( p0, p1, p2, p3 );
	if ( true /*check result*/ )
	{
		std::cout << "%TEST_FAILED% time=0 testname=testApply_surface (newsimpletest1) message=error message sample" << std::endl;
	}
}

void testCheckCharacters( )
{
	Player player;
	bool result = player.checkCharacters( );
	if ( true /*check result*/ )
	{
		std::cout << "%TEST_FAILED% time=0 testname=testCheckCharacters (newsimpletest1) message=error message sample" << std::endl;
	}
}

void testCheckGates( )
{
	Player player;
	bool result = player.checkGates( );
	if ( true /*check result*/ )
	{
		std::cout << "%TEST_FAILED% time=0 testname=testCheckGates (newsimpletest1) message=error message sample" << std::endl;
	}
}

void testCheckSwitches( )
{
	Player player;
	player.checkSwitches( );
	if ( true /*check result*/ )
	{
		std::cout << "%TEST_FAILED% time=0 testname=testCheckSwitches (newsimpletest1) message=error message sample" << std::endl;
	}
}

void testDraw( )
{
	Player player;
	player.draw( );
	if ( true /*check result*/ )
	{
		std::cout << "%TEST_FAILED% time=0 testname=testDraw (newsimpletest1) message=error message sample" << std::endl;
	}
}

void testInput( )
{
	char* p0;
	Player player;
	player.input( p0 );
	if ( true /*check result*/ )
	{
		std::cout << "%TEST_FAILED% time=0 testname=testInput (newsimpletest1) message=error message sample" << std::endl;
	}
}

void testShooting( )
{
	Player player;
	player.shooting( );
	if ( true /*check result*/ )
	{
		std::cout << "%TEST_FAILED% time=0 testname=testShooting (newsimpletest1) message=error message sample" << std::endl;
	}
}

void testUpdate( )
{
	Player player;
	player.update( );
	if ( true /*check result*/ )
	{
		std::cout << "%TEST_FAILED% time=0 testname=testUpdate (newsimpletest1) message=error message sample" << std::endl;
	}
}

int main( int argc, char** argv )
{
	std::cout << "%SUITE_STARTING% newsimpletest1" << std::endl;
	std::cout << "%SUITE_STARTED%" << std::endl;

	std::cout << "%TEST_STARTED% testPlayer (newsimpletest1)" << std::endl;
	testPlayer( );
	std::cout << "%TEST_FINISHED% time=0 testPlayer (newsimpletest1)" << std::endl;

	std::cout << "%TEST_STARTED% testApply_surface (newsimpletest1)" << std::endl;
	testApply_surface( );
	std::cout << "%TEST_FINISHED% time=0 testApply_surface (newsimpletest1)" << std::endl;

	std::cout << "%TEST_STARTED% testCheckCharacters (newsimpletest1)" << std::endl;
	testCheckCharacters( );
	std::cout << "%TEST_FINISHED% time=0 testCheckCharacters (newsimpletest1)" << std::endl;

	std::cout << "%TEST_STARTED% testCheckGates (newsimpletest1)" << std::endl;
	testCheckGates( );
	std::cout << "%TEST_FINISHED% time=0 testCheckGates (newsimpletest1)" << std::endl;

	std::cout << "%TEST_STARTED% testCheckSwitches (newsimpletest1)" << std::endl;
	testCheckSwitches( );
	std::cout << "%TEST_FINISHED% time=0 testCheckSwitches (newsimpletest1)" << std::endl;

	std::cout << "%TEST_STARTED% testDraw (newsimpletest1)" << std::endl;
	testDraw( );
	std::cout << "%TEST_FINISHED% time=0 testDraw (newsimpletest1)" << std::endl;

	std::cout << "%TEST_STARTED% testInput (newsimpletest1)" << std::endl;
	testInput( );
	std::cout << "%TEST_FINISHED% time=0 testInput (newsimpletest1)" << std::endl;

	std::cout << "%TEST_STARTED% testShooting (newsimpletest1)" << std::endl;
	testShooting( );
	std::cout << "%TEST_FINISHED% time=0 testShooting (newsimpletest1)" << std::endl;

	std::cout << "%TEST_STARTED% testUpdate (newsimpletest1)" << std::endl;
	testUpdate( );
	std::cout << "%TEST_FINISHED% time=0 testUpdate (newsimpletest1)" << std::endl;

	std::cout << "%SUITE_FINISHED% time=0" << std::endl;

	return (EXIT_SUCCESS );
}

