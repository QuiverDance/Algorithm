#include<iostream>
using namespace std;

int n, x, y, mn_x = 10000, mn_y = 10000, mx_x = -10000, mx_y = -10000;
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        mn_x = min(mn_x, x); mn_y = min(mn_y, y);
        mx_x = max(mx_x, x); mx_y = max(mx_y, y);
    }
    cout << (mx_x - mn_x) * (mx_y - mn_y);
    return 0;
}