#include<iostream>
#include<string>
using namespace std;

int k, visited[10];
char oper[10];
string mx = "0", mn = "9999999999";

bool validation(int idx, int a, int b){
    if(oper[idx] == '>')
        return a > b;
    else
        return a < b;
}

void solve(int idx, string s){
    if(idx == k){
        mx = max(mx, s);
        mn = min(mn, s);
        return;
    }
    for(int i = 0; i < 10; i++){
        if(visited[i]) continue;
        if(validation(idx, s[idx] - '0', i)){
            visited[i] = 1;
            solve(idx + 1, s += to_string(i));
            s.pop_back();
            visited[i] = 0;
        }
    }
}
int main(){
    cin >> k;
    for(int i = 0; i < k; i++) cin >> oper[i];

    for(int i = 0; i < 10; i++){
        visited[i] = 1;
        solve(0, to_string(i));
        visited[i] = 0;
    }
    cout << mx << '\n' << mn;
    return 0;
}