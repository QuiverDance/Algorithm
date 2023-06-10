#include<iostream>
#include<string>

using namespace std;

int n, k, ret;
string s;
int word[50];

int count(int llist){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if((word[i] & llist) == word[i]) cnt++;
    }
    return cnt;
}

void solve(int idx, int lnum, int llist){
    if(lnum < 0) return;
    if(idx == 26){
        ret = max(ret, count(llist));
        return;
    }
    solve(idx + 1, lnum - 1, llist | (1 << idx));
    if(idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a')
        solve(idx + 1, lnum, llist);
}

int main(void){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int c : s)
            word[i] |= (1 << (c - 'a'));
    }
    solve(0, k, 0);
    cout << ret;
    return 0;
}