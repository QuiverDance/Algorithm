#include<iostream>
#include<string>
#include<map>
using namespace std;

string s;
int main(void){
    for(int i = 0; i < 100; i++){
        getline(cin, s);
        cout << s << '\n';
    }
    return 0;
}