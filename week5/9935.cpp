#include<iostream>
#include<string>

using namespace std;
string s, mask;
string ret;
int main(void){
    cin >> s;
    cin >> mask;
    for(char c : s){
        ret += c;
        if(ret.size() >= mask.size() && ret.substr(ret.size() - mask.size()) == mask){
            ret.erase(ret.size() - mask.size());
        }
    }
    if(!ret.size()) cout << "FRULA";
    else cout << ret;
    return 0;
}