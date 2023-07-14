#include<iostream>
using namespace std;

int n, t, a[104], cnt;
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> t;
    for(int i = 0; i < n; i++){
        if(a[i] == t) cnt++;
    }
    cout << cnt;
    return 0;
}