#include<iostream>
using namespace std;

int n, x, t;
int main(void){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(t < x) cout << t << " ";
    }
    return 0;
}