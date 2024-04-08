#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;
void solve(){
    int a, b;
    cin >> a >> b;
    a %= 3;
    b %= 3;
    if(a == b) {
        cout << "Yes\n";
        return ;
    }
    cout << "No\n";
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