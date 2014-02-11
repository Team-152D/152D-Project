#include <iostream>
#include "Application.h"

using namespace std;

int main(int argc, char* args[])
{
	cout << "*** RUNNING APPLICATION ***" << endl;
	
	int returnValue;
	Application *application = new Application();
	returnValue = application->runApplication();
	delete application;
	
	cout << "*** EXITING APPLICATION WITH RETURN VALUE = " << returnValue << "***" << endl;
	return returnValue;
}