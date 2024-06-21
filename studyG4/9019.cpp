/*
    #9019 DSLR
*/
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int t, from, to, visited[10004], trace[10004];
string s1, s2, ret;
char order[] = {'D', 'S', 'L', 'R'};
int main(){
    cin >> t;
    while(t--){
        cin >> s1 >> s2;
        from = stoi(s1); to = stoi(s2);

        queue<int> q;
        memset(visited, -1, sizeof(visited));
        memset(trace, -1, sizeof(visited));
        q.push(from); visited[from] = 10001;
        int cur;
        while(!q.empty()){
            cur = q.front(); q.pop();
            if(cur == to) break;

            int i = 0;
            for(int num : {(cur * 2) % 10000, 
                (cur - 1 < 0 ? 9999 : cur - 1), 
                (cur % 1000) * 10 + cur / 1000,  
                (cur % 10) * 1000 + cur / 10}){

                if(visited[num] < 0){
                    q.push(num); visited[num] = cur; trace[num] = order[i];
                }
                i++;
            }
        }
        ret = "";
        while(visited[cur] != 10001){
            ret += trace[cur];
            cur = visited[cur];
        }
        reverse(ret.begin(), ret.end());
        cout << ret << '\n';
    }
    return 0;
}