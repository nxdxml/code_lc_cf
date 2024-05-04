/*
n个数字(1~n)选k个(1~n) 相差最小值大于k的数量,mod 1e9+7
难度6星

组合数
*/
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
static const LL mod=1000000007;
LL N;
LL fac[100005];
LL rev[100005];
LL modpow(LL a,LL n){
    LL res=1;
    while(0<n){
        if(n&1) res = (res * a) % mod;
        a=(a * a) % mod;
        n >>= 1;
    }
    return res;
}
void init(){
    fac[0] = 1;
    rev[0] = 1;
    for(LL i = 1; i < 100005; i ++ ){
        fac[i] = (i * fac[i - 1]) % mod;
        rev[i] = modpow(fac[i], mod - 2);
    }
}
LL comb(LL n,LL k){
    if(n < k) return 0;
    LL res = (fac[n] * rev[k]) % mod;
    res = (res * rev[n - k]) % mod;
    return res;
}
int main(){
    cin >> N;
    init();
    for(LL k = 1;k <= N; k ++){
    LL ans=0;
        for(LL m = 1; m <= N - (k - 1) * (m - 1); m ++ )
            ans=(ans + comb(N - (k - 1) * (m - 1), m)) % mod;
        cout << ans << '\n';
    }
    return 0;
}