#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, p, d, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &p, &d);
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first){
            pq.pop();
        }
    }
    while(pq.size()){
        ret += pq.top();
        pq.pop();
    }
    printf("%d", ret);
    return 0;
}