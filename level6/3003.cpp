#include<iostream>
using namespace std;

int a[] = {1, 1, 2, 2, 2, 8}, t;
int main(void){
    for(int i = 0; i < 6; i++){
        cin >> t;
        cout << a[i] - t << " ";
    }
    return 0;
}