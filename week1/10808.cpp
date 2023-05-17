#include<iostream>
#include<string>

using namespace std;

int count[26];
string str;
int main(void){
    cin >> str;
    
    for(auto it : str){
        count[it-'a']++;
    }
    for(auto it : count){
        cout << it << " ";
    }
    return 0;
}