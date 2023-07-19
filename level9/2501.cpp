#include<iostream>
using namespace std;

int n, k, cnt, a[10000];
int main(void){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        if(n % i == 0){cnt++; a[cnt] = i;}
    if(cnt < k) cout << 0;
    else cout << a[k];
    return 0;
}