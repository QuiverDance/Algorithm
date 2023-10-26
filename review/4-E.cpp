#include<iostream>
using namespace std;

int n, l, a[104][104], b[104][104];

int solve(int t[104][104]){
    int ret = 0;
    for(int i = 0; i < n; i++){
        int cnt = 1;
        for(int j = 1; j < n; j++){
            if(t[i][j] == t[i][j - 1]) cnt++;
            else if(t[i][j] == t[i][j - 1] + 1 && cnt >= l){
                cnt = 1;
            }
            else if(t[i][j] + 1 == t[i][j - 1] && cnt >= 0){
                cnt = -l + 1;
            }
            else {
                cnt = -1; break;
            }
        }
        if(cnt >= 0) {
            ret++;
        }
    }
    return ret;
}

int main(){
    cin >> n >> l;
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            a[i][j] = num;
            b[j][i] = num;
        }
    }
    cout << solve(a) + solve(b);
    return 0;
}