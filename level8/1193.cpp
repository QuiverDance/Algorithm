#include<iostream>
using namespace std;

int x, n, pre;
int main(void){
    cin >> x;
    n = 1;
    while(true){
        if(x > pre && x <= n * (n + 1) / 2) break;
        pre = n / 2 * (n + 1); n++;
    }
    int diff = n * (1 + n) / 2 - x;
    if(n % 2) cout << 1  + diff << "/" << n - diff;
    else cout << n - diff << "/" << 1 + diff;
    return 0;
}