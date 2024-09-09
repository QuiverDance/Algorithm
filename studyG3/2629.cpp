/*
    #2629 양팔저울
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int n, m;
map<int, int> mp;
int main() {
    cin >> n;
    int num;
    cin >> num;
    mp[num] = 1;
    mp[-num] = 1;
    for(int i = 1; i < n; i++){
        cin >> num;
        vector<int> keys;
        for(pair<int, int> keyset : mp){
            keys.push_back(keyset.first);
        }
        for(int key : keys){
            mp[key + num] = 1;
            mp[key - num] = 1;
        }
        mp[num] = 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> num;
        if(mp[num] == 1) cout << 'Y' << " ";
        else cout << 'N' << " ";
    }
    return 0;
}