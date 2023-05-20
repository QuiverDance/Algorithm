#include<iostream>
#include<string>
#include<map>

using namespace std;

int N, M;
string parr[100001];
map<string, int> pmap;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    string s;
    for(int i = 1; i <= N; i++){
        cin >> s;
        parr[i] = s;
        pmap.insert({s, i});
    }
    for(int i = 1; i <= M; i++){
        cin >> s;
        if(s[0] >= 'A'){
            auto it = pmap.find(s);
            cout << (*it).second << '\n';
        }
        else
            cout << parr[atoi(s.c_str())] << '\n';
    }

    return 0;
}