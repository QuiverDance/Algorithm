#include<iostream>
using namespace std;

int a, b;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        cout << a + b << '\n';
    }   
    return 0;
}