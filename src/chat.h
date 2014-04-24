
//
#ifndef CHAT_H
#define	CHAT_H

//http://lazyfoo.net/SDL_tutorials/lesson23/index.php

#include <iostream>
#include <cstdlib>
#include <sstream>
#include "SDL2/SDL.h"

#include "Text.h"

using namespace std;
   class chat{
       
   public:

       chat();
       ~chat();
       
       
       void run(); 
       
       
       //move to private later
       void old_chatting(SDL_Event event); //SDL_Event* event
       void chatting();
       void show_message(string str);
       void send_message(string str);
       void show_result();
       
       void chatting2();
      
       void can_type(bool x);
       
       string get_input();
       string get_player();
   
       //Future methods
       //scroll up and down to see text
       //Text boxes size
       //feature to mute spammers
       //
       
   private: 
       SDL_Surface * inbox, * textbox ; //input box, output box
       bool isTyping; //0 = not typing, 1 = typing
       string s, player;
       stringstream in, out; //input and output 
       const Uint8 * keystate; //state of keyboard , note: need to include const
      
   }; 


#endif	/* CHAT_H */

