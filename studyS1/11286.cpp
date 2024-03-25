/*
    #11286 절댓값 힙
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(num == 0){
            if(!pq.empty()){
                cout << pq.top().second << '\n';
                pq.pop();
            }
            else cout << 0 << '\n';
        }
        else{
            pq.push({abs(num), num});
        }
    }
    return 0;
}