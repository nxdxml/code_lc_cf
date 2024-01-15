#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        ll a, b;
        cin >> a >> b;
        int t = a * b / gcd(a, b);
        if(t == b) cout << b * (b / a) << endl;
        else cout << t << endl;
    }
    

    return 0;
}