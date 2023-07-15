#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int cnt;
string s;
int main(void){
    getline(cin, s);
    if(s.length() == 0){ cout << 0; return 0;}
    if(s.length() == 1 && s[0] == ' '){ cout << 0; return 0;}

    if(s[0] == ' ') s[0] = 'a';
    if(s[s.length() - 1] == ' ') s[s.length() - 1] = 'a';
    cnt = 1;
    for(char c : s){
        if(c == ' ') cnt++;
    } 
    cout << cnt;
    return 0;
}