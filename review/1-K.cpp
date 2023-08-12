#include<iostream>
#include<string>
using namespace std;

int a[26];
string s, ret = "";

int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++) a[s[i] - 'A']++;
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if(a[i] % 2){
            ret += (char)(i + 'A'); cnt++;
            a[i]--;
        }
    }
    if(cnt > 1){
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }
    for(int i = 25; i >= 0; i--){
        for(int j = 0; j < a[i] / 2; j++){
            ret = (char)(i + 'A') + ret;
            ret += (char)(i + 'A');
        }
    }
    cout << ret;
    return 0;
}