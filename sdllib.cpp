#include "mylib.h"
#include "sdllib.h"

void sdldie(const string msg){
    cout << msg << SDL_GetError() << endl;
    SDL_Quit();
    exit(1);
}

void checkSDLError(int line=-1){
    const string error(SDL_GetError());
    if(error.length() > 0){
        cout << "SDL Error:" << error << endl;
        if(line != -1){
            cout << "line: " << line << endl;
        }
        SDL_ClearError();
    }
}

void setupwindow(SDL_Window **window, SDL_GLContext *context,int width,
                 int height){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        sdldie("Unable to init SDL");
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);

  /* Enable multisampling for a nice antialiased effect */
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,4);

    *window = SDL_CreateWindow("young",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                          width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if(window == NULL){
        sdldie("Unable to create window");
    }
    *context = SDL_GL_CreateContext(*window);


    /* Enable Z depth testing so objects closest to the viewpoint are
       in front of objects further away */
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    SDL_GL_SetSwapInterval(1);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (640.0/480.0), 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
