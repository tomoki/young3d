#include "mylib.h"
#include "ogl.h"

using namespace std;

void runMainLoop(int val){
    next_young();
    update();
    render();
    glutTimerFunc(1000/FPS,runMainLoop,0);
}

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitContextVersion(2,1);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Young");

    if(not initGL()){
        cerr << "opengl error" << endl;
        return 1;
    }
    glutKeyboardFunc(handleKey);
    glutMouseFunc(handleMouse);
    glutDisplayFunc(render);
    glutReshapeFunc(resize);
    glutTimerFunc(1000/FPS,runMainLoop,0);
    glutMainLoop();
    return 0;
}
