#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first)
            pq.pop();
    }
    while(pq.size()){
        ret += pq.top();
        pq.pop();
    }
    printf("%d", ret);
    return 0;
}