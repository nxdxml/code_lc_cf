#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<PII> s;
    for(int i = 0; i < n; i ++ ){
        int x, y;
        cin >> x >> y;
        if(y >= 5){
            s.insert({x, y - 1});
            s.insert({x, y - 3});
            s.insert({x, y - 5});
        } else if(y >= 3){
            s.insert({x, y - 1});
            s.insert({x, y - 3});
            s.insert({x - 1, y - 5 + 60});
        } else if(y >= 1){
            s.insert({x, y - 1});
            s.insert({x - 1, y - 3 + 60});
            s.insert({x - 1, y - 5 + 60});
        } else {
            s.insert({x - 1, y - 1 + 60});
            s.insert({x - 1, y - 3 + 60});
            s.insert({x - 1, y - 5 + 60});
        }
    }
    int m = s.size();
    vector<PII> f(m);
    int cnt = 0;
    for(auto x : s){
        f[cnt ++ ] = x;
    }
    sort(f.begin(), f.end(), [](auto&& t1, auto&& t2){
        if(t1.first != t2.first) return t1.first < t2.first;
        return t1.second < t2.second;
    });
    cout << m << endl;
    for(auto e : f){
        cout << e.first << " " << e.second << endl;
    }
    
    return 0;
}