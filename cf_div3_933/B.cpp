#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

bool solve(){
    int n;
    cin >> n;
    vector<int > a(n + 2);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < n; i ++ ){
        if(a[i] < 0) return false;
        a[i + 1] -= 2 * a[i];
        a[i + 2] -= a[i];
        a[i] = 0;
    }
    if(a[n] || a[n + 1]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) {
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    

    return 0;
}