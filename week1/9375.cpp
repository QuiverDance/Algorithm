#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int T, n;
string a, b;
int main(void){
    cin >> T;
    while(T--){
        map<string, int> closet;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            closet[b]++;
        }
        int ret = 1;
        for(auto it : closet){
            ret *= (it.second + 1);
        }
        ret--;
        cout << ret << '\n';
    }

    return 0;
}