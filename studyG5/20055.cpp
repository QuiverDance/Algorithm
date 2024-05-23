/*
    #20055 컨베이어 벨트 위의 로봇
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, r_idx, ret, cnt;
vector<int> belt, robot;
int main(){
    cin >> n >> k;
    int num;
    for(int i = 0; i < 2 * n; i++){
        cin >> num;
        belt.push_back(num);
    }
    while(true){
        ret++;
        rotate(belt.rbegin(), belt.rbegin() + 1, belt.rend());
        for(int i = r_idx; i < robot.size(); i++){
            robot[i]++;
            if(robot[i] == n - 1) r_idx++;
        }
        for(int i = r_idx; i < robot.size(); i++){
            if(belt[robot[i] + 1] < 1) continue;
            if(i != r_idx && robot[i] + 1 == robot[i - 1]) continue;
            
            robot[i]++; belt[robot[i]]--;
            if(belt[robot[i]] == 0) cnt++;
            if(robot[i] == n - 1) r_idx++;
        }
        
        if(belt[0] > 0){
            belt[0]--; robot.push_back(0);
            if(belt[0] == 0) cnt++; 
        }
        if(cnt >= k) break;
    }
    cout << ret;
    return 0;
}