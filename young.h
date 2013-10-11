#ifndef YOUNG_H
#define YOUNG_H
#include "mylib.h"
ostream& operator<<(ostream& os,const vector<vector<int>>&);
// do not call for 5!
void get_young(const int,vector<vector<vector<int>>>&,
                   vector<vector<int>>&,int,int);
#endif
