#include<iostream>
#include<string>
using namespace std;

int t;
string s;
int main(void){
    cin >> t;
    while(t--){
        cin >> s;
        cout << s[0] << s[s.length() - 1] << '\n';
    }
    return 0;
}