#include<iostream>
#include<cmath>
using namespace std;

int t, x1, x2, y1, y2, r1, r2, d, rd;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = pow(x1 - x2, 2) + pow(y1 - y2, 2);
        rd = pow(r1 + r2, 2);
        if(d > rd) cout << 0 << '\n';
        
    }

}