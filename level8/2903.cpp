#include<iostream>
using namespace std;

int n, a[19], pre, k, cnt;
int main(void){
    cin >> n;
    a[0]= 4; a[1] = 9;
    k = 4; pre = 3; cnt = 2;
    for(int i = 2; i <= n; i++){
        a[i] = a[i - 1] + 2 * (cnt * pre) + k;
        k *= 4; pre += cnt; cnt *= 2;
    }
    cout << a[n];
    return 0;
}