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
    map<int, int > ans;
    map<int, basic_string<int> > mp;
    for(int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        ans[a[i]] = a[i];
        if(!mp.count(a[i])){
            mp[a[i]] = {a[i]};
        }
    }
    while(m -- ){
        int x, y;
        cin >> x >> y;
        if(x == y) continue;
        mp[y] += mp[x];
        mp.erase(x);
    }
    for(auto [y, x] : mp){
        for(auto i : x) ans[i] = y;
    }
    for(int i = 1; i <= n; i ++ ) cout << ans[a[i]] << " ";
    cout << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}