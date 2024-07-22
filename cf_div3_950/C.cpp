/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int a[N], b[N], c[N];

bool solve(){
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < n; i ++ ) cin >> b[i];
    cin >> m;
    map<int, int> mp;
    for(int i = 0; i < m; i ++ ) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i ++ ){
        if(!mp.count(b[i])) mp[b[i]] = 0;
        if(a[i] != b[i]){
            mp[b[i]] ++ ;
        }
    }
    bool fg = 0;
    for(int i = 0; i < m; i ++ ){
        if(!mp.count(c[i])){
            fg = 1;
        } else {
            fg = 0;
            if(mp[c[i]] > 0) mp[c[i]] -- ;
        }
    }
    if(fg) return false;
    for(auto it : mp){
        if(it.second > 0) return false;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) {
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    

    return 0;
}