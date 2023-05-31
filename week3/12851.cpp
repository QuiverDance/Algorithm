#include<iostream>
#include<queue>

using namespace std;

int n, k;
int visited[100001], cnt[100001];
queue<int> q;

int d[] = {-1, 1};

int main(void){
    cin >> n >> k;
    if(n == k){
        cout << "0\n1";
        return 0;
    }
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    int x;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int nx : {x-1, x+1, x*2}) {
            if (0 <= nx && nx <= 100000) { 
                if (!visited[nx]) {
                    q.push(nx); 
                    visited[nx] = visited[x] + 1;
                    cnt[nx] += cnt[x];
                } else if (visited[nx] == visited[x] + 1) {
                    cnt[nx] += cnt[x];
                }
            }
        }
    }
    cout << visited[k] - 1 << '\n';
    cout << cnt[k];
    return 0;
}