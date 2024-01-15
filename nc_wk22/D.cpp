#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
const int N = 1e5 + 5;
int f[N][2];
int p[N], n, m;
struct edge{
    int a;
    int b;
    int w;
    bool operator< (const edge &E)const{
        return w < E.w;
    }
}edges[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}


long long ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        long long x;
        cin >> x;
        while(x % 2 == 0) x /= 2, f[i][0] ++ ;
        while(x % 5 == 0) x /= 5, f[i][1] ++ ;
    }

    for(int i = 0; i < m; i ++ ){
        int a, b;
        cin >> a >> b;
        int c = min(f[a][0] + f[b][0],f[a][1] + f[b][1]);
        ans += c;
        edges[i] = {a, b, c};
        
    }

    sort(edges, edges + m);
    for(int i = 1; i <= n; i ++ ) p[i] = i;
    int res = 0;
    for(int i = 0; i < m; i ++ ){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(p[a] != p[b]){
            p[a] = b;

            res += w;
        }
    }
    cout << ans - res << endl;


    return 0;
}