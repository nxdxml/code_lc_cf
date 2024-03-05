#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 105;
int a[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int sum = accumulate(a, a + n, 0);
    int mx = *max_element(a, a + n);
    if(mx * 2 > sum || (sum & 1)) cout << "T" << endl;
    else cout << "HL" << endl;
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