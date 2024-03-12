/*
    把颜色看成一个点
    颜色->城市并对城市去重
    然后from -> col1 -> ct1 -> col2 -> ct2 -> col3 -> ... -> to
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    map<int, unordered_set<int>> col_city;
    for(int i = 0; i < m; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        a -- ;
        b -- ;
        col_city[c].insert(a);
        col_city[c].insert(b);
    }
    int col_idx = n;
    int c_len = col_city.size();
    vector<vector<int>> g(n + c_len);

    for(auto it : col_city){
        // int c = it.first;
        for(auto x : it.second){
            g[col_idx].push_back(x);
            g[x].push_back(col_idx);
            // cout << x << " " << col_idx << endl;
        }
        col_idx ++ ;
    }
    // u fa dep
    // queue<tuple<int,int,int>> q;
    queue<int> q;
    vector<int> d(n + c_len, -1);
    int ff, tt;
    cin >> ff >> tt;
    ff --;
    tt --;
    d[ff] = 0;
    q.push(ff);
    while(!q.empty()){
        auto t = q.front(); q.pop();
        if(t == tt) break;
        for(int v : g[t]){
            if(d[v] != -1) continue;
            d[v] = d[t] + 1;
            q.push(v);
        }
    }
    cout << d[tt] / 2 << endl;
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