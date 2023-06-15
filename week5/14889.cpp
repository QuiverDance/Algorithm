#include<iostream>
#include<vector>

using namespace std;

int n, ret = 1e8;
int board[24][24];
vector<int> t1, t2;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }
    for(int k = 1; k < (1 << n); k++){
        int cnt = 0;
        t1.clear(); t2.clear();
        for(int i = 0; i < n; i++){
            if(k & (1 << i)){
                cnt++; t1.push_back(i + 1);
            }
            else t2.push_back(i + 1);
        }
        if(cnt != n / 2) continue;
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n / 2; i++){
            int x1 = t1[i], y1 = t2[i];
            for(int j = i + 1; j < n / 2; j++){
                int x2 = t1[j], y2 = t2[j];
                sum1 += board[x1][x2]; sum1 += board[x2][x1];
                sum2 += board[y1][y2]; sum2 += board[y2][y1];
            }
        }
        ret = min(ret, abs(sum1 - sum2));
    }
    cout << ret;
    return 0;
}