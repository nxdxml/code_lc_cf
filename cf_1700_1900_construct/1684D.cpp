#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    LL sum = 0;
    for(int i = 0; i < n; i ++ ){
        sum += a[i];
        a[i] -= (n - i - 1);
        // cout << a[i] << " ";
    }
    sort(a.begin(), a.end());
    for(int i = n - 1; i >= n - k; i -- ){
        sum -= a[i];
        
    }
    sum -= (LL)k * (k - 1) / 2;
    cout << sum << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();
    return 0;
}