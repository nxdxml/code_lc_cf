#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> l, r;
    for(int i = 0; i < n; i ++ ){
        if(s[i] == '<')l.push_back(i);
        else r.push_back(i);
    }
    vector<LL> sl(l.size() + 1), sr(r.size() + 1);
    for(int i = 0; i < l.size(); i ++ ){
        sl[i + 1] = sl[i] + l[i];
    }
    for(int i = 0; i < r.size(); i ++ ){
        sr[i + 1] = sr[i] + r[i];
    }
    
    for(int i = 0; i < n; i ++ ){
        // int a = ranges::lower_bound(r, i + 1) - r.begin();
        // int b = ranges::lower_bound(l, i) - l.begin();
        int a = lower_bound(r.begin(), r.end(), i + 1) - r.begin();
        int b = lower_bound(l.begin(), l.end(), i) - l.begin();
        // cout << "a=" << a << ' ' << "b=" << b << endl;
        LL ans = 0;
        if (s[i] == '<') {
            if (l.size() - b > a) {
                ans = 2 * (sl[b + 1 + a] - sl[b + 1]) - 2 * sr[a] + i + 1;
            } else {
                int t = l.size() - b;
                ans = 2 * (sl[b + t] - sl[b + 1]) - 2 * (sr[a] - sr[a - t]) + i + n;
            }
        } else {
            if (a > l.size() - b) {
                int t = l.size() - b;
                ans = 2 * (sl[b + t] - sl[b]) - 2 * (sr[a - 1] - sr[a - 1 - t]) + n - i;
            } else {
                ans = 2 * (sl[b + a] - sl[b]) - 2 * sr[a - 1] - i + 1;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}