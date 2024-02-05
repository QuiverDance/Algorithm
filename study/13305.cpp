/*
    #13305 주유소
*/
#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;

long long n, sum[100004], ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main(){
    cin >> n;
    int num;
    sum[0] = 0;
    for(int i = 1; i <= n - 1; i++){
        cin >> num;
        sum[i] = num + sum[i - 1];
    }
    for(int i = 0; i < n; i++){
        cin >> num;
        pq.push({num, i});
    }
    int cost, i, idx = n - 1;
    while(pq.size()){
        tie(cost, i) = pq.top(); pq.pop();
        if(idx < i) continue;
        ret += cost * (sum[idx] - sum[i]);
        //printf("idx : %d i : %d cost : %d distance : %d ret : %d\n", idx, i, cost, sum[idx] - sum[i], ret);
        idx = i;
        if(idx == 0) break;
    }
    cout << ret;
    return 0;
}