/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;


void solve(){
    int n, k;
    cin >> n >> k;
    cout << (n - 1 + k - 1 - 1) / (k - 1) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();    
    

    return 0;
}