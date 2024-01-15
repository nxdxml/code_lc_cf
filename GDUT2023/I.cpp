#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
const int N = 1005;
int n, m;
int f[N], g[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    memset(f, 0x3f, sizeof f);
    f[m] = 0;
    
    for(int i = 1; i <= n; i ++ ){
        int x;
        cin >> x;
        memcpy(g, f, sizeof g);
        for(int j = 0; j <= 1000; j ++ ){
            int k = abs(j - x);
            g[k] = min(g[k], f[j] + 1);
        }
        swap(f, g);
    }
    if(f[0] == 0x3f3f3f3f){
        cout << -1 << endl;
        return 0;
    }
    cout << f[0] << endl;
    return 0;
}