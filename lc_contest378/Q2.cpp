#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
// const int N = 1e5 + 5;

int maximumLength(string s) {
    int n = s.size();
    vector<priority_queue<int>> f(26);
    int cnt = 1;
    for(int i = 1; i < n; i ++ ){
        if(s[i] != s[i - 1]){
            // cout << s[i  - 1] << " " << cnt << endl;
            f[s[i - 1] - 'a'].push(cnt);
            cnt = 1;
        }
        else {
            cnt ++ ;
        }
    }
    f[s[n - 1] - 'a'].push(cnt);
    int ans = -1;
    for(int i = 0; i < 26; i ++ ){
        if(f[i].size() >= 3) {
            int a = f[i].top(); f[i].pop();
            int b = f[i].top(); f[i].pop();
            int c = f[i].top(); f[i].pop();
            if(a == b && b == c) ans = max(ans, a);
            else if(a == b) ans = max(ans, a - 1);
            else ans = max(ans, max(a - 2, b));
        }
        else if(f[i].size() == 2 && f[i].top() >= 2) {
            int a = f[i].top(); f[i].pop();
            int b = f[i].top(); f[i].pop();
            if(a == b) ans = max(ans, a - 1);
            else ans = max(ans, max(a - 2, b));
        }
        else if(f[i].size() == 1 && f[i].top() >= 3) ans = max(ans, f[i].top() - 2);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    cout << maximumLength(s) << endl;

    return 0;
}