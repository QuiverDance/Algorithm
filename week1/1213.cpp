#include<iostream>
#include<string>

using namespace std;

int cnt[26];
int flag = 0;
char mid;
string s, ret;
int main(void){
    cin >> s;
    for(auto it : s) cnt[it-'A']++;
    for(int i = 'Z'; i >= 'A'; i--){
        if(cnt[i-'A'] % 2 == 1){
            mid = char(i);
            flag++; cnt[i-'A']--;
        }
        if(flag == 2) break;
        for(int j = 0; j < cnt[i-'A']; j+=2){
            ret = char(i) + ret;
            ret += char(i);
        }
    }
    if(mid)
        ret.insert(ret.begin() + ret.size()/2, mid);
    
    if(flag == 2)
        cout << "I'm Sorry Hansoo";
    else
        cout << ret;
    return 0;
}