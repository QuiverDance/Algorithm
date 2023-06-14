#include<iostream>
#include<string>
#include<vector>

using namespace std;

int t, k, ret;
string gears[1004];
int tops[1004], temp[1004];
void rotate(int gear, int clockwise){    
    if(clockwise == 1){
        temp[gear] -= 1;
        if(temp[gear] < 0) temp[gear] = 7;
    }
    else
        temp[gear] = (temp[gear] + 1) % 8;
}
void solve(int gear, int clockwise){    
    rotate(gear, clockwise);
    int prev = clockwise;
    for(int i = gear; i < t; i++){
        int p = tops[i + 1] - 2;
        if(p < 0) p += 8;
        if(gears[i][(tops[i] + 2) % 8] != gears[i + 1][p]){
            prev == 1 ? prev = -1 : prev = 1;
            rotate(i + 1, prev);
        }
        else break;
    }
    prev = clockwise;
    for(int i = gear; i > 1; i--){
        int p1 = tops[i] - 2;
        if(p1 < 0) p1 += 8;
        if(gears[i][p1] != gears[i - 1][(tops[i - 1] + 2) % 8]){
            prev == 1 ? prev = -1 : prev = 1;
            rotate(i - 1, prev);
        }
        else break;
    }
    for(int i = 1; i <= t; i++) tops[i] = temp[i];
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; i++)
        cin >> gears[i];
    cin >> k;
    int a, b;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        solve(a, b);
    }

    for(int i = 1; i <= t; i++){
        if(gears[i][tops[i]] == '1') ret++;
    }
    cout << ret;
    return 0;
}