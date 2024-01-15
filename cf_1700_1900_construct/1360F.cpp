#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
const int N = 15;
char g[N][N];



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i ++ ) cin >> g[i];
        string s = "";
        for(int i = 0; i < m; i ++ ) s = s + g[0][i];

        string ans = "-1";

        for(int i = 0; i < m; i ++ ){
            for(int j = 0; j < 26; j ++ ){
                string p = s;
                p[i] = 'a' + j;

                auto check = [&](string t) -> bool {
                    for(int c = 1; c < n; c ++ ){
                        int cnt = 0;
                        for(int d = 0; d < m; d ++ ){
                            if(g[c][d] != t[d]) cnt ++ ;
                        }
                        if(cnt > 1) return false;
                    }
                    return true;
                };

                if(check(p)) ans = p;

            }
        }
        cout << ans << endl;
    }
    

    return 0;
}