/*
    #7662번 이중 우선순위 큐
*/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int t, k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> k;
        priority_queue<int, vector<int>> max_q;
        priority_queue<int, vector<int>, greater<int>> min_q;
        map<int, int> mp;

        char order; int num;
        for(int i = 0; i < k; i++){
            cin >> order >> num;
            if(order == 'I'){
                max_q.push(num);
                min_q.push(num);
                mp[num]++;
            }
            else if(order == 'D' && num == 1){
                if(max_q.empty()) continue;
                mp[max_q.top()]--;
                max_q.pop();
            }
            else{
                if(min_q.empty()) continue;
                mp[min_q.top()]--;
                min_q.pop();
            }
            while(!max_q.empty() && mp[max_q.top()] == 0){
                max_q.pop();
            }
            while(!min_q.empty() && mp[min_q.top()] == 0){
                min_q.pop();
            }
        }

        if(max_q.empty()) cout << "EMPTY\n";
        else cout << max_q.top() << " " << min_q.top() << '\n';
    }
    return 0;
}