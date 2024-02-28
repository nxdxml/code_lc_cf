#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;

void solve(){
    int a, b, l;
    cin >> a >> b >> l;
    vector<int> fa;
    vector<int> fb;
    unordered_set<int> s;
    int t = 1;
    while(t <= l){
        fa.push_back(t);
        t *= a;
    }
    t = 1;
    while(t <= l){
        fb.push_back(t);
        t *= b;
    }
    for(int i = 0; i < fa.size(); i ++ ){
        for(int j = 0; j < fb.size(); j ++ ){
            LL x = (LL)fa[i] * fb[j];
            // cout << x << endl;
            if(l % x == 0){
                s.insert(l / x);
            }
        }
    }
    cout << s.size() << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        solve();
    }

    return 0;
}