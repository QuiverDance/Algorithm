/*
    #1715 카드 정리하기
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, ret;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        pq.push(num);
    }
    if(n == 1){
        cout << 0; return 0;
    }
    int num1, num2;
    while(pq.size() != 1){
        num1 = pq.top(); pq.pop();
        num2 = pq.top(); pq.pop();
        ret += num1 + num2;
        pq.push(num1 + num2);
    }
    cout << ret;
    return 0;
}