/*
    #12852 1로 만들기 2
*/
#include<iostream>
#include<queue>
using namespace std;

int n, visited[1000004], trace[1000004];
queue<int> q;
int main(){
    cin >> n;
    q.push(1); visited[1] = 1; trace[1] = -1;
    int num;
    while(!q.empty()){
        num = q.front(); q.pop();
        if(num == n) break;
        for(int next : {num + 1, num * 2, num * 3}){
            if(next > 1000000 || visited[next]) continue;
            q.push(next); visited[next] = visited[num] + 1; trace[next] = num;
        }
    }
    cout << visited[n] - 1 << '\n';
    for(int i = n; i != -1; i = trace[i]){
        cout << i << " ";
    }
    return 0;
}