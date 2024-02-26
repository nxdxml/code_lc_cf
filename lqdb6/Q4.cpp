#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;
int st[10] = {1,0,0,0,1,0,1,0,2,1};
LL memo[20][30];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string L, R;
    int K;
    cin >> L >> R >> K;
    bool fg = (L.size() == 1 && L[0] == '0');
    int n = R.size();
    while(L.size() < n){
        L = "0" + L;
    }
    memset(memo, -1, sizeof memo);
    function<LL(int,int,bool,bool,bool)> dfs = [&](int i, int cnt, bool limitL, bool limitH, bool is_num) -> LL {
        // cout << i << " " << cnt << endl;
        if(i == n) return (cnt == K) && is_num;
        if(is_num && !limitL && !limitH && memo[i][cnt] != -1) return memo[i][cnt];
        int lo = limitL ? L[i] - '0' : 0;
        int hi = limitH ? R[i] - '0' : 9;
        LL ret = 0;
        if(!is_num && lo == 0) ret = dfs(i + 1, cnt, true, false, false);

        int d0 = is_num ? 0 : 1;

        for(int d = max(lo, d0); d <= hi; d ++ ){
            ret += dfs(i + 1, cnt + st[d], limitL && d == lo, limitH && d == hi, true);
        }
        if(is_num && !limitL && !limitH )memo[i][cnt] = ret;
        return ret;

    };
    cout << dfs(0, 0, true, true, false) + fg << endl;

    return 0;
}