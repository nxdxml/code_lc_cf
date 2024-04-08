#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt0 = 0;
    for(int i = 0; i < n; i ++ ) cnt0 += s[i] == '0';
    int cnt1 = n - cnt0;
    int ans = -1;
    int c0 = 0, c1 = 0;
    if(cnt1 >= cnt0) ans = 0;
    for(int i = 1; i <= n; i ++ ){
        c0 += s[i - 1] == '0';
        c1 += s[i - 1] == '1';
        if(c0 >= c1 && (cnt1 - c1) >= (cnt0 - c0)){
            // cout << i << endl;
            if(ans == -1 || (abs(n / 2 - ans) > abs(n / 2 - i)) || (abs(n / 2 - ans) >= abs(n / 2 - i) && (n & 1))) ans = i;
        }
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