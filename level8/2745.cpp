#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;
int b, ret;
int main(void){
    cin >> s >> b;
    reverse(s.begin(), s.end());
    int k = 1;
    for(char c : s){
        if(c >= 'A') ret += (c - 'A' + 10) * k;
        else ret += (c - '0') * k;
        k *= b;
    }
    cout << ret;
    return 0;
}