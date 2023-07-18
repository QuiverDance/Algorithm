#include<iostream>
using namespace std;

int num[] = {25, 10, 5, 1}, t, n;
int main(void){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < 4; i++){
            cout << n / num[i] << " ";
            n -= num[i] * (n / num[i]);
        }
        cout << '\n';
    }
    return 0;
}