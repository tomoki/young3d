#include "mylib.h"
#include "ogl.h"


bool initGL(){
    //Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    // Initialize ModelView Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.f,0.f,0.f,1.f);
    GLenum error = glGetError();
    if(error != GL_NO_ERROR){
        cerr << "Error initializing OpenGl." << gluErrorString(error) << endl;
        return false;
    }
    return true;
}

void update(){
}


void render(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f,-0.5f);
    glVertex2f(0.5f,-0.5f);
    glVertex2f(0.5f,0.5f);
    glVertex2f(-0.5f,0.5f);
    glEnd();

    glutSwapBuffers();
}
