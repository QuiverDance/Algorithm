#include<iostream>
#include<vector>
using namespace std;

typedef struct _Shark{
    int r, c, s, d, z;
}Shark;

int r, c, m, a[104][104], ret;
vector<Shark> v;
int main(){
    cin >> r >> c >> m;
    int t1, t2, t3, t4, t5;
    for(int i = 0; i < m; i++){
        cin >> t1 >> t2 >> t3 >> t4 >> t5;
        Shark sh;
        sh.r = t1; sh.c = t2; sh.s = t3; sh.d = t4; sh.z = t5;
        v.push_back(sh);
    }
    return 0;
}