#include<iostream>
using namespace std;

int n = 10, a[42], t, cnt;
int main(void){
    for(int i = 0; i < n; i++){
        cin >> t;
        a[t % 42] = 1;
    }
    for(int i = 0; i < 42; i++)
        if(a[i]) cnt++; 
    cout << cnt;   
    return 0;
}