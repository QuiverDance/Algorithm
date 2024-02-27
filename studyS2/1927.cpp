/*
    #1927 최소 힙
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    scanf("%d", &n);
    int num;
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        if(num == 0){
            if(pq.empty()) cout << 0 << '\n';
            else cout << pq.top() << '\n', pq.pop();
        }
        else{
            pq.push(num);
        }
    }
    return 0;
}