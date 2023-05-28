#include<iostream>
#include<string>

using namespace std;

int n;
int s1 = 0, s2 = 0;
int w_team = 0;

string iToA(int a){
    if(a < 10)
        return "0" + to_string(a);
    return to_string(a);
}
string addTime(string a, string b){
    int m = atoi(a.substr(0, 2).c_str()) + atoi(b.substr(0, 2).c_str());
    int s = atoi(a.substr(3, 2).c_str()) + atoi(b.substr(3, 2).c_str());
    if(s >= 60){
        m += 1;
        s -= 60;
    }
    return iToA(m) + ":" + iToA(s);
}
string subTime(string a, string b){
    int m = atoi(a.substr(0, 2).c_str()) - atoi(b.substr(0, 2).c_str());
    int s = atoi(a.substr(3, 2).c_str()) - atoi(b.substr(3, 2).c_str());
    if(s < 0){
        m -= 1;
        s += 60;
    }
    return iToA(m) + ":" + iToA(s);
}

string c_time = "00:00", w_time1 = "00:00", w_time2 = "00:00";
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    int a; string s;
    for(int i = 0; i < n; i++){
        cin >> a >> s;
        if(a == 1) s1++;
        else s2++;

        if(s1 > s2){
            if(a == 1 && s1 - s2 == 1){
                c_time = s;
            }
            w_team = 1;
        }
        else if(s1 < s2){
            if(a == 2 && s2 - s1 == 1){
                c_time = s;
            }
            w_team = 2;
        }
        else{
            if(w_team == 1){
                w_time1 = addTime(w_time1, subTime(s, c_time));
            }
            else if(w_team == 2){
                w_time2 = addTime(w_time2, subTime(s, c_time));
            }
            w_team = 0;
            c_time = s;
        }
    }
    if(w_team == 1){
        w_time1 = addTime(w_time1, subTime("48:00", c_time));
    }
    else if(w_team == 2){
        w_time2 = addTime(w_time2, subTime("48:00", c_time));
    }

    cout << w_time1 << '\n';
    cout << w_time2;
    return 0;
}