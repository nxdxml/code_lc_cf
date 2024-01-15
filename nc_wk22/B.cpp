#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i += 2 ){
        if(s[i] == s[i + 1]) {
            cnt ++;
            ans = max(ans, cnt);
        } else {
            cnt = 0;
        }
    }
    cnt = 0;
    for(int i = 1; i < n; i += 2 ){
        if(s[i] == s[i + 1]) {
            cnt ++;
            ans = max(ans, cnt);
        } else {
            cnt = 0;
        }
    }
    cout << ans * 2 << endl;

    return 0;
}