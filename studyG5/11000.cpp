/*
    #11000 강의실 배정
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int st, ed;
    for(int i = 0; i < n; i++){
        cin >> st >> ed;
        v.push_back({st, ed});
    }
    sort(v.begin(), v.end());

    pq.push(v[0].second); ret++;
    for(int i = 1; i < n; i++){
        if(v[i].first < pq.top()){
            ret++; pq.push(v[i].second);
        }
        else{
            pq.pop(); pq.push(v[i].second);
        }
    }
    cout << ret;
    return 0;
}