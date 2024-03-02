#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    cout << "? 1 1" << endl;
    fflush(stdout);
    int x;
    cin >> x;
    fflush(stdout);
    if(x == 0){
        cout << "! 1 1" << endl;
        fflush(stdout);
        return ;
    }
    int a = x + 1, b = 1;
    int c = 1, d = x + 2 - 1;
    if(a >= n + 1){
        a = n;
        b = x + 2 - n;
    }
    if(d >= m + 1){
        d = m;
        c = x + 2 - m;
    }
    cout << "? " << a << " " << b << endl;
    fflush(stdout);
    cin >> x;
    // cout << "x=" << x << endl;
    fflush(stdout);
    if(x == 0){
        cout << "! " << a << " " << b << endl;
        fflush(stdout);
        return ;
    }
   
    cout << "? " << c << " " << d << endl;
    int y;
    cin >> y;
    fflush(stdout);
    if(y == 0){
        cout << "! " << c << " " << d << endl;
        fflush(stdout);
        return ;
    }
    if((x & 1) || (a - x/2 < 1)){
        cout << "! " << c + y/2 << " " << d - y/2 << endl;
        fflush(stdout);
        return ;
    }
    if((y & 1)){
        cout << "! " << a - x/2 << " " << b + x/2 << endl;
        fflush(stdout);
        return ;
    }
    cout << "? " << a - x/2 << " " << b + x/2 << endl;
    fflush(stdout);
    int z;
    cin >> z;
    fflush(stdout);
    if(z == 0){
        cout << "! " << a - x/2 << " " << b + x/2 << endl;
        fflush(stdout);
        return ;
    }
    cout << "! " << c + y/2 << " " << d - y/2 << endl;
    fflush(stdout);
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        solve();
    }

    return 0;
}