#include "net.h"
#include "Command.h"

command::command()
{
}

command::~command()
{
}

void command::setSocket(int sockfd)
{
    sock = sockfd;
}

int command::getSocket()
{
    return sock;
}

//for player commands

void command::push(SDL_Event event, bool multiPlayer)
{
    switch ( event.type )
    {
	case (SDL_KEYDOWN ):
	    switch ( event.key.keysym.sym )
	    {
		case SDLK_w:
		    strcpy(slfCmd, "Up");
		    break;
		case SDLK_s:
		    strcpy(slfCmd, "Down");
		    break;
		case SDLK_a:
		    strcpy(slfCmd, "Left");
		    break;
		case SDLK_d:
		    strcpy(slfCmd, "Right");
		    break;
		case SDLK_j:
		    strcpy(slfCmd, "Shoot");
		    break;
		default:
		    strcpy(slfCmd, "nil");
		    break;
	    }
	    break;
	case (SDL_KEYUP ):
	    switch ( event.key.keysym.sym )
	    {
		case SDLK_w:
		    strcpy(slfCmd, "Down");
		    break;
		case SDLK_s:
		    strcpy(slfCmd, "Up");
		    break;
		case SDLK_a:
		    strcpy(slfCmd, "Right");
		    break;
		case SDLK_d:
		    strcpy(slfCmd, "Left");
		    break;
		default:
		    strcpy(slfCmd, "nil");
		    break;
	    }
	    break;
	default:
	    strcpy(slfCmd, "nil");
	    break;
    }
    if ( multiPlayer ) send(sock, slfCmd, 16, 0);
}

//for other player commands

void command::take()
{
    recv(sock, othCmd, 16, 0);
}