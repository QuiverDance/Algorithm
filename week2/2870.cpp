#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, start;
string s;
vector<string> v;

bool cmp(string a, string b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        start = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                if(start == -1) start = i;
            }
            else if(start != -1){
                v.push_back(s.substr(start, i - start));
                start = -1;
            }
            if(start != -1 && i == s.size()-1)
                v.push_back(s.substr(start, i - start + 1));
        }
    }
    for(int i = 0; i < v.size(); i++){
        string str = v[i];
        if(str[0] == '0' && str.size() > 1){
            int flag = 0;
            for(int j = 0; j < str.size(); j++){
                if(str[j] != '0'){
                    flag = 1;
                    v[i] = str.substr(j);
                    break;
                } 
            }
            if(!flag){
                v[i] = "0";
            }

        }
    }
    sort(v.begin(), v.end(), cmp);
    for(auto it : v){
        cout << it << '\n';
    }
    return 0;
}