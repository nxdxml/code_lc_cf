#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a.begin(), a.end());
    if(n == 2){
        cout << (a[0] != a[1]) << endl;
        return ; 
    }
    if(n == 3){
        cout << (a[0] != a[1]) + (a[1] != a[2]) << endl;
        return ;
    }
    if(a[0] == a[1] && a[n - 1] == a[n - 2]) {
        cout << 0 << endl;
        return ;
    }
    if(a[0] == a[1] || a[n - 1] == a[n - 2]){
        cout << 1 << endl;
        return ;
    }
    if(a[1] == a[2] || a[n - 2] == a[n - 3]){
        cout << 1 << endl;
        return ;
    }
    cout << 2 << endl;
    
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