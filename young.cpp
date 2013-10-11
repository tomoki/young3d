#include "mylib.h"

typedef vector<int> vi;
typedef vector<vi> vii;

ostream& operator<<(ostream& os,const vii& matrix){
    // remember row and columns are same size.
    cout << "[" << endl;
    int n = matrix.size();
    for(int i=0;i<n;i++){
        cout << "[";
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << ",";
        }
        cout << "]" << endl;
    }
    cout << "]";
    return os;
}

void get_young(const int N,vector<vii> &all_young,vii & matrix,int r=0,int c=0){
    int upper = N;
    if(r > 0) upper = min(upper,matrix[r-1][c]);
    if(c > 0) upper = min(upper,matrix[r][c-1]);

    int nr,nc;
    if(r == N-1 and c == N-1){
        nr = -1;
        nc = -1;
    }else if(r == N-1){
        nr=0;nc=c+1;
    }else{
        nr=r+1;nc=c;
    }
    for(int n=0;n<=upper;n++){
        matrix[r][c] = n;
        if(nr == -1 and nc == -1){
            all_young.push_back(matrix);
        }else{
            get_young(N,all_young,matrix,nr,nc);
        }
    }
    return;
}

// int main(){
//     int N = 5;
//     vector<vii> v;
//     vii init(N,vi(N));
//     get_young(N,v,init);
//     // for(const vii& a : v){
//     //     cout << a << endl;
//     // }
//     cout << v.size() << endl;

//     return 0;
// }
