#include<iostream>
using namespace std;

int h, m, c;
int main(void){
    cin >> h >> m >> c;
    m += c;
    if(m >= 60){
        h += m / 60;
        m -= 60 * (m / 60);
        if(h > 23) h -= 24;
    }
    cout << h << " " << m;
    return 0;
}