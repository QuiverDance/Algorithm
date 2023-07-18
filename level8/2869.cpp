#include<iostream>
using namespace std;

int a, b, v;
int main(void){
    cin >> a >> b >> v;
    int ret = (v - a) / (a - b) + 1;
    if((v - a) % (a - b)) ret++;
    cout << ret;
    return 0;
}