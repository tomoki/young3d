#ifndef SDLLIB_H
#define SDLLIB_H
#include "mylib.h"

void sdldie(const string);
void checkSDLError(int);
void setupwindow(SDL_Window**,SDL_GLContext*,int,int);

#endif
