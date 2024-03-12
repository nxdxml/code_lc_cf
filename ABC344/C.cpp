#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 105;
int f[3][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, l, t;
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> f[0][i];
    cin >> m;
    for(int i = 0; i < m; i ++ ) cin >> f[1][i];
    cin >> l;
    for(int i = 0; i < l; i ++ ) cin >> f[2][i];
    set<int> s;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            for(int k = 0; k < l; k ++ ){
                int x = f[0][i] + f[1][j] + f[2][k];
                s.insert(x);
            }
        }
    }
    cin >> t;

    while(t -- ){
        int x;
        cin >> x;
        if(s.find(x) != s.end()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}