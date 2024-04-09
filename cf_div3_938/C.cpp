#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int a[N];
void solve(){
    int n;
    LL k;
    cin >> n >> k;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int l = 0, r = n - 1;
    LL sum = 0;
    while(l < r){
        if(a[l] <= a[r]){
            if(sum + a[l] * 2 <= k){
                sum += a[l] * 2;
                a[r] -= a[l];
                l ++ ;
            } else {
                if(sum + a[l] * 2 - 1 <= k) {
                    sum += a[l] * 2 - 1;
                    l ++ ;
                }
                break;
            }
        } else {
            if(sum + a[r] * 2 <= k){
                sum += a[r] * 2;
                a[l] -= a[r];
                r -- ;
            } else {
                break;
            }
        }
    }
    if(l == r && sum + a[l] <= k) l ++ ;
    // cout << l << " " << r << endl;
    cout << l + (n - 1 - r) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}