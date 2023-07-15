#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int a[26];
string s;
int main(void){
    memset(a, -1, sizeof(a));
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(a[s[i] - 'a'] == -1)
            a[s[i] - 'a'] = i;
    }
    for(int i = 0; i < 26; i++) cout << a[i] << " ";
    return 0;
}