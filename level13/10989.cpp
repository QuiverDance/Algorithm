#include<iostream>
using namespace std;

int n, t, a[10004];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){ cin >> t; a[t]++; }
    for(int i = 1; i <= 10000; i++){
        for(int j = 0; j < a[i]; j++) cout << i << '\n';
    }
    return 0;
}