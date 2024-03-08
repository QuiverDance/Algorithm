/*
    #16953 A -> B
*/
#include<iostream>
using namespace std;

int a, b, ret;
int main(){
    cin >> a >> b;
    while(a != b){
        if(a > b){ ret = -2; break; }
        if(b % 10 == 1){ b /= 10; ret++; }
        else if(b % 2 == 0) { b /= 2; ret++; }
        else{ ret = -2; break; }
    }
    cout << ret + 1;
    return 0;
}