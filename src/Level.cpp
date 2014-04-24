#include "Level.h"

Level::Level( int levelNumber )
{
	multiplayer = currentGameGlobal->multiPlayer;
	loadLevel( levelNumber );

    characters = new vector<Unit*>;
    movers = new vector<Mover*>;
    gates = new vector<Gate*>;
    switches = new vector<Switch*>;
    powerups = new vector<Powerup*>;
        
	player1 = new Player( p1Spawn.x, p1Spawn.y);
        characters->push_back(player1);
	if ( multiplayer ){
		player2 = new Player(p2Spawn.x, p2Spawn.y);
                characters->push_back(player2);
                }
	else
		player2 = NULL;
        
    difficulty="Easy"; //default until we get something more specific set
    currentLevelGlobal = this;
    Guard* tester = new Guard(espawn.x,espawn.y);
    characters->push_back(tester);
}

vector<Mover*>* Level::getMovers(){return movers;}

vector<Unit*>* Level::getCharacters(){return characters;}

vector<Gate*>* Level::getGates(){return gates;}

vector<Switch*>* Level::getSwitches(){return switches;}

vector<Powerup*>* Level::getPowerups(){return powerups;}

string Level::getDifficulty(){return difficulty;}

bool Level::isMultiplayer(){return multiplayer;}

Level::~Level( )
{
	currentLevelGlobal = NULL;
}

void Level::input( char *inP1, char *inP2 )
{
	player1->input( inP1 );
	if ( multiplayer )
		player2->input( inP2 );
}

void Level::update( )
{
    Unit* Upointer;
    Mover* Mpointer;
    Gate* Gpointer;
    Switch* Spointer;
    Powerup* Ppointer;
    
    bool isalive;
    
    for(int i=0; i<characters->size();i++){
        Upointer = characters->at(i);
        isalive=Upointer->isAlive();
        if(isalive==false)
            characters->erase(characters->begin()+i);
        else
            Upointer->update();
        }
    bool hit=false;
    for(int j=0; j<movers->size();j++){
        Mpointer = movers->at(j);
        hit=Mpointer->checkhit();
        if(hit==true)
            movers->erase(movers->begin()+j);
        else
            Mpointer->update();
    }
    for(int j=0; j<gates->size();j++){
        Gpointer = gates->at(j);
        Gpointer->update();
    }
    for(int j=0; j<switches->size();j++){
        Spointer = switches->at(j);
        Spointer->update();
    }
    bool grabbed;
    for(int j=0; j<powerups->size();j++){
        Ppointer = powerups->at(j);
        grabbed=Ppointer->status();
        if(grabbed==true)
            powerups->erase(powerups->begin()+j);
        else
            Ppointer->update();
    }
}

void Level::draw( )
{
    grid -> drawGrid( );

    Unit* Upointer;
    Mover* Mpointer;
    Gate* Gpointer;
    Switch* Spointer;
    Powerup* Ppointer;
    
    for(int i=0; i<characters->size();i++){
        Upointer = characters->at(i);
        Upointer->draw();
        }
    for(int j=0; j<movers->size();j++){
        Mpointer = movers->at(j);
        Mpointer->draw();
        }
        for(int j=0; j<gates->size();j++){
        Gpointer = gates->at(j);
        Gpointer->draw();
    }
    for(int j=0; j<switches->size();j++){
        Spointer = switches->at(j);
        Spointer->draw();
    }
    for(int j=0; j<powerups->size();j++){
        Ppointer = powerups->at(j);
        Ppointer->draw();
    }
    
    ostringstream sstream;
    sstream << "Ammo (Player 1) = " << player1->getammo();

    text->writeText( 0, 0, sstream.str( ).c_str( ), 36 );
    sstream.str( string( ) );

    if(multiplayer==true){
        sstream << "Ammo (Player 2) = " << player2->getammo();
        text->writeText( 0, 50, sstream.str( ).c_str( ), 36 );
    }
}

Player* Level::getPlayer( int player )
{
	if ( player == 1 )
		return player1;
	else return player2;
}

