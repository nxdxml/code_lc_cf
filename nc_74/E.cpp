#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
// const int N = 1e5 + 5;
int n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    string s;
    cin >> s;
    // cout << n << m << s << endl;
    // return 0;
    int cnt = 0;
    for(int i = 1; i < n; i ++ ){
        if((s[i] == '0') && (s[i - 1] == '1')) cnt ++ ;
    }
    if(s[n - 1] == '1') cnt ++ ;
    while(m -- ){
        int l, r;
        cin >> l >> r;
        l --, r --;
        int x = s[l] - '0', y = s[r] - '0';
        int ll = (l == 0) ? 0 : (s[l - 1] - '0');
        int rr =  (r == n - 1) ? 0 : (s[r + 1] - '0');
        // 0 1 0 1
        // 1 1 0 0
        if((x ^ y) && (x ^ ll) && (y ^ rr)) cout << cnt - 1 << endl;
        else if((x ^ y) && (x == ll) && (y == rr)) cout << cnt + 1 << endl;
        else cout << cnt << endl;
    }
    

    return 0;
}