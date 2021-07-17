#include "SDL.h"
#include "log.h"

void logSDLError(std::ostream & os, const std::string & message)
{
    os << message << " error: " << SDL_GetError() << std::endl;
}
