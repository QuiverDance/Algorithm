#include<iostream>
#include<string>
using namespace std;

int cnt;
string s;
int main(void){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        cnt++;
        if(i + 1 >= s.length()) continue;
        if(s[i] == 'c' && (s[i + 1] == '=' || s[i + 1] == '-')) i += 1;
        else if(s[i] == 'd'){
            if(s[i + 1] == '-') i += 1;
            else if(i + 2 < s.length() && s[i + 1] == 'z' && s[i + 2] == '=') i += 2;
        }
        else if(s[i] == 'l' && s[i + 1] == 'j') i += 1;
        else if(s[i] == 'n' && s[i + 1] == 'j') i += 1;
        else if(s[i] == 's' && s[i + 1] == '=') i += 1;
        else if(s[i] == 'z' && s[i + 1] == '=') i += 1;
    }
    cout << cnt;
    return 0;
}