/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

bool solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    vector<int> pi(n * m), pj(n * m);
    map<int, set<int>> mi, mj;

    for(int i = 0; i < n; i ++ ) {
        for(int j = 0; j < m; j ++ ){
            cin >> a[i][j];
            pi[a[i][j] - 1] = i;
            pj[a[i][j] - 1] = j;
        }
    }
    for(int i = 0; i < n; i ++ ) {
        for(int j = 0; j < m; j ++ ){
            cin >> b[i][j];
            int ai = pi[b[i][j] - 1];
            int aj = pj[b[i][j] - 1];
            mi[ai].insert(i);
            mj[aj].insert(j);
        }
    }
    for(auto x : mi){
        if(x.second.size() > 1) return false;
    }
    for(auto x : mj){
        if(x.second.size() > 1) return false;
    }
    return true;

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
    


    return 0;
}