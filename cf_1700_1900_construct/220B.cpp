/*
扫描线+树状数组
有些没理解
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 1e5 + 5;
int n, m;
int a[N], tr[N], ans[N];
vector<PII> f[N];

// a[i] - {pos}
vector<int> g[N];

int lowbit(int x){
    return x & -x;
}

void add(int x, int v){
    for(int i = x; i <= n; i += lowbit(i)){
        tr[i] += v;
    }
}

int query(int x){
    int ret = 0;
    for(int i = x; i; i -= lowbit(i)){
        ret += tr[i];
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= m; i ++ ){
        int l, r;
        cin >> l >> r;
        f[r].push_back({l, i});
    }
    for(int i = 1; i <= n; i ++ ){
        int x = a[i];
        if(x <= n) {
            g[x].push_back(i);
            int len = g[x].size();
            if(len >= x){
                add(g[x][len - x], 1);
                if(len - x - 1 >= 0) add(g[x][len - x - 1], -2);
                if(len - x - 2 >= 0) add(g[x][len - x - 2], 1);
            }
        }
        for(int j = 0; j < f[i].size(); j ++ ){
            PII t = f[i][j];
            ans[t.second] = query(i) - query(t.first - 1);
        }
    }

    for(int i = 1; i <= m; i ++ ) cout << ans[i] << endl;

    return 0;
}


