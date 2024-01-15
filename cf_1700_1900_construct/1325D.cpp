// a + b = a ^ b + 2(a & b)
// a ^ b = u
// a + b = v
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll u, v;
    cin >> u >> v;
    
    if(u > v || (u % 2 != v % 2)) cout << "-1" << endl;
    else if(u == v){
        if(u == 0) cout << 0 << endl;
        else {
            cout << 1 << endl << u << endl;
        }
    } else {
        ll x = (v - u) / 2;
        if((x & u) == 0){
            cout << 2 << endl << x + u << " " << x << endl;
        } else {
            cout << 3 << endl << u << " " << x << " " << x << endl;
        }
    }

    return 0;
}