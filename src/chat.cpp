#include "chat.h"
#include "SDL2/SDL.h"

using namespace std;

chat::chat(){
    s = "";
    //in = "";
    //out = "";
    player = "Player1";
    textbox = NULL; //output
    inbox = NULL;   //input
    keystate = NULL;
    isTyping = false; 
    //keystate[SDLK_XXXX]  0 = not pressed   1 = pressed
    //SDL_TEXTINPUT
    //SDL_TEXTEDITING 
    //SDL_StartTextInput() // SDL_StopTextInput()
    //SDL_TextInputRect(SDL_Rect *rect);
}

chat::~chat(){
    SDL_FreeSurface(textbox);
    SDL_FreeSurface(inbox);
}

void chat::old_chatting(){ //handles input from user
    SDL_Event event;
    
    while(SDL_PollEvent(&event)){
        switch(event.type)
        {
          case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
              {
                  
                case SDLK_RETURN: //enter / return
                    //send message
                    //show message
                    cout<<"Return key has been pressed"<<endl; //debugging
                    if(!isTyping){
                    SDL_StartTextInput();
                    isTyping = true;
                    }
                    else{
                        SDL_StopTextInput();
                        isTyping = false;
                    }
                    break;
              
                case SDLK_KP_ENTER: //enter from keypad
                    //send message
                    //show message
                    cout<<"Keypad_Return key has been pressed"<<endl; //debugging
                    if(!isTyping){
                    SDL_StartTextInput();
                    isTyping = true;
                    }
                    else{
                        SDL_StopTextInput();
                        isTyping = false;
                    }
                    break;
                    
                 
                    
                case SDLK_BACKSPACE: //backspace 
                if(s.length()!= 0)
                  s.erase(s.length()-1); //remove character from the end of string
                break;
                
                default: //entered something
                
                
                    break;
              }//end event.key.keysym.sym
                
                  break;
                  
            case SDL_TEXTINPUT:
                s += event.text.text;
                
                break;
                
            case SDL_TEXTEDITING:
                // event.edit.text;
                // event.edit.start;
                // event.edit.length; 
                break; 
                  
        } //end SDL_KEYDOWN
    
    }
    
    
    //ss<<str;
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
                  s.erase(s.length()-1);
            
        }else{
            
            //append input
            //show message
            //don't send message
        }
        
    
    
    
    
}


void chat::show_message(string str){
   // SDL_FreeSurface(textbox);
    
 //   textbox = TTF_RenderText_Solid(12,s,12);
}

void chat::send_message(string str){
    
    
}

void chat::show_result(){
    
    
}

void chat::run(){
    
    
    
    
    
   
}

void chat::can_type(bool x){
    
    
}

