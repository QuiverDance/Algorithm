#include<iostream>
using namespace std;

int a[3];
int main(void){
    for(int i = 0; i < 3; i++) cin >> a[i];
    if(a[0] == a[1] && a[1] == a[2]){ cout << a[0] * 3; return 0; }
    int mx = max(a[0], max(a[1], a[2]));
    if(mx < a[0] + a[1] + a[2] - mx){ cout << a[0] + a[1] + a[2]; }
    else cout << (a[0] + a[1] + a[2] - mx) * 2 - 1;
    return 0;
}