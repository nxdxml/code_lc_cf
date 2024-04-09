#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    if(a * 2 <= b){
        cout << a * n << endl;
        return ;
    }
    if(n & 1){
        cout << a + (n / 2) * b << endl;
    } else {
        cout << (n / 2) * b << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}