#include "mylib.h"
#include "sdllib.h"

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;

int main(){
    SDL_Window *mw;
    SDL_GLContext mc;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        sdldie("Unable to init SDL");
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);


    mw = SDL_CreateWindow("young",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                          WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if(mw == NULL){
        sdldie("Unable to create window");
    }
    checkSDLError(__LINE__);

    mc = SDL_GL_CreateContext(mw);

    SDL_GL_SetSwapInterval(1);

    // RED
    glClearColor(1.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(mw);
    SDL_Delay(2000);

    /* Same as above, but blue */
    glClearColor ( 0.0, 0.0, 1.0, 1.0 );
    glClear ( GL_COLOR_BUFFER_BIT );
    SDL_Delay(2000);

    /* Delete our opengl context, destroy our window, and shutdown SDL */
    SDL_GL_DeleteContext(mc);
    SDL_DestroyWindow(mw);
    SDL_Quit();


    return 0;
}
