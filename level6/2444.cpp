#include<iostream>
using namespace std;

int n, b, s;
int main(void){
    cin >> n;
    for(int i = 0; i < 2 * n - 1; i++){
        if(i < n){ b = n - 1 - i; s = 2 * i + 1; }
        else{ b = i - n + 1; s = (2 * n - 1) - 2 * (i % n + 1); }
        for(int j = 0; j < b; j++) cout << " ";
        for(int j = 0; j < s; j++) cout << "*";
        cout << '\n';
    }
    return 0;
}