#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int board[15][5], ret = 1e8;
int goal[5], n;
vector<int> v;
map<int, vector<vector<int>>> retV;

int main(void){
    cin >> n;
    cin >> goal[0] >> goal[1] >> goal[2] >> goal[3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++) cin >> board[i][j];
    }

    for(int i = 0; i < (1 << n); i++){
        v.clear();
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) {
                v.push_back(j);
            }
        }
        int flag = 1, sum = 0;
        for(int j = 0; j < 5; j++){
            sum = 0;
            for(int idx : v){
                sum += board[idx][j];  
            }
            if(sum < goal[j]){
                flag = 0;
                break;
            }
        }
        if(flag && ret >= sum){
            ret = sum;
            retV[ret].push_back(v);
        }
    }

    if(ret == 1e8)
        cout << "-1";
    else{
        sort(retV[ret].begin(), retV[ret].end());
        cout << ret << '\n';
        for(int it : retV[ret][0])
            cout << it + 1 << " ";
    }
    return 0;
}