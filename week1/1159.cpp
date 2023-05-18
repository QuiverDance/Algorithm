#include<iostream>
#include<string>

using namespace std;

int n, f = 0;
int name[26];
int main(void){
    cin >> n;

    string temp;    
    for(int i = 0; i < n; i++){
        cin >> temp;
        name[temp[0]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(name[i] >= 5){ printf("%c", 'a'+i); f = 1; } 
    }
    if(f == 0)
        cout << "PREDAJA";
    
    return 0;
}
