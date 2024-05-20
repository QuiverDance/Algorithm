/*
    #14719 빗물
*/
#include<iostream>
using namespace std;

int h, w, ret, cnt, flag, a[504];
int main(){
    cin >> h >> w;
    for(int i = 0; i < w; i++) cin >> a[i];

    for(int y = 1; y <= h; y++){
        cnt = 0; flag = 0;
        for(int x = 0; x < w; x++){
            if(y <= a[x]){
                ret += cnt, cnt = 0; flag = 1;
            }
            else if(flag) cnt++;
        }
    }
    cout << ret;
    return 0;
}