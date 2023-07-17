#include<iostream>
using namespace std;

int n = 9, a[10][10], mx = 0;
int main(void){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == mx){
                cout << mx << '\n';
                cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }
    return 0;
}