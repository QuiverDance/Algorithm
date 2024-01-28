/*
    #1002 터렛
*/
#include<iostream>
using namespace std;

int t, x1, x2, y1, y2, r1, r2, d, rd1, rd2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if(d == 0 && r1 == r2) 
            cout << -1 << '\n';
        else if((r1 - r2) * (r1 - r2) == d || d == (r1 + r2) * (r1 + r2))
            cout << 1 << '\n';
        else if((r1 - r2) * (r1 - r2) < d && d < (r1 + r2) * (r1 + r2))
            cout << 2 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}