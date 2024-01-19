#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

void solve(){
    LL x; cin >> x;
    x --;
    // +0       t + 1
    // + >max   t*2+1
    // t == x
    int cur = 99;
    vector<int> ans;
    while(x){
        if(x % 2) ans.push_back(cur -- ), x /= 2;
        else ans.push_back(0), x --;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto y : ans) cout << y << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T -- ) solve();
    

    return 0;
}