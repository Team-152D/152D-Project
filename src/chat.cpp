#include "chat.h"
#include "SDL2/SDL.h"
//  //
using namespace std;

chat::chat(){
    s = "";
    //in = "";
    //out = "";
    player = "<Bob> ";
    textbox = NULL; //output
    inbox = NULL;   //input
    keystate = NULL;
    isTyping = false;
    count = 0;
    state_out = 0; 
    //keystate[SDLK_XXXX]  0 = not pressed   1 = pressed
    //SDL_TEXTINPUT
    //SDL_TEXTEDITING 
    //SDL_StartTextInput() // SDL_StopTextInput()
    //SDL_TextInputRect(SDL_Rect *rect);
    out.x = 30; 
    out.y = 330;
    out.h = 330;
    out.w = 400;
    
    in.x = 30;
    in.y = 620;
    in.h = 20;
    in.w = 400;
    //text_out(out,14,false);
    //text_in(in,14,false);
}

chat::~chat(){
    SDL_FreeSurface(textbox);
    SDL_FreeSurface(inbox);
}

void chat::old_chatting(SDL_Event event){ //handles input from user
    //note: Poll events handle more, not good for efficiency
    //keystate = SDL_GetKeyboardState(NULL); crashes 
    string temp = "";
 
    if(count == 0){
        SDL_StopTextInput();
        count++; 
        set_player("Player1");
    }
    
        switch(event.type)
        {
          case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
              {
                case SDLK_RETURN: //enter / return
                    cout<<"Return key has been pressed"<<endl; //debugging
                    if(!isTyping){
                   SDL_StartTextInput();
                   isTyping = true;
                   }
                   else{
                       SDL_StopTextInput();
                       isTyping = false;
                       cout<<s<<endl;
                       if(s != ""){
                       merge_player_input();
                       input_text(); 
                       show_output();
                       cout<<s<<endl;
                       break_down(10);
                       //text->writeText(88,466,s.c_str(),14);
                       show_result();
                       s = "";
                       clear_vect();}
                   }
                    break;
              
                case SDLK_BACKSPACE: //backspace 
                    s.pop_back(); 
                break;
                
                  case SDLK_t:
                      if(!isTyping){
                      state_out++;     
                      state_out = state_out % 2;
                      }
                      break;
                
                default: 
                    break; 
                }//end event.key.keysym.sym 
   
            case SDL_TEXTINPUT:
                if((int) event.text.text[0] != 1){ //prevents start of heading(aka spaces) Ascii int value 1
                    if(s.size()<Limit)
                    s+= event.text.text; 
                }
               break;
                
            case SDL_TEXTEDITING:
                // event.edit.text;
                // event.edit.start;
                // event.edit.length; 
                break; 
                  
        } 
        toggle(); 
        } 

void chat::merge_player_input(){
    s.insert(0,player);
}

void chat::chatting(){
    //const     // Uint8 * keystate;
    //SDL_PumpEvents(); 
    //error with keystate = SDL_GetKeyboardState();
    keystate = SDL_GetKeyboardState(NULL); 
        
    if(keystate[SDLK_RETURN] && isTyping == true){
            //send message
            //show message
            isTyping = false; 
        }else if(keystate[SDLK_RETURN]){
        isTyping = true;     
        }else if(keystate[SDLK_BACKSPACE]){
            //remove one character from string input
            if(s.length()!= 0)
                  s.pop_back();
            
        }else{
            
            //append input
            //show message
            //don't send message
        }
} 

void chat::show_result(){  
    for(int i = input.size()-1; i>= 0; i--){
    cout<<input.at(i); 
    }
    cout<<endl; 
    
}

string chat::get_vect(int x){
    return input.at(x);  
}

int chat::get_vect_end(){ 
    return (input.size() - 1) ;
}


bool chat::can_type(){
    return isTyping;
}

 string chat::get_input(){
     return s;
       }
 string chat::get_player(){
     return player; 
       }


 
 void chat::break_down(int size){
     int x = s.size();
     cout<<x<<endl; 
     int i;
     string temp;
     for(i = x - size; i> 0; i= i- size){
     temp = "";    
     temp = s.substr(i, size); 
         input.push_back(temp);  
     } 
     cout<<"i"<<i<<endl; 
     input.push_back(s.substr(0,i+size)); //also include the first the string at the end of the vector input
 }
 
 void chat::set_player(string str){
           player = "<" + str + "> ";
       }
 void chat::set_string(string str){
           s = str; 
       }
     
  void chat::clear_vect(){
      while(!input.empty()){
          //cout<<input.back();  //debugging
          input.pop_back(); 
      }
  } 
  
   void chat::show_input(){
      // text_in.draw();
      // keystate = SDL_GetKeyboardState(NULL); 
       show_output(); 
       text->changeColor(255,255,255);
       text->writeText(100,640,s.c_str(),20);
       
     //  if(keystate[SDLK_BACKSPACE]){
     //      text->~Text();
      // }
   }
   
   void chat::show_output(){
       //text_out.draw(); 
       //text->writeText(30,330,s.c_str(),20);
       
       if(output.size()>5)
           output.pop_front(); 
           
       int x = 640;
       for(list<string>::iterator it = output.begin() ; it != output.end() ; it++){
           string temp = *it;
           text->writeText(540,x,temp.c_str(), 20);
           x+= 22; 
       }
   
   
   }
   
   void chat::input_text(){
        if(output.size()>5){
           output.pop_front();
       }else{
       output.push_back(s);
       }
   }
  
   int chat::toggle(){
       return state_out;  
   }
   
   