#include<iostream>
#include<vector>

using namespace std;

int n, m, j, ret, movement, a, cur;
vector<int> pos_vector;
int main(void){
    cin >> n >> m;
    cin >> j;
    for(int i = 0; i < j; i++){
        cin >> a;
        pos_vector.push_back(a);
    }
    movement = 0; cur = 1;
    for(int i = 0; i < j; i++){
        if(pos_vector[i] >= cur){ 
            movement = (int)abs(pos_vector[i] - cur) - m + 1;
            if(movement < 0) movement = 0;
            cur += movement;
        }
        else {
            movement = (int)abs(pos_vector[i] - cur);
            cur -= movement;
        }
        ret += movement;
    }
    cout << ret;
    return 0;
}