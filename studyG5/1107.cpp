/*
    #1107 리모컨
*/
#include<iostream>
#include<string>
using namespace std;

int n, m, valid[14], ret;
void solve(string s){
    if(s.length() > 6){ return;}
    if(s != "")
        ret = min(ret, (int)s.length() + abs(stoi(s) - n));
    for(int i = 0; i < 10; i++){
        if(valid[i]) continue;
        s.push_back(i + '0');
        solve(s);
        s.pop_back();
    }
}

int main() {
    cin >> n >> m;
    if(m > 0){
        int num;
        for(int i = 0; i < m; i++){
            cin >> num; valid[num] = 1;
        }
    }
    ret = abs(n - 100);
    solve("");
    cout << ret;
    return 0;
}