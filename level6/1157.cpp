#include<iostream>
#include<string>
using namespace std;

string s;
int a[26];
int main(void){
    cin >> s;
    for(char c : s){
        if(c >= 'a') a[c - 'a']++;
        else a[c - 'A']++;
    }
    int mx = 0, cnt = 0, idx;
    for(int i = 0; i < 26; i++) mx = max(mx, a[i]);
    for(int i = 0; i < 26; i++) if(mx == a[i]) {cnt++; idx = i;};
    if(cnt > 1) cout << "?";
    else cout << (char)(idx + 'A');
    return 0;
}