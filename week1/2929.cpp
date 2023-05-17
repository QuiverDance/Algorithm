#include<iostream>

using namespace std;

int a, b, c;
int car[101];
int main(void){
    cin >> a >> b >> c;

    int start, end;
    for(int i = 0; i < 3; i++){
        cin >> start >> end;
        for(int j = start; j < end; j++) car[j]++;
    }
    
    int sum = 0;
    for(int i = 1; i < 101; i++){
        if(car[i] == 1){ sum += a; continue; }
        if(car[i] == 2){ sum += (2 * b); continue;}
        if(car[i] == 3){ sum += (3 * c); continue;}
    }
    cout << sum;
    return 0;
}