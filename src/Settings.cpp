#include "Settings.h"
#include "Enumerations.h"

Settings::Settings()
{
    uiSfxEnabled = true;
    gameSfxEnabled = true;
    musicEnabled = true;
    
    cout << "\tSettings class..." <<endl;
}

Settings::~Settings()
{
	
}

bool* Settings::getLinkedBool(int index)
{
    switch ( index )
    {
	case Enums::SET_UISFX_BOOL:
	    return &uiSfxEnabled;
	case Enums::SET_GAMESFX_BOOL:
	    return &gameSfxEnabled;
	case Enums::SET_MUSIC_BOOL:
	    return &musicEnabled;
    }
}

bool Settings::getUiSfxEnabled()
{
    return uiSfxEnabled;
}

int Settings::getUiSfxVolume()
{
    return uiSfxVolume;
}

void Settings::toggleUiSfxEnabled()
{
    uiSfxEnabled = !uiSfxEnabled;
}

void Settings::setUiSfxVolume(int tVol)
{
    uiSfxVolume = tVol;
}

bool Settings::getGameSfxEnabled()
{
    return gameSfxEnabled;
}

int Settings::getGameSfxVolume()
{
    return gameSfxVolume;
}

void Settings::toggleGameSfxEnabled()
{
    gameSfxEnabled = !gameSfxEnabled;
}

void Settings::setGameSfxVolume(int tVol)
{
    gameSfxVolume = tVol;
}

bool Settings::getMusicEnabled()
{
    return musicEnabled;
}

int Settings::getMusicVolume()
{
    return musicVolume;
}

void Settings::toggleMusicEnabled()
{
    musicEnabled = !musicEnabled;
}

void Settings::setMusicVolume(int tVol)
{
    musicVolume = tVol;
}


bool Settings::loadSettings()
{

}

bool Settings::saveSettings()
{

}