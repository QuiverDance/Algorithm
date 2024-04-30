/*
    #14891 톱니바퀴
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int k, ret;
vector<int> gear[4];
int main(){
    int num;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            scanf("%1d", &num);
            gear[i].push_back(num);
        }
    }
    scanf("%d", &k);
    int tg, dir;
    while(k--){
        scanf("%d %d", &tg, &dir);
        int d = dir; tg--;
        vector<pair<int, int>> order;
        order.push_back({tg, dir});
        for(int i = tg + 1; i < 4; i++){
            d == 1 ? d = -1 : d = 1;
            if(gear[i][6] == gear[i - 1][2]) break;
            order.push_back({i, d});
        }
        d = dir;
        for(int i = tg - 1; i >= 0; i--){
            d == 1 ? d = -1 : d = 1;
            if(gear[i][2] == gear[i + 1][6]) break;
            order.push_back({i, d});
        }
        for(auto it : order){
            int i = it.first;
            if(it.second == -1)
                rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
            else
                rotate(gear[i].rbegin(), gear[i].rbegin() + 1, gear[i].rend());
        }
    }
    for(int i = 0; i < 4; i++){
        if(gear[i][0] == 1) ret += (int)pow(2, i);
    }
    printf("%d", ret);
    return 0;
}