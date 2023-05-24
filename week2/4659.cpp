#include<iostream>
#include<string>

using namespace std;

string s;
int cnt, lcnt, vcnt, flag;
char pre;
bool check(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}
int main(void){
    while(true){
        cnt = 0; lcnt = 0; vcnt = 0; flag = 0; pre = '0';
        cin >> s;
        if(s == "end") break;
        for(char c : s){
			if(check(c))lcnt++, vcnt = 0, cnt = 1;
			else vcnt++, lcnt = 0;
			if(vcnt == 3 || lcnt == 3) flag = 1;
            if(pre == c && c != 'e' && c != 'o') flag = 1;
            pre = c;
        }
        if(cnt == 0) flag = 1;

        if(flag)
            cout << "<" << s << ">" << " is not acceptable.\n";
        else
            cout << "<" << s << ">" << " is acceptable.\n";
    }
    
    return 0;
}