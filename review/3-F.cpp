#include<iostream>
#include<string>
using namespace std;

int n, ret = -1e9;
string s;
int cal(int a, int b, char oppr){
    if(oppr == '+') return a + b;
    else if(oppr == '-') return a - b;
    else if(oppr == '*') return a * b;
}

void solve(int idx, int sum){
    if(idx >= n - 1){
        ret = max(ret, sum);
        return;
    }
    solve(idx + 2, cal(sum, s[idx + 2] - '0', s[idx + 1]));
    if(idx + 4 < n)
        solve(idx + 4, cal(sum, cal(s[idx + 2] - '0', s[idx + 4] - '0', s[idx + 3]), s[idx + 1]));
}

int main(){
    cin >> n;
    cin >> s;
    solve(0, s[0] - '0');
    cout << ret;
    return 0;
}