/*
    #1759 암호 만들기
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<char> v;
void solve(int idx, string s){
    if(s.length() == n){
        int ja = 0, mo = 0;
        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') mo++;
            else ja++;
        }
        if(ja >= 2 && mo >= 1) cout << s << '\n';
        return;
    }
    for(int i = idx; i < m; i++){
        s.push_back(v[i]);
        solve(i + 1, s);
        s.pop_back();
    }
}

int main(){
    cin >> n >> m;
    char c;
    for(int i = 0; i < m; i++){
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    string s = "";
    solve(0,s);
    return 0;
}