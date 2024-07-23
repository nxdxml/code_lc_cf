/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 1005;
int a[N];
LL pw(int a, int b){
    LL ret = 1LL;
    while(b > 0){
        b --;
        ret *= a;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;
    n -- ;
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int l = 1;
    for( ; ; l ++ ){
        int k = (l + 1) >> 1;
        LL d = 9LL * pw(10, k - 1);
        if(n > d){
            n -= d;
        } else {
            n -- ;
            // cout << n << endl;
            int idx = 0;
            while(n){
                a[idx ++ ] = n % 10;
                n /= 10;
            }
            a[k - 1] ++;
            for(int i = k - 1; i >= 0; i -- ) cout << a[i];
            for(int i = (l & 1); i < k; i ++ ) cout << a[i];
            cout << endl;
            return 0;
        }
    }

    return 0;
}