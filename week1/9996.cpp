#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> split(string input, string deleimeter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(deleimeter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + deleimeter.length());
    }
    ret.push_back(input);
    return ret;
}

int n;
int main(void){
    cin >> n;
    
    string pat;
    cin >> pat;

    vector<string> pattern = split(pat, "*");
    string temp;
    int flen, slen, len;
    for(int i = 0; i < n; i++){
        cin >> temp;
        len = temp.size();
        flen = pattern[0].size();
        slen = pattern[1].size();
        if(flen > len - slen || pattern[0] != temp.substr(0, flen) || pattern[1] != temp.substr(len - slen, slen))
            cout << "NE" << '\n';
        else
            cout << "DA" << '\n';
    }
    return 0;
}