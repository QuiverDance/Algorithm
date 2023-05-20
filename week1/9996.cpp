#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n;
string pre, suf;
int main(void){
    cin >> n;
    string s;
    cin >> s;

    int pos = s.find("*");
    pre = s.substr(0, pos);
    suf = s.substr(pos + 1);

    string temp;
    int len;
    for(int i = 0; i < n; i++){
        cin >> temp;
        len = temp.size();
        if(pre.size() + suf.size() > len || pre != temp.substr(0, pre.size()) || suf != temp.substr(len - suf.size()))
            cout << "NE" << '\n';
        else
            cout << "DA" << '\n';
    }
    return 0;
}