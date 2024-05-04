/*
l->x, x+1->r
k = 2

l->s, s+1->t, t+1->r

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int a[N];

void solve(){
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mp;
    mp[0].push_back(0);
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        a[i] ^= a[i - 1];
        mp[a[i]].push_back(i);
    }
    // k == 2
    while(m -- ){
        int l, r;
        cin >> l >> r;
        // k == 2
        if(a[l - 1] == a[r]) {
            cout << "YES\n";
            continue;
        }
        // k == 3
        // >= r
        // 最右t的位置（<r最大）
        int pt = *--lower_bound(mp[a[l-1]].begin(), mp[a[l-1]].end(), r);
        // 最左s的位置(>=l最小)
        int ps = *lower_bound(mp[a[r]].begin(), mp[a[r]].end(), l);
        if(ps < pt) cout << "YES\n";
        else cout << "NO\n";

    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) {
        solve();
        if(T) cout << endl;
    }
    

    return 0;
}