#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

bool solve(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int t = 0;
    for(int i = 0; i < n; i ++ ){
        x -= min((LL)(a[i] - t) * y, (LL)z);
        t = a[i];
        if(x <= 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
        

    return 0;
}