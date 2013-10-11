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
