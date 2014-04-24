#include "chat.h"
#include "SDL2/SDL.h"
//  //
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

void chat::old_chatting(SDL_Event event){ //handles input from user
    //note: Poll events handle more, not good for efficiency
   // SDL_Event event;
    //keystate = SDL_GetKeyboardState(NULL); crashes
    //while(SDL_PollEvent(&event)){
    string temp = "";
    
    //if ( SDL_PollEvent( &event ) ){
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
                  // SDL_StartTextInput();
                   isTyping = true;
                   }
                   else{
                       SDL_StopTextInput();
                       isTyping = false;
                       cout<<"<Player> "<<s<<endl;
                       text->writeText(88,466,s.c_str(),14);
                    }
                    break;
              
                case SDLK_KP_ENTER: //enter from keypad
                    //send message
                    //show message
                    cout<<"Keypad_Return key has been pressed"<<endl; //debugging
                    //if(!isTyping){
                    //SDL_StartTextInput();
                    //isTyping = true;
                    //}
                   // else{
                       //DL_StopTextInput();
                   //     isTyping = false;
                   // }
                    break;
                    
                 
                    
                case SDLK_BACKSPACE: //backspace 
                //if(s.length()!= 0)
                  //s.erase(s.length()-1); //remove character from the end of string
                    s.pop_back(); 
                break;
                
                default: //entered something
                    break; 
                }//end event.key.keysym.sym 
               
                  
            case SDL_TEXTINPUT:
               // s+= (string) event->text.text; crashes
                        //cout<<event->text.text<<endl;
                //if(keystate[SDLK_RETURN]){
                //if(isTyping){
   
                //temp = event->text.text;
                    //cout<<event->text.text<<endl;
                if((int) event.text.text[0] != 1){ //prevents start of heading(aka spaces) Ascii int value 1
                    s+= event.text.text; 
                    
                   // input.writeTextCentered();
                        }
                //cout<<temp;
                //cout<<temp<<endl; 
                //s.append( temp ); 
                 //cout<<"<"<<s<<">"<<endl;
       // }
                  
                
               break;
                
            case SDL_TEXTEDITING:
                // event.edit.text;
                // event.edit.start;
                // event.edit.length; 
                break; 
                  
        } 
    //input.writeText(88,486, s.c_str(),12);
    
   
    
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

void chat::chatting2(){
    SDL_Event event;
    
    if ( SDL_PollEvent( &event ) ){
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
                  // SDL_StartTextInput();
                   isTyping = true;
                   }
                   else{
                       SDL_StopTextInput();
                       isTyping = false;
                       cout<<"<Player> "<<s<<endl;
                    }
                    break;
              
                case SDLK_KP_ENTER: //enter from keypad
                    //send message
                    //show message
                    cout<<"Keypad_Return key has been pressed"<<endl; //debugging
                    //if(!isTyping){
                    //SDL_StartTextInput();
                    //isTyping = true;
                    //}
                   // else{
                       //DL_StopTextInput();
                   //     isTyping = false;
                   // }
                    break;
                    
                 
                    
                case SDLK_BACKSPACE: //backspace 
                //if(s.length()!= 0)
                  //s.erase(s.length()-1); //remove character from the end of string
                    s.pop_back(); 
                break;
                
                default: //entered something
                    break; 
                }//end event.key.keysym.sym 
               
                  
            case SDL_TEXTINPUT:
                    //cout<<event->text.text<<endl;
                if((int) event.text.text[0] != 1){ //prevents start of heading (aka spaces)
                    s+= event.text.text; 
                    //cout<<"<<"<<(int) event->text.text[0]<<">>"<<endl; 
                        }
                           
               break;
                
            case SDL_TEXTEDITING:
                // event.edit.text;
                // event.edit.start;
                // event.edit.length; 
                break; 
                  
        } 
    //input.writeText(88,486, s.c_str(),12);
    
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

