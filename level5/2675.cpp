#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int t, n;
string s;
int main(void){
    cin >> t;
    while(t--){
        string ret;
        cin >> n >> s;
        for(int j = 0; j < s.length(); j++){
            for(int k = 0; k < n; k++)
                ret += s[j];
        } 
        cout << ret << '\n';
    }
    return 0;
}