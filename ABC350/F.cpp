/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;
const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    auto encrypt = [&](){
        A = 1 + (((a * (1 + cnt)) % MOD) % 2);
        B = 1 + (((b * (1 + cnt)) % MOD) % n);
        C = 1 + (((c * (1 + cnt)) % MOD) % n);
        if(A == 2) cnt ++ ; 
    };
    for(int i = 0; i < m; i ++ ){
        int a, b, c;
        int A, B, C;
        cin >> a >> b >> c;
        encrypt();
       
    }
    

    return 0;
}