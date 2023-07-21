#include<iostream>
using namespace std;

int a[1004], b[1004], x, y;
int main(void){
    for(int i = 0; i < 3; i++){
        cin >> x >> y;
        a[x]++; b[y]++;
    }
    for(int i = 0; i < 1004; i++){
        if(a[i] == 1){
            cout << i << " "; break;
        }
    }
    for(int i = 0; i < 1004; i++){
        if(b[i] == 1){
            cout << i; break;
        }
    }
    return 0;
}