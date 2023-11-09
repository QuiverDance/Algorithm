#include<iostream>
#include<string>
#include<deque>

using namespace std;

int t, n;
string p;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> p;
        cin >> n;
        deque<int> deq;
        string s;
        cin >> s;
        int pre = 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '[') continue;
            if(pre != i && (s[i] == ',' || s[i] == ']')){
                deq.push_back(atoi(s.substr(pre, i - pre).c_str()));
                pre = i + 1;
            }
        }
        bool f = 0, flag = 0;
        for(int i = 0; i < p.size(); i++){
            if(p[i] == 'R'){ f == 0 ? f = 1 : f = 0; continue; }
            if(!deq.size()){ flag = 1; break;}
            if(f) deq.pop_back();
            else deq.pop_front();
        }
        if(flag) {cout << "error\n"; continue;}
        cout << "[";
        while(deq.size()){
            if(f){
                cout << deq.back();
                deq.pop_back();
            }
            else {
                cout << deq.front();
                deq.pop_front();
            }
            if(deq.size() != 0)
                cout << ",";
        }
        cout << "]\n";
    }
    return 0;
}