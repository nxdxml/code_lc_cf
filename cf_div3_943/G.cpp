/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;
vector<int> z_func(string& s){
    int n = (int)s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i ++ ){
        if(i <= r) z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            l = i;
            r = i + z[i];
            z[i] ++ ;
        }
    }
    return z;
}

void solve(){
    int n, k;
    cin >> n >> k >> k;
    string s;
    cin >> s;

    vector<int> z = z_func(s);
    // for(auto x : z) cout << x << " ";
    // cout << endl;
    auto check = [&](int x){
        int cnt = 1;
        for(int i = x; i < n; i ++ ){
            if(z[i] >= x){
                cnt ++ ;
                i += x - 1;
            }
        }
        return cnt >= k;
    };
    
    int l = 0, r = n;
    // 1111 1 0000
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}