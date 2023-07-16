#include<iostream>
#include<string>
#include<map>
using namespace std;

double sc;
string s1, s2;
int sum1, sum2;
map<string, int> mp;
int main(void){
    mp["A+"] = 45; mp["A0"] = 40; mp["B+"] = 35;
    mp["B0"] = 30; mp["C+"] = 25; mp["C0"] = 20;
    mp["D+"] = 15; mp["D0"] = 10; mp["F"] = 0;
    for(int i = 0; i < 20; i++){
        cin >> s1 >> sc >> s2;
        if(s2 == "P") continue;
        sum1 += (int)(sc * 10);
        sum2 += (int)(sc * 10) * mp[s2];
    }
    cout << (double)sum2 / sum1 / 10;
    return 0;
}