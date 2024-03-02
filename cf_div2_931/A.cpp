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
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    sort(a, a + n);
    cout << (a[n - 1] - a[0]) + (a[n - 1] - a[1]) + (a[n - 2] - a[0]) + (a[n - 2] - a[1]) << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}