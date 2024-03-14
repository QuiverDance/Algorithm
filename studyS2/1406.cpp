/*
    #1406 에디터
*/
#include<iostream>
#include<string>
#include<deque>
using namespace std;

int m;
string str, order;
deque<char> dq1, dq2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str >> m;
    for(char c : str) dq1.push_back(c);
    getline(cin, order);
    for(int i = 0; i < m; i++){
        getline(cin, order);
        if(order[0] == 'L'){
            if(!dq1.empty()){ dq2.push_front(dq1.back()); dq1.pop_back(); }  
        }
        else if(order[0] == 'D'){
            if(!dq2.empty()){ dq1.push_back(dq2.front()); dq2.pop_front();}
        }
        else if(order[0] == 'B'){
            if(!dq1.empty()) dq1.pop_back();
        }
        else{
            string temp = order.substr(2);
            for(char c : temp) dq1.push_back(c);
        }
    }
    while(!dq1.empty()){
        cout << dq1.front();
        dq1.pop_front();
    }
    while(!dq2.empty()){
        cout << dq2.front();
        dq2.pop_front();
    }
    return 0;
}