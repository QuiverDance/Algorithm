#include<iostream>
#include<string>
using namespace std;

string str;
int main(void){
    getline(cin, str);

    char s;
    for(auto it : str){
        s = it;
        if(it >= 'a' && it <= 'z'){
            s = ((it - 'a') + 13) % 26 + 'a';
        }
        else if(it >= 'A' && it <= 'Z'){
            s = ((it - 'A') + 13) % 26 + 'A';
        }
        printf("%c", s);
    }
    return 0;
}