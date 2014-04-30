
//
#ifndef CHAT_H
#define	CHAT_H

#include <iostream>
#include <cstdlib>
//#include <sstream>
#include "SDL2/SDL.h"
#include <vector>
#include "Text.h"

using namespace std;
   class chat{
       
   public:

       chat();
       ~chat();
       void old_chatting(SDL_Event event); //SDL_Event* event
       void chatting();
       void show_result(); 
      // void chatting2();
       void can_type(bool x);
       void break_down(int size);
       void set_player(string str);
       void set_string(string str);
       void clear_vect();
       string get_input();
       string get_player();
       void merge_player_input();
       string get_vect(int x);
       int get_vect_end();
       //Future methods
       //scroll up and down to see text
       //Text boxes size
       //feature to mute spammers
       //
       
   private: 
       SDL_Surface * inbox, * textbox ; //input box, output box
       bool isTyping; //0 = not typing, 1 = typing
       int count; //initial state for SDL_StopTextInput()
       string s, player;
       //stringstream in, out; //input and output 
       const Uint8 * keystate; //state of keyboard , note: need to include const
       vector<string> input; 
   }; 


#endif	/* CHAT_H */

