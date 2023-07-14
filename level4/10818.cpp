#include<iostream>
using namespace std;

int n, t, mx = -1e8, mn = 1e8;
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        mx = max(mx, t);
        mn = min(mn, t);
    }
    cout << mn << " " << mx;
    return 0;
}