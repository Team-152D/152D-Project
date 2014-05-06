#ifndef SETTINGS_H
#define	SETTINGS_H

#include <iostream>

using namespace std;

class Settings
{
public:
	Settings();
	~Settings();

	bool* getLinkedBool(int);

	//audio settings accessors
	bool getUiSfxEnabled();
	int getUiSfxVolume();
	void toggleUiSfxEnabled();
	void setUiSfxVolume(int);

	bool getGameSfxEnabled();
	int getGameSfxVolume();
	void toggleGameSfxEnabled();
	void setGameSfxVolume(int);

	bool getMusicEnabled();
	int getMusicVolume();
	void toggleMusicEnabled();
	void setMusicVolume(int);

	//video settings accessors
	bool getIsFullscreen();
	void toggleIsFullscreen();

	//dev settings accessors
	bool getMenuDebug();
	void toggleMenuDebug();
private:
	bool loadSettings();
	bool saveSettings();

	//audio settings
	bool uiSfxEnabled;
	int uiSfxVolume;
	bool gameSfxEnabled;
	int gameSfxVolume;
	bool musicEnabled;
	int musicVolume;

	//video settings
	bool isFullscreen;

	//development settings
	bool menuDebug;
};

#endif