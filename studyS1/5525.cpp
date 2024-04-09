/*
    #5525 IOIOI
*/
#include<iostream>
#include<string>
using namespace std;

int n, m, ret;
string p, str;
int main(){
    cin >> n >> m >> str;

    int cnt = 0;
    for(int i = 0; i < m; i++){
        cnt = 0;
        // cout << "i : " << i << '\n';
        if(str[i] == 'O') continue;
        for(int j = i + 2; j < m; j += 2){
            if(str[j - 1] == 'O' && str[j] == 'I'){ cnt++; i = j - 1;}
            else break;
            if(cnt == n){
                ret++; cnt--;
            }
        }
    }
    cout << ret;
    return 0;
}