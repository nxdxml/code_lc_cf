#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 15;
char g[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T -- ){
        int n; cin >> n;
        for(int i = 0; i < n; i ++ ){
            cin >> g[i];
        }
        bool fg = 0;
        for(int i = 0; i < n; i ++ ){
            for(int j = 0; j < n; j ++ ){
                if(g[i][j] == '1'){
                    if(g[i + 1][j + 1] == '1' && g[i][j + 1] == '1' && g[i + 1][j] == '1'){
                        cout << "SQUARE" << endl;
                    } else {
                        cout << "TRIANGLE" << endl;
                    }
                    fg = 1;
                    break;
                }
            }
            if(fg) break;
        }
    }

    return 0;
}