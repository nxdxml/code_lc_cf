#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

long long findMaximumNumber(long long k, int x) {
    auto check = [&](LL num) {
        // __builtin_clzll 前导零的个数
        int m = 64 - __builtin_clzll(num);
        // cout << num << " " << m << endl;
        vector<vector<LL>> memo(m, vector<LL>(m + 1, -1));
        function<LL(int, int, bool)> dfs = [&](int i, int cnt, bool is_limit) -> LL {
            if(i < 0) return cnt;
            if(!is_limit && memo[i][cnt] >= 0 ) return memo[i][cnt];

            int lo = 0;
            int hi = is_limit ? num >> i & 1 : 1;
            LL res = 0;
            for(int d = lo; d <= hi; d ++ ){
                res += dfs(i - 1, cnt + (d == 1 && (i + 1) % x == 0), is_limit && d == hi);
            }
            if(!is_limit) memo[i][cnt] = res;
            return res;
        };
        return dfs(m - 1, 0, true) <= k;
    };

    LL l = 0, r = 1e16;

    // <= k的最大数字
    while(l < r){
        LL mid = (l + r) / 2;
        if(!check(mid)) r = mid;
        else l = mid + 1;
    }
    return r - 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL k;
    int x;
    cin >> k >> x;

    cout << findMaximumNumber(k, x) << endl; 


    return 0;
}