#include "mylib.h"
#include "ogl.h"

bool initGL(){
    //Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutInitDisplayMode(GLUT_RGBA);

    // Initialize ModelView Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    // glEnable(GL_LIGHTING);
    // glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glLineWidth(3);

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_BACK);

    glClearColor(1.f,1.f,1.f,1.f);
    GLenum error = glGetError();
    if(error != GL_NO_ERROR){
        cerr << "Error initializing OpenGl." << gluErrorString(error) << endl;
        return false;
    }
    return true;
}

void resize(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
    gluLookAt(9.0, 12.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void update(){
}

void cube(GLdouble x,GLdouble y,GLdouble z){
    glPushMatrix();
    glTranslated(x,z,y);
    glColor3d(0,0,0);
    glBegin(GL_LINES);
    for(int i=0;i<12;i++){
        glVertex3dv(vertex[edge[i][0]].data());
        glVertex3dv(vertex[edge[i][1]].data());
    }
    glEnd();

    // /* 図形の描画 */
    // glColor3d(0.3, 0.0, 0.0);
    // glBegin(GL_QUADS);

    // for (int j= 0; j < 6; ++j) {
    //     // glColor3dv(facecolor[j].data());
    //     for (int i = 0; i < 4; ++i) {
    //         glVertex3dv(vertex[face[j][i]].data());
    //     }
    // }
    // glEnd();

    glPopMatrix();
}

void render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(int y=0;y<young_size;y++){
        for(int x=0;x<young_size;x++){
            for(int z=0;z<top[y][x];z++){
                cube(x,y,z);
            }
        }
    }
    glutSwapBuffers();
}

void handleKey(unsigned char key,int x,int y){
    if(key == 'n'){
        top = next_young();
    }
}

vii next_young(){
    if(youngs.empty()){
        young_size++;
        // 5 is too big!
        if(young_size == 5) young_size = 1;
        vii initial(young_size,vi(young_size));
        vector<vii> ys;
        get_young(young_size,ys,initial,0,0);
        for(const vii& v : ys){
            youngs.push(v);
        }
    }
    vii t = youngs.front();
    youngs.pop();
    return t;
}

void handleMouse(int button,int state,int x,int y){
    switch (button) {
    case GLUT_LEFT_BUTTON:
        printf("left");
        break;
    case GLUT_MIDDLE_BUTTON:
        printf("middle");
        break;
    case GLUT_RIGHT_BUTTON:
        printf("right");
        break;
    default:
        break;
    }

    printf(" button is ");

    switch (state) {
    case GLUT_UP:
        printf("up");
        break;
    case GLUT_DOWN:
        printf("down");
        break;
    default:
        break;
    }

    printf(" at (%d, %d)\n", x, y);
}
