#include<iostream>

using namespace std;

int a, b;
int main(void){
    cin >> a >> b;
    cout << a * (b % 10) << '\n';
    cout << a * (b % 100 - b % 10) / 10 << '\n';
    cout << a * (b / 100) << '\n';
    cout << a * b;
    return 0;
}