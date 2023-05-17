#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[9];
int sum = 0;
void print(pair<int, int> e){
    for(int i = 0; i < 9; i++){
        if(i == e.first || i == e.second)
            continue;
        cout << a[i] << '\n';
    }
}

int main(void){
    for(int i = 0; i < 9; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + 9);

    //combiation
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if(sum - a[i] - a[j] == 100){
                print({i, j});
                return 0;
            }
        }
    } 
    return 0;
}