/*
    字典树
    维护每个位置的栈序列
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

struct Node{
    Node* son[26]{};
    Node* fa;
    int t;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    Node* o = new Node();
    o -> t ++ ;
    LL ans = 0;
    for(int i = 0; i < n; i ++ ){
        int x = s[i] - 'a';
        if(o -> fa == nullptr || o -> fa -> son[x] != o){
            if(o -> son[x] == nullptr){
                o -> son[x] = new Node();
                o -> son[x] -> fa = o;
            }
            
            o = o -> son[x];
        } else {
            o = o -> fa;
        }
        // cout << i << " " << o -> t << endl;
        ans += o -> t;
        o -> t ++ ;
    }
    cout << ans << endl;

    return 0;
}