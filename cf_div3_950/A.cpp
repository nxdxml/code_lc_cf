/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    string s;
    int n, m;
    cin >> n >> m;
    cin >> s;
    vector<int> cnt(7);
    for(int i = 0; i < n; i ++ ){
        int x = s[i] - 'A';
        cnt[x] ++;
    }
    int ans = 0;
    for(int i = 0; i < 7; i ++ ){
        if(cnt[i] >= m) continue;
        ans += m - cnt[i];
    }
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