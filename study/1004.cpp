/*
    #1004 어린 왕자
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct _Circle {
    int x, y, r;
} Circle;

int t, n, ret, fx, sx, fy, sy;
// vector<Circle> v;
int main() {
    cin >> t;
    int x, y, r;
    while(t--){
        cin >> fx >> fy >> sx >> sy;
        cin >> n;
        bool flag1, flag2;
        ret = 0;
        for(int i = 0; i < n; i++){
            cin >> x >> y >> r;
            flag1 = pow(x - fx, 2) + pow(y - fy, 2) < pow(r, 2);
            flag2 = pow(x - sx, 2) + pow(y - sy, 2) < pow(r, 2);
            if(flag1 ^ flag2) ret++;
        }
        cout << ret << '\n';
    }
    return 0;
}