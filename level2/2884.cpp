#include<iostream>
using namespace std;

int h, m;
int main(void){
    cin >> h >> m;
    m -= 45;
    if(m < 0){
        if(h == 0) h = 23;
        else h--;
        m += 60;
    }
    cout << h << " " << m;
    return 0;
}