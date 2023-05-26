#include<iostream>

using namespace std;

int n, temp, cnt, cnt_6;
int main(void){
    cin >> n;
    cnt = 0;
    for(int i = 666; i < 10000000; i++){
        temp = i; cnt_6 = 0;
        while(temp > 0){
            if(temp % 10 == 6) cnt_6++;
            else cnt_6 = 0;
            if(cnt_6 >= 3){ cnt++; break;}
            temp /= 10;
        }
        if(cnt == n){
            cout << i;
            break;;
        }
    }
    return 0;
}