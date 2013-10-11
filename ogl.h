#ifndef OGL_H
#define OGL_H

#include "mylib.h"
#include "young.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const int FPS = 60;


bool initGL();
void update();
void render();
void resize(int,int);
void handleKey(unsigned char,int,int);
void handleMouse(int,int,int,int);
vii next_young();

//. http://www.wakayama-u.ac.jp/~tokoi/opengl/libglut.html#6
const vector<vector<double>> vertex = {
    { 0.0, 0.0, 0.0 }, /* A */
    { 1.0, 0.0, 0.0 }, /* B */
    { 1.0, 1.0, 0.0 }, /* C */
    { 0.0, 1.0, 0.0 }, /* D */
    { 0.0, 0.0, 1.0 }, /* E */
    { 1.0, 0.0, 1.0 }, /* F */
    { 1.0, 1.0, 1.0 }, /* G */
    { 0.0, 1.0, 1.0 }  /* H */
};

const vector<vector<int> > edge = {
    { 0, 1 }, /*  (A-B) */
    { 1, 2 }, /*  (B-C) */
    { 2, 3 }, /*  (C-D) */
    { 3, 0 }, /*  (D-A) */
    { 4, 5 }, /*  (E-F) */
    { 5, 6 }, /*  (F-G) */
    { 6, 7 }, /*  (G-H) */
    { 7, 4 }, /*  (H-E) */
    { 0, 4 }, /*  (A-E) */
    { 1, 5 }, /*  (B-F) */
    { 2, 6 }, /*  (C-G) */
    { 3, 7 }  /*  (D-H) */
};

const vector<vector<int>> face = {
    { 0, 1, 2, 3 },
    { 1, 5, 6, 2 },
    { 5, 4, 7, 6 },
    { 4, 0, 3, 7 },
    { 4, 5, 1, 0 },
    { 3, 2, 6, 7 }
};

const vector<vector<GLdouble>> facecolor = {
    { 1.0, 0.0, 0.0 },
    { 0.0, 1.0, 0.0 },
    { 0.0, 0.0, 1.0 },
    { 1.0, 1.0, 0.0 },
    { 1.0, 0.0, 1.0 },
    { 0.0, 1.0, 1.0 }
};

#endif
