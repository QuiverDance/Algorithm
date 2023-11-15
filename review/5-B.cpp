#include<iostream>
#include<string>
using namespace std;

string s, m, ret = "";
int main(){
    cin >> s >> m;
    for(int i = 0; i < s.size(); i++){
        ret += s[i];
        if(ret.size() >= m.size() && ret.substr(ret.size() - m.size()) == m){
            ret.erase(ret.size() - m.size());
        }
    }
    if(ret.size()){
        cout << ret;
    }
    else cout << "FRULA";
    return 0;
}