#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 5005;
bool st[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    st[0][0] = 1;
    for(int i = 1; i <= m; i ++ ){
        int x;
        cin >> x;
        for(int j = 0; j < n; j ++ ){
            if(st[i - 1][j]){
                st[i][(j + x) % n] = 1;
                st[i][((j - x) % n + n) % n] = 1;
            }
        }
        
    }
    if(st[m][0]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}