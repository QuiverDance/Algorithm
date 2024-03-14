/*
    #5397 키로거
*/
#include<iostream>
#include<deque>
using namespace std;

int t;
string str;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t; getline(cin, str);
    while(t--){
        deque<char> dq1, dq2;
        getline(cin, str);
        for(char c : str){
            if(c == '<' && !dq1.empty()){
                dq2.push_front(dq1.back()); dq1.pop_back();
            }
            else if(c == '>' && !dq2.empty()){
                dq1.push_back(dq2.front()); dq2.pop_front();
            }
            else if(c == '-' && !dq1.empty()){
                dq1.pop_back();
            }
            else if(c != '<' && c != '>' && c != '-'){
                dq1.push_back(c);
            }
        }
        while(!dq1.empty()){
            cout << dq1.front(); dq1.pop_front();
        }
        while(!dq2.empty()){
            cout << dq2.front(); dq2.pop_front();
        }
        cout << '\n';
    }
    return 0;
}