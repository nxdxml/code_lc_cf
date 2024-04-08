/*
把长L的杆子中的N个切口选K个切下去，求分成的K+1块最短长度的最大值
1 <= K <= N <= 1e5
0 < L <= 1e9
难度4星

二分贪心
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, L, k;
    cin >> n >> L >> k;
    vector<int> a(n + 2);
    a[n + 1] = L;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    
    auto ck = [&](int x){
        int i, j = 0;
        int cnt = 0;
        for(i = 1; i <= n + 1; i ++ ){
            if(a[i] - a[j] >= x){
                j = i;
                cnt ++ ;
                if(cnt >= k + 1) return true;
            }
        }
        return false;
    };

    int l = 1, r = 1e9;
    while(l < r){
        int mid = l + r + 1 >> 1;
        // cout << mid << " " << ck(mid) << endl;
        if(ck(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}