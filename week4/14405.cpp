#include<iostream>
#include<string>

using namespace std;

string s;
string word[3] = {"pi", "ka", "chu"};
int main(void){
    cin >> s;
    int i = 0, flag = 0;
    while(i != s.size()){
        int cnt = 0, j;
        for(j = 0; j < 3; j++){
            if(word[j] == s.substr(i, word[j].size())){cnt ++; break;}
        }
        if(cnt == 0){flag = 1; break;}
        i += word[j].size();
    }
    if(flag) cout << "NO";
    else cout << "YES";
    return 0;
}