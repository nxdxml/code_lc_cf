/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

bool solve(){
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = "#" + s;
    int pos = 0;
    while(true){
        bool fg = 1;
        for(int j = m; j >= 1; j -- ){
            if(j + pos >= n + 1) return 1;
            if(s[j + pos] == 'L'){
                pos += j;
                fg = 0;
                break;
            }
        }
        bool fg2 = 1;
        if(fg){
            for(int j = m; j >= 1; j -- ){
                // if(j + pos >= n + 1) return 1;
                if(s[j + pos] == 'W'){
                    pos += j;
                    fg2 = 0;
                    break;
                }
            }
            while(pos + 1 <= n + 1){
                if(pos + 1 == n + 1) {
                    if(k > 0) return 1;
                    else return 0;
                }
                if(s[pos + 1] == 'W'){
                    if(k > 0) {
                        pos ++ ;
                        k -- ;
                    }
                    else return 0;
                } else if(s[pos + 1] == 'C'){
                    return 0;
                } else {
                    if(k > 0) {
                        pos ++ ;
                        k -- ;
                        break;
                    }
                    else return 0;
                }
            }
        }
        // cout << fg << " " << fg2 << endl;
        if(fg && fg2) return 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    cin >> T;
    while(T -- ) {
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}