#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, d, p, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &d, &p);
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());
    for(auto it : v){
        pq.push(it.second);
        if(pq.size() > it.first){
            pq.pop();
        }
    }
    while(pq.size()){
        ret += pq.top();
        pq.pop();
    }
    cout << ret;
    return 0;
}