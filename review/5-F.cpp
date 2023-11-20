#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, k, m, v, c;
long long ret;
vector<int> bags;
vector<pair<int, int>> jewels;
priority_queue<int, vector<int>, less<int>> pq;

int main(void){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &m, &v);
        jewels.push_back({m, v});
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &c);
        bags.push_back(c);
    }
    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());
    int j = 0;
    for(int i = 0; i < k; i++){
        while(j < n && bags[i] >= jewels[j].first){
            pq.push(jewels[j++].second);
        }
        if(pq.size()){
            ret += pq.top();
            pq.pop();
        }
    }
    printf("%lld", ret);
    return 0;
}