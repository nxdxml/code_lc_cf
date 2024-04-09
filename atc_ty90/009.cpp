/*
N个点(<2000)求三个点确定的最大角度
难度6星

极坐标
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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2, 0));
    for(int i = 0; i < n; i ++ ){
        cin >> a[i][0] >> a[i][1];
    }
    double ans = 0.0;
    for(int i = 0; i < n; i ++ ){
        vector<double> f(n - 1);
        int idx = 0;
        for(int j = 0; j < n; j ++ ){
            if(i == j) continue;
            int x1 = a[i][0];
            int y1 = a[i][1];
            int x2 = a[j][0];
            int y2 = a[j][1];
            f[idx ++ ] = atan2(x1 - x2, y1 - y2) * 180 / M_PI;
        }
        sort(f.begin(), f.end());
        int l = 0, r = 0;
        while(r < n - 1){
            double t = f[r] - f[l];
            ans = max(ans, min(t, 360 - t));
            if(t < 180) r ++ ;
            else l ++ ;
        }
    }
    printf("%.14lf\n", ans);
    

    return 0;
}