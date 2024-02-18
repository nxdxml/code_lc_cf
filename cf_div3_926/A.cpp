#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T -- ){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < n; i ++ ){
            if(s[i] == '*' && s[i - 1] == '*') break;
            ans += s[i] == '@';
        }
        cout << ans << endl;
    }
    

    return 0;
}