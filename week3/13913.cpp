#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int n, k;
int visited[100001], from[100001];
queue<int> q;
stack<int> stk;
int main(void){
    cin >> n >> k;
    if(n == k){
        cout << "0\n" << n;
        return 0;
    }
    q.push(n);
    visited[n] = 1;
    int x;
    while(q.size()){
        x = q.front();
        if(x == k)
            break;
        q.pop();
        for(int nx : {x - 1, x + 1, x * 2}){
            if(nx < 0 || nx > 100000) continue;
            if(visited[nx]) continue;
            visited[nx] = visited[x] + 1;
            from[nx] = x;
            q.push(nx);
        }
    }
    int cur = k;
    stk.push(cur);
    while(from[cur] != n){
        stk.push(from[cur]);
        cur = from[cur];
    }
    stk.push(n);
    cout << visited[k] - 1 << '\n';
    while(stk.size()){
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}