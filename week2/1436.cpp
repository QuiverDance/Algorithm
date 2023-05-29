#include<iostream>
#include<string>

using namespace std;

int n, cnt;
int main(void){
    cin >> n;
    cnt = 0;
    string s;
    for(int i = 666; i < 10000000; i++){
        s = to_string(i);
        if(s.find("666") != string::npos){
            cnt++;
            if(cnt == n){
                cout << s;
                break;
            }
        }
    }
    return 0;
}