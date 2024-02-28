#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e5 + 5;
int a[N];
void solve(){
    int n;
    cin >> n;
    int sum = 0;
    bool fg1 = 0;
    bool fg2 = 0;
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
        sum += a[i];
        if(a[i] % 3 == 1) fg1 = 1;
        if(a[i] % 3 == 2) fg2 = 1; 
    }
    if(sum % 3 == 0) cout << 0 << endl;
    else if(sum % 3 == 1){
        if(fg1) cout << 1 << endl;
        else cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
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