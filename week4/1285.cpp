#include<iostream>
#include<string>

using namespace std;

int n, board[20], ret = 1e8;
string s;

void solve(int idx){
    if(idx == n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++)
                if(board[j] & (1 << i)) cnt++;
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }
    solve(idx + 1);
    board[idx] = ~board[idx];
    solve(idx + 1);
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        int value = 1;
        for(int j = 0; j < n; j++){
            if(s[j] == 'T')
                board[i] |= value;
            value *= 2;
        }
    }
    solve(0);
    cout << ret;
    return 0;
}