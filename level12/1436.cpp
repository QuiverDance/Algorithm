#include<iostream>
#include<string>
using namespace std;

int n, cnt = 0;
string s;
int main(void){
    cin >> n;
    for(int i = 666; i <= 1e9; i++){
        s = to_string(i);
        if(s.find("666") != string::npos){
            cnt++;
            if(cnt == n) break;
        }
    }
    cout << s;
    return 0;
}