#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    LL sum = 0;
    for(int i = 0; i < m; i ++ ){
        int x;
        cin >> x;
        sum += a[x];
    }
    cout << sum << endl;
    return 0;
}