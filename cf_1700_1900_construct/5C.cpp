#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    stack<int> stk;
    vector<int> f(n, 0);
    for(int i = 0; i < n; i ++ ){
        if(s[i] == '(') stk.push(i);
        else {
            if(stk.empty()) continue;
            f[stk.top()] = f[i] = 1;
            stk.pop();
        }
    }
    int cnt = 0;
    int max_len = 0;
    int t = 0;
    for(int i = 0; i < n; i ++ ){
        if(f[i]) t ++;
        else {
            if(t > max_len) max_len = t, cnt = 1;
            else if(t == max_len) cnt ++ ;
            t = 0;
        }
    }

    if(t > max_len) max_len = t, cnt = 1;
    else if(t == max_len) cnt ++ ;

    if(max_len == 0) cout << "0 1" << endl;
    else cout << max_len << " " << cnt << endl;
    

    return 0;
}