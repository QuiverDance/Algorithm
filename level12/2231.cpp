#include<iostream>
using namespace std;

int n, k;
int main(void){
    cin >> n;
    for(k = 1; k <= 1000000; k++){
        int sum = 0, t = k;
        while(t > 0){
            sum += t % 10; t /= 10;
        }
        if(k + sum == n) break;
    }
    if(k == 1000001) cout << 0;
    else cout << k;
    return 0;
}