#include<iostream>
using namespace std;

int a0, a1, c, n0;
int main(void){
    cin >> a1 >> a0 >> c >> n0;
    if(a1 * n0 + a0 <= c * n0 && a1 <= c) cout << 1;
    else cout << 0;
    return 0;
}
