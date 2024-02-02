/*
    #1021 회전하는 큐
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m, ret;
vector<int> v;
int main() {
    cin >> n >> m;
    int num;
    for(int i = 0; i < m; i++){
        cin >> num;
        v.push_back(num - 1);
    }
    int target, move;
    while(v.size()){
        move = 0;
        if(v[0] > n - v[0]) move = n - v[0];
        else move = v[0] * (-1);
        for(int i = 0; i < v.size(); i++){
            v[i] = (v[i] + move) % n;
            if(v[i] < 0) v[i] += n;
        }
        v.erase(v.begin(), v.begin() + 1); n--;
        ret += abs(move);

        for(int i = 0; i < v.size(); i++){
            v[i]--;
            if(v[i] < 0) v[i] += n;
        }
    }
    cout << ret;
    return 0;
}