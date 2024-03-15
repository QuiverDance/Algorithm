/*
    #3085 is solved
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, ret;
char a[54][54];
string str;
void getCandy(int dir){
    int cnt;
    for(int i = 0; i < n; i++){
        cnt = 1;
        for(int j = 0; j < n - 1; j++){
            if(a[i][j] == a[i][j + 1]) cnt++;
            else { ret = max(ret, cnt); cnt = 1; }
        }
        ret = max(ret, cnt);
    }
    for(int j = 0; j < n; j++){
        cnt = 1;
        for(int i = 0; i < n - 1; i++){
            if(a[i][j] == a[i + 1][j]) cnt++;
            else { ret = max(ret, cnt); cnt = 1; }
        }
        ret = max(ret, cnt);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < n; j++)
            a[i][j] = str[j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j + 1 < n && a[i][j] != a[i][j + 1]){
                swap(a[i][j], a[i][j + 1]);
                getCandy(1);
                swap(a[i][j], a[i][j + 1]);
            }
            if(i + 1 < n && a[i][j] != a[i + 1][j]){
                swap(a[i][j], a[i + 1][j]);
                getCandy(0);
                swap(a[i][j], a[i + 1][j]);
            }
        }
    }
    cout << ret;
    return 0;
}
