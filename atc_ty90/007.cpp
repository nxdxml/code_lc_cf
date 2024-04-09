/*
查找数轴上的最近点
难度3星

二分
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
    
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a.begin(), a.end());
    cin >> m;
    for(int i = 0; i < m; i ++ ){
        int x;
        cin >> x;
        int l = 0, r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(a[mid] <= x) l = mid;
            else r = mid - 1;
        }
        
        cout << min(abs(x - a[l]), abs(x - a[min(n - 1, l + 1)])) << endl;
    }

    return 0;
}