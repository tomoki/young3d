#ifndef YOUNG_H
#define YOUNG_H
#include "mylib.h"

typedef vector<int> vi;
typedef vector<vi> vii;

ostream& operator<<(ostream& os,const vii&);
// do not call for 5!
void get_young(const int,vector<vii>&,vii&,int,int);
#endif
