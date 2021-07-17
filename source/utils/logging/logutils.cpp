#include "SDL.h"
#include "logutils.h"

namespace LogUtils
{
    void LogSDLError(std::ostream & os, const std::string & message)
    {
        os << message << " error: " << SDL_GetError() << std::endl;
    }
}
