#include<iostream>
using namespace std;

int n = 9, t, mx = 0, idx;
int main(void){
    for(int i = 0; i < n; i++){
        cin >> t;
        if(mx < t){
            mx = t;
            idx = i + 1;
        }
    }
    cout << mx << '\n' << idx;
    return 0;
}