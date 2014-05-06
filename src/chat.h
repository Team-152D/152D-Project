
//
#ifndef CHAT_H
#define	CHAT_H

#define Limit 75

#include <iostream>
#include <cstdlib>
//#include <sstream>
#include "SDL2/SDL.h"
#include <vector>
#include <list>
#include "Text.h"
#include "UI_IPfield.h"

using namespace std;
   class chat{
       
   public:

       chat();
       ~chat();
       void old_chatting(SDL_Event event); //SDL_Event* event
       void chatting();
       void show_result(); 
       bool can_type();
       void break_down(int size);
       void set_player(string str);
       void set_string(string str);
       void clear_vect();
       string get_input();
       string get_player();
       void merge_player_input();
       string get_vect(int x);
       int get_vect_end();
       void show_input();
       void show_output();
       int toggle();
       void input_text();
       //Future methods
       //scroll up and down to see text
       //Text boxes size
       //feature to mute spammers
       //
       SDL_Rect in, out;
    
       
   private: 
       SDL_Surface * inbox, * textbox ; //input box, output box
       bool isTyping; //0 = not typing, 1 = typing
       int count; //initial state for SDL_StopTextInput()
       int state_out; 
       string s, player;
       //stringstream in, out; //input and output 
       const Uint8 * keystate; //state of keyboard , note: need to include const
       vector<string> input;
       list<string> output; 
       //UI_IPfield text_out(out,14,false); // text_in(in,14,false);
   }; 


#endif	/* CHAT_H */

