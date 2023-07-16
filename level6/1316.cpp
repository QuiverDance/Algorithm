#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int t, a[26], cnt;
string s;
int main(void){
    cin >> t;
    while(t--){
        memset(a, 0, sizeof(a));
        int pre = -1, flag = 0;
        cin >> s;
        for(char c : s){
            if(pre != c - 'a') a[pre] = 1;
            if(a[c - 'a']) {flag = 1; break;}
            pre = c - 'a';
        }
        if(!flag) cnt++;
    }
    cout << cnt;
    return 0;
}