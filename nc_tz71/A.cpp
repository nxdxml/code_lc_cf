#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
const int MOD = 998244353;
int n;

int q_pow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)res = ((long long)res * a) % MOD;
        a = ((long long)a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    long long sum = 0;
    for(int i = 0; i < n; i ++ ){
        int x;
        cin >> x;
        sum = (sum + x) % MOD;
    }
    for(int k = 1; k <= n; k ++ ){
        cout << sum * k % MOD * q_pow(n, MOD - 2) % MOD << " ";
    }
    

    return 0;
}