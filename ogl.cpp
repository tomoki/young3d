#include "mylib.h"
#include "ogl.h"

vii top;
queue<vii> youngs;
int young_size = 0;
int cnt = 0;

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

void draw_line(int n){
    double y = n + 0.5;
    int r = young_size-1;int c = 0;
    glColor3dv(red.data());
    glBegin(GL_LINE_STRIP);
    // start.
    glVertex3d(0,y,young_size);
    for(int i=0;i<young_size*2-1;i++){
        if(r == -1){
            c++;
        }else if(c == young_size){
            r--;
        }else{
            if(top[r][c] > n){
                c++;
            }else{
                r--;
            }
        }
        glVertex3d(c,y,r+1);
    }
    //glVertex3d(young_size,y,young_size);
    glVertex3d(young_size,y,0);
    glEnd();
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
    for(int n=0;n<young_size;n++){
        draw_line(n);
    }
    glutSwapBuffers();
}

void handleKey(unsigned char key,int x,int y){
    if(key == 'n'){
        top = next_young();
        //cout << cnt << " " << top << endl;
    }else if(key == 'c'){
        young_size = 0;
        cnt = 0;
        queue<vii> emp;
        swap(youngs,emp);
    }
}

vii next_young(){
    if(youngs.empty()){
        young_size++;
        // 5 is too big!
        if(young_size == 5) young_size = 1;
        cnt = 0;
        vii initial(young_size,vi(young_size));
        vector<vii> ys;
        get_young(young_size,ys,initial,0,0);
        for(const vii& v : ys){
            youngs.push(v);
        }
    }
    vii t = youngs.front();
    cnt++;
    youngs.pop();
    cout << cnt << " " << top << endl;
    return top=t;
}

void handleMouse(int button,int state,int x,int y){
    switch (button) {
    case GLUT_LEFT_BUTTON:

        break;
    default:
        break;
    }

    switch (state) {
    case GLUT_UP:
        break;
    case GLUT_DOWN:
        next_young();
        break;
    default:
        break;
    }
    //printf(" at (%d, %d)\n", x, y);
}
