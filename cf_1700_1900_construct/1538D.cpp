// 36 2 2 3 3
// 48 2 2 3 2 2
// 12 2 2 3
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

int cnt_f(int x){
    int cnt = 0;
    for(int i = 2; i * i <= x; i ++ ){
        while(x % i == 0){
            x /= i;
            cnt ++ ;
        }
    }
    if(x > 1) cnt ++ ;
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, a, b, k;
    cin >> T;
    while(T -- ){
        cin >> a >> b >> k;
        // a > b;
        if(a < b) swap(a, b);
        int min_k = (a % b == 0 && a != b) ? 1 : 2;
        int max_k = cnt_f(a) + cnt_f(b);
        // cout << min_k << " " << max_k << endl;
        // if(min_k <= k && k <= max_k) cout << "YES" << endl;
        // else cout << "NO" << endl;
        cout << ((min_k <= k && k <= max_k) ? "YES" : "NO") << endl;
    }
    return 0;
}



// #include <iostream>
// using namespace std;
// int pf(int x){
//     int ans=0;
//     for(int i=2;i*i<=x;i++) while(x%i==0) ans++, x/=i;
//     if(x>1) ans++;
//     return ans;
// }
// int main(){
//     int t,a,b,k;
//     cin>>t;
//     while(t--){
//         cin>>a>>b>>k;
//         if(a>b)swap(a,b);
//         int hi=pf(a)+pf(b);
//         int lo=b%a==0&&a!=b?1:2;
//         cout<<(lo<=k&&k<=hi?"YES":"NO")<<endl;
//     }
// }