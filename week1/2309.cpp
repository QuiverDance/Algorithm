#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a;
int n = 9, k = 7, found = 0;
void print(vector<int> b){
    vector<int> result;
    for(auto it : b){
        result.push_back(a[it]);
    }
    sort(result.begin(), result.end());
    for(auto it : result)
        cout << it << '\n';
}

void combi(int start, vector<int> b){
    if(found == 1)
        return;
    if(b.size() == k){
        int sum = 0;
        for(auto it : b) sum += a[it];
        if(sum == 100){
            found = 1;
            print(b);
        }
        return;
    }
    for(int i = start + 1; i < n; i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main(void){
    int h = 0;
    for(int i = 0; i < 9; i++){
        cin >> h;
        a.push_back(h);
    }

    vector<int> b;
    combi(-1, b);
    return 0;
}