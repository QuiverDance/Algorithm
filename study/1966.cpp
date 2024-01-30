/*
    #1966 프린터 큐
*/
#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

int t, n, m, target, num;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        priority_queue<pair<int, int>> pq;
        queue<pair<int, int>> q;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> num;
            q.push({num, i});
            pq.push({num, i});
        }
        int x, y, idx = 0;
        while(pq.size()){
            tie(x, y) = q.front(); q.pop();
            if(x < pq.top().first) q.push({x, y});
            else{
                pq.pop();
                idx++;
                if(y == m){ cout << idx << '\n'; break; }
            }
        }
    }
    return 0;
}