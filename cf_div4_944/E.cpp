/*

*/
#include<bits/stdc++.h>
#define int long long
const int N=1e5+5,M=305;
const int mod=1;
using namespace std;
int ksm(int a,int b){int res=1;for(;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;return res;}
void solve()
{
    int n,k,q;
    cin >> n >> k >> q;
    vector<int>a(k+1);
    vector<int>b(k+1);
    a[0] = 0;
    b[0] = 0;
    map<int,int>Hash;
    for(int i = 1; i <= k; i++){
        cin >> a[i];
        Hash[a[i]] = i;
    }
    for(int i = 1; i <= k; i++){
        cin >> b[i];
    }
    while (q--){
        int x;
        cin >> x;
        if(x == n){
            cout << b[k] << " ";
            continue;
        }
        int res = 0;
        int w = *std::upper_bound(a.begin(), a.end(),x);
        w = a[Hash[w]-1];
        res += b[Hash[w]];
        if(w != x){
            res += (x - w) * (b[Hash[w] + 1] - b[Hash[w]]) / (a[Hash[w] + 1] - a[Hash[w]]);
        }
        cout << res << " ";
    }
    cout << endl;
}
int tt;
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    tt=1;
    cin>>tt;
    while(tt--)solve();
    return 0;
}