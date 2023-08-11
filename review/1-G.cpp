#include<iostream>
#include<string>
using namespace std;

int n, flag, pos;
string pat, s;
int main(void){
    cin >> n >> pat;
    pos = pat.find("*");
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s.length() + 1 < pat.size()){
            cout << "NE\n"; continue;
        }
        flag = 0;
        if(s.substr(0, pos) != pat.substr(0, pos)) flag = 1;
        if(s.substr(s.length() - ( pat.size() - pos ) + 1) != pat.substr(pos + 1)) flag = 1;
        if(flag == 1) cout << "NE\n";
        else cout << "DA\n";
    }
    return 0;
}