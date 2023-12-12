#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int n, k, l;
char a[104][104];
vector<pair<int, int>> v;
queue<pair<int, int>> bodies, orders;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int main(){
    cin >> n >> k;
    int y, x;
    for(int i = 0; i < k; i++){
        cin >> y >> x;
        a[y - 1][x - 1] = 'A';
    }
    cin >> l;
    for(int i = 0; i < l; i++){
        cin >> y >> x;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());
    for(auto it : v) orders.push(it); 

    int time = 0, d = 0;
    while(1){
        time++;
        if(orders.size() && orders.front().first == time){
            if(orders.front().second == 'D') d = (d + 1) % 4;
            else d = (d + 4 - 1) % 4;
        }
    }

    return 0;
}