#include<iostream>
using namespace std;

int n = 28, a[31], t;
int main(void){
    for(int i = 0; i < n; i++){
        cin >> t;
        a[t] = 1;
    }
    for(int i = 1; i <= 30; i++)
        if(!a[i]) cout << i << '\n';    
    return 0;
}