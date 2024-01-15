#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
int T, n;
int idx, h[N], e[N], ne[N];
LL a[N];
void add(int x, int y){
    e[idx] = y; ne[idx] = h[x]; h[x] = idx ++ ;
}

LL dfs1(int u){
    if(h[u] == -1){
        return a[u];
    }
    LL t = 0;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        t = max(t, dfs1(j));
    }
    return max(a[u] - t, t);
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T -- ){
        cin >> n;
        idx = 0;
        for(int i = 0; i <= n; i ++ ) h[i] = -1;
        for(int i = 2; i <= n; i ++ ){
            cin >> a[i];
        }
        for(int i = 2; i <= n; i ++ ){
            int b;
            cin >> b;
            add(b, i);
        }
        cout << dfs1(1) << endl;

    }
    

    return 0;
}