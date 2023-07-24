#include<iostream>
#include<string>
using namespace std;

int n, m, ret = 1e7;
string s, a[50];
string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
int WB_cnt(int x, int y)
{
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(a[x+i][y+j] != WB[i][j]) cnt++;
        }
    }
    return cnt;
}
int BW_cnt(int x, int y)
{
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(a[x+i][y+j] != BW[i][j]) cnt++;
        }
    }
    return cnt;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i <= n - 8; i++){
        for(int j = 0; j <= m - 8; j++){
            ret = min(ret, WB_cnt(i, j));
            ret = min(ret, BW_cnt(i, j));
        }
    }
    cout << ret;
    return 0;
}