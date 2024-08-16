/*
    #4386 별자리 만들기
*/
#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<cmath>
using namespace std;

int n, parent[104];
double ret;
pair<double, double> a[104];
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
int getRoot(int node){
    if(parent[node] == 0) return node;
    return parent[node] = getRoot(parent[node]);
}
int main(){
    scanf("%d", &n);
    double y, x;
    for(int i = 1; i <= n; i++){
        scanf("%lf %lf", &y, &x);
        a[i] = {y, x};
        for(int j = i - 1; j >= 1; j--){
            double ty = a[j].first, tx = a[j].second;
            pq.push({sqrt(pow(y - ty, 2) + pow(x - tx, 2)), {j, i}});
        }
    }

    int from, to;
    double cost;
    while(!pq.empty()){
        cost = pq.top().first;
        tie(from, to) = pq.top().second;
        pq.pop();
        int r1 = getRoot(from);
        int r2 = getRoot(to);
        if(r1 == r2) continue;
        parent[r2] = r1;
        ret += cost;
    }
    printf("%.2lf", ret);
    return 0;
}