/*
    #17413 단어 뒤집기 2
*/
#include <iostream>
#include <string>
using namespace std;

string str, ret, buffer;
int flag;
int main() {
    getline(cin, str);
    for(char c : str){
        if(c == ' '){
            ret = ret + buffer + " ";
            buffer = "";
            continue;
        }
        if(c == '<') flag = 1;
        if(flag)
            buffer += c;
        else
            buffer = c + buffer;
        if(c == '>') {
            flag = 0;
            ret = ret + buffer;
            buffer = "";
        }
    }
    ret += buffer;
    cout << ret;
    return 0;
}