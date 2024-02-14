/*
    #17626 Four Squares
*/
#include<iostream>
using namespace std;

int n, a[50004];
int main(){
    cin >> n;
    fill(a, a + 50004, 4);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j * j > i) break;
            a[j * j] = 1;
            a[i] = min(a[i], a[i - (j * j)] + 1);
        }
    }
    cout << a[n];
    return 0;
}