/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    LL n;
    vector<LL> ans;
    cin >> n;
    ans.push_back(n);
    for(LL i = 0; i < 64; i ++ ){
        LL x = 1LL << i;
        if((x | n) == n && x != n){
            ans.push_back(n - x);
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(auto x : ans){
        cout << x << " ";
    }
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