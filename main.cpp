#include "mylib.h"
#include "sdllib.h"

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;
const int FPS = 60;

void handle_key_down(SDL_Keysym* keysym){
    switch(keysym->sym){
    case SDLK_ESCAPE:
        sdldie("escape pressed");
        break;
    default:
        break;
    }
}

void process_events(){
    /* Our SDL event placeholder. */
    SDL_Event event;
    /* Grab all the events off the queue. */
    while(SDL_PollEvent(&event)){
        switch( event.type ) {
        case SDL_KEYDOWN:
            /* Handle key presses. */
            handle_key_down( &event.key.keysym );
            break;
        case SDL_QUIT:
            /* Handle quit requests (like Ctrl-c). */
            sdldie("quit with close?");
            break;
        }

    }

}

float rotation = 0.0f;
void drawyoung(SDL_Window *window){
 /* Clear our buffer with a red background */
    // glClearColor ( 1.0, 0.0, 0.0, 1.0 );
    // glClear ( GL_COLOR_BUFFER_BIT );
    // /* Swap our back buffer to the front */
    // SDL_GL_SwapWindow(window);
    // /* Wait 2 seconds */
    // SDL_Delay(2000);

    // /* Same as above, but green */
    // glClearColor ( 0.0, 1.0, 0.0, 1.0 );
    // glClear ( GL_COLOR_BUFFER_BIT );
    // SDL_GL_SwapWindow(window);
    // SDL_Delay(2000);

    // /* Same as above, but blue */
    // glClearColor ( 0.0, 0.0, 1.0, 1.0 );
    // glClear ( GL_COLOR_BUFFER_BIT );
    // SDL_GL_SwapWindow(window);
    // SDL_Delay(2000);

    /****** Draw Rectangle ******/
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(0.0f, 0.0f, -6.0f);
    glRotatef(rotation, 1.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);

    /* Cube Top */
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);


    /* Cube Bottom */
    glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    /* Cube Front */
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    /* Cube Back */
    glColor4f(0.0f, 1.0f, 0.5f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    /* Cube Left Side */
    glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    /* Cube Right Side */
    glColor4f(0.15f, 0.25f, 0.75f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);


    glEnd();
    glLoadIdentity();

    rotation -= 0.5f;
}



void main_loop(SDL_Window *mw,SDL_GLContext &mc){
    process_events();
    drawyoung(mw);
    SDL_GL_SwapWindow(mw);
}

int main(){
    SDL_Window *mw;
    SDL_GLContext mc;

    setupwindow(&mw,&mc,WIDTH,HEIGHT);
    const int interval = 1000 / FPS;
    int nextTime = SDL_GetTicks() + interval;
    while(true){
        main_loop(mw,mc);
        int delay = nextTime - SDL_GetTicks();
        if(delay > 0){
            SDL_Delay(delay);
        }
        nextTime = SDL_GetTicks() + interval;
    }

    /* Delete our opengl context, destroy our window, and shutdown SDL */
    SDL_GL_DeleteContext(mc);
    SDL_DestroyWindow(mw);
    SDL_Quit();



    return 0;
}
