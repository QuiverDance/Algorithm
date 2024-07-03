/*
    #1339 단어 수학
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, a[26], ret;
string str[14];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> str[i];
    for(int i = 0; i < n; i++){
        int cal = 1;
        for(int j = str[i].length() - 1; j >= 0; j--){
            a[str[i][j] - 'A'] += cal;
            cal *= 10;
        }
    }
    sort(a, a + 26);
    reverse(a, a + 26);
    for(int i = 0; i < 10; i++){
        ret += a[i] * (9 - i);
    }
    cout << ret;
    return 0;
}