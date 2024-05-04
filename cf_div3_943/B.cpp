/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    auto check = [&](int x){
        int i = 0, j = 0;
        for(; i < x; i ++ ){
            if(a[i] == b[j]) ;
            else {
                while(j < m && a[i] != b[j]){
                    j ++ ;
                }
            }
            if(j >= m) return false;
            j ++ ;
        }
        return true;
    };

    int l = 0, r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        // 11 1 00
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}