bool Level::victoryCondition( )
{
	bool endOne = false, endTwo = false;
	//cout << "victory- getting offsets" << endl;
	int x1 = player1->getXoffset( );
	int y1 = player1->getYoffset( );
	int x2 = 0, y2 = 0;
	if ( currentGameGlobal->multiPlayer )
	{
		x2 = player2->getXoffset( );
		y2 = player2->getYoffset( );
	}

	//cout << "victory- checking if stuff is in the bounds" << endl;
	if ( ( x1 > endzone.x ) &&
		 ( x1 < ( endzone.x + endzone.w ) ) &&
		 ( y1 > endzone.y ) &&
		 ( y1 < ( endzone.y + endzone.h ) )
		 )
		endOne = true;
	if ( currentGameGlobal->multiPlayer )
		if ( ( x2 > endzone.x ) &&
			 ( x2 < ( endzone.x + endzone.w ) ) &&
			 ( y2 > endzone.y ) &&
			 ( y2 < ( endzone.y + endzone.h ) )
			 )
			endTwo = true;
	if ( currentGameGlobal->multiPlayer )
		return (endOne || endTwo );
	else
		return endOne;
}

void Level::loadLevel( int level )
{
	cout << "DEBUG: Level is loading file" << endl;
	vector<vector<int>*>* temp = new vector<vector<int>*>;

	for ( int i = 0; i < Global::GRID_HEIGHT; i++ )
		temp->push_back( new vector<int> );

	for ( int i = 0; i < Global::GRID_HEIGHT; i++ )
		for ( int j = 0; j < Global::GRID_WIDTH; j++ )
			temp->at( i )->push_back( 1 );

	string filepath;
	switch ( level )
	{
		case 1: filepath = "rsc\\data\\data_s1.txt";
			break;
		case 2: filepath = "rsc\\data\\data_s2.txt";
			break;
		case 3: filepath = "rsc\\data\\data_s3.txt";
			break;
		case 4: filepath = "rsc\\data\\data_s4.txt";
			break;
		case 5: filepath = "rsc\\data\\data_s5.txt";
			break;
	}

	ifstream infile;
	infile.open( filepath.c_str( ) );
	for ( int i = 0; i < Global::GRID_HEIGHT; i++ )
	{
		for ( int j = 0; j < Global::GRID_WIDTH; j++ )
		{
			int input;
			if ( infile >> input )
				temp->at( i )->at( j ) = input;
			else
				break;
		}
		if ( !infile )
			break;
	}
	infile >> p1Spawn.x;
	infile >> p1Spawn.y;
	infile >> p2Spawn.x;
	infile >> p2Spawn.y;
	infile >> endzone.x;
	infile >> endzone.y;
	infile >> endzone.w;
	infile >> endzone.h;
        infile >> espawn.x;
        infile >> espawn.y;
	infile.close( );

	cout << "DEBUG: (Level.cpp) P1 Spawn = (" << p1Spawn.x << "," << p1Spawn.y << ")"
		<< "P2 Spawn = (" << p2Spawn.x << "," << p2Spawn.y << ")"
		<< "Endzone = (" << endzone.x << "," << endzone.y << ")"
                << "Guard = (" << espawn.x << "," << espawn.y << ")" <<endl;

	this->grid = new Grid( temp );
	cout << "DEBUG: Level file loaded" << endl;
}

Grid* Level::getGrid( )
{
	return grid;
}

vector<string>* Level::getInfoBarData( )
{
	vector<string>* vec = new vector<string>;
	stringstream ss;
	string s1, s2, strX, strY, strXVel, strYVel;


	ss << "Level: ";
	ss << currentGameGlobal->getCurrentLevelNumber( );
	s1 = ss.str( );
	vec->push_back( s1 );
	ss.str( string( ) );

	ss << "Health: ";
	ss << player1->getHealth( );
	s2 = ss.str( );
	vec->push_back( s2 );
	ss.str( string( ) );

	ss << player1->getXoffset( );
	strX = ss.str( );
	vec->push_back( strX );
	ss.str( string( ) );

	ss << player1->getYoffset( );
	strY = ss.str( );
	vec->push_back( strY );
	ss.str( string( ) );

	ss << player1->getXVel( );
	strXVel = ss.str( );
	vec->push_back( strXVel );
	ss.str( string( ) );

	ss << player1->getYVel( );
	strYVel = ss.str( );
	vec->push_back( strYVel );
	ss.str( string( ) );


	return vec;
}
