/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int a[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i ++ ) cin >> a[i];
    int t = 1e8;
    cout << t << " ";
    for(int i = 0; i < n - 1; i ++ ) {
        t += a[i];
        cout << t << " ";    
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