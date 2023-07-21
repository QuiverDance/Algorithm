#include<iostream>
using namespace std;

int x, y, w, h, ret;
int main(void){
    cin >> x >> y >> w >> h;
    ret = min(abs(x - w), abs(y - h));
    ret = min(ret, min(x, y));
    cout << ret;
}