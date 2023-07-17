#include<iostream>
#include<string>
using namespace std;

int n = 5;
string a[5];
int main(void){
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < 15; j++){
        for(int i = 0; i < n; i++){
            if(a[i].length() <= j) continue;
            cout << (char)a[i][j];
        }
    }
    return 0;
}