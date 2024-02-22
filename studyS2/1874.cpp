/*
    #1874 수택 수열
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n;
queue<int> q;
stack<int> stk;
vector<char> vret;
int main() {
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        q.push(num);
    }
    int flag = 0, cur = 1;
    while(q.size()){
        if(stk.empty()){
            stk.push(cur++);
            vret.push_back('+');
        }
        while(!stk.empty() && stk.top() <= q.front()){
            if(stk.top() == q.front()){
                stk.pop();
                vret.push_back('-');
                q.pop();
                break;
            }
            else{
                stk.push(cur++);
                vret.push_back('+');
            }
        }
        if(!stk.empty() && !q.empty() && stk.top() > q.front()){
            flag = 1;
            break;
        }
    }    
    if(flag) cout << "NO";
    else{
        for(char c : vret) cout << c << '\n';
    }
    return 0;
}