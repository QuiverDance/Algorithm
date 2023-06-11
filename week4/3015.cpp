#include<iostream>
#include<stack>

using namespace std;

int n, temp;
long long ret;
stack<pair<long long, long long>> stk;
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        int cnt = 1;
        while(stk.size() && stk.top().first <= temp){
            ret += stk.top().second;
            if(stk.top().first == temp){
                cnt = stk.top().second + 1;
            }
            else{
                cnt = 1;
            }
            stk.pop();
        }
        if(stk.size()) ret++;
        stk.push({temp, cnt});
    }
    cout << ret;
    return 0;
}