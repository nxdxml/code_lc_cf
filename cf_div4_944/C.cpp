/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

bool solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    if(a < c && c < b && d > b) return true;
    if(a < c && c < b && d < a) return true;

    if(c < a && a < d && b > d) return true;
    if(c < a && a < d && b < c) return true;


    return false;
    
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