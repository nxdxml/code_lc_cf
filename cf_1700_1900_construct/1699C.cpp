#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i ++ ) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int l = pos[0], r = pos[0];
    LL ans = 1;
    for(int i = 1; i < n; i ++ ){
        if(pos[i] < l) l = pos[i];
        else if(pos[i] > r) r = pos[i];
        else ans = ans * (r - l + 1 - i) % MOD;
    }
    // 4 0 3 2 1
    // 4 0 3 2 1
    // 4 0 2 3 1
    cout << ans << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();   
    

    return 0;
}