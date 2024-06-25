/*
    #5639 이진 검색 트리
*/
#include<iostream>
using namespace std;

struct Tree{
    int left = -1;
    int right = -1;
    int value = -1;
};

Tree tree[10004];
void addNode(int idx, int value){
    int cur = 0;
    tree[idx].value = value;
    while(true){
        if(tree[cur].value > value){
            if(tree[cur].left == -1){
                tree[cur].left = idx; break;
            }
            cur = tree[cur].left;
        }
        else{
            if(tree[cur].right == -1){
                tree[cur].right = idx; break;
            }
            cur = tree[cur].right;            
        }
    }
}
void postorder(int node){
    if(tree[node].left != -1)
        postorder(tree[node].left);
    if(tree[node].right != -1)
        postorder(tree[node].right);
    cout << tree[node].value << '\n';
}
int main(){
    int num, i = 1;
    cin >> num; tree[0].value = num;
    while(cin >> num){
        addNode(i, num);
        i++;
    }
    postorder(0);
    return 0;
}