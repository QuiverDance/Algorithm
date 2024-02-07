/*
    #11478 서로 다른 부분 문자열의 개수
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

string str;
set<string> s;
int main() {
    cin >> str;
    for(int l = 1; l <= str.size(); l++){
        int i = 0;
        while(i + l <= str.size()){
            s.insert(str.substr(i, l));
            i++;
        }
    }
    cout << s.size();
    return 0;
}