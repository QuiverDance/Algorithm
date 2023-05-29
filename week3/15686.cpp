#include<iostream>
#include<vector>

using namespace std;

int n, m;
int ret = 1000000;
int board[50][50], visitied[50][50];
vector<int> v;
vector<pair<int, int>> homeList, chickenList;

int getDistance(pair<int, int> from, pair<int, int> to){
    return abs(to.first - from.first) + abs(to.second - from.second);
}
void go(int index){
    if(index == chickenList.size())
        return;
    if(v.size() > m)
        return;

    int sum = 0, distance;
    for(auto h : homeList){
        int min = 101;
        for(int c : v){
            distance = getDistance(h, chickenList[c]);
            if(min > distance) min = distance;
            if(distance == 1)
                break;
        }
        sum += min;
    }
    ret = min(ret, sum);

    v.push_back(index + 1);
    go(index + 1);
    v.pop_back();
    go(index + 1);
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1) homeList.push_back({i, j});
            else if(board[i][j] == 2) chickenList.push_back({i, j});
        }
    }
    v.push_back(0);
    go(0);
    v.pop_back();
    go(0);
    cout << ret;
    return 0;
}