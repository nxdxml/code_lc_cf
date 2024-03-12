/*
    枚举选择的最大最小b，一定会选到答案需要的2个b
    在这种情况下通过multiset不断删除最大元素直到满足条件
    n^2logn
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, L;
    cin >> n >> L;
    vector<PII> f(n);
    for(int i = 0; i < n; i ++ ){
        cin >> f[i].second >> f[i].first;
    } // b a
    sort(f.begin(), f.end());
    int ans = 0;
    for(int l = 0; l < n; l ++ ){
        int cur = 0;
        multiset<int> s;
        for(int r = l; r < n; r ++ ){
            s.insert(f[r].second);
            cur += f[r].second;
            while(!s.empty() && f[r].first - f[l].first + cur > L){
                int max_val = *s.rbegin();
                cur -= max_val;
                s.extract(max_val);
            }
            ans = max(ans, (int)s.size());
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}