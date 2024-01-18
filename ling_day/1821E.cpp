#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

void solve(){

    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();

    stack<int> stk;
    vector<int> f;
    for(int i = 0; i < n; i ++ ){
        if(s[i] == '(') stk.push(i);
        else if(s[i] == ')'){
            int j = stk.top();
            stk.pop();
            f.push_back((i - j) / 2);
        }
    }

    sort(f.begin(), f.end());

    int m = f.size();
    LL ans = 0;

    for(int i = 0; i < m - k; i ++ ){
        ans += f[i];
    }
    cout << ans << endl;
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    // cout << T << endl;
    while(T -- ) solve();
    

    return 0;
}