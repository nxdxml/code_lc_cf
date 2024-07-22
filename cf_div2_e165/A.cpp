/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 55;
int a[N], p[N], sz[N];

int find(int x){
    if(p[x] == x) return p[x];
    return p[x] = find(p[x]);
}

void merge(int a, int b){
    int pa = find(a), pb = find(b);
    if(pa != pb){
        p[pa] = pb;
        sz[pb] += sz[pa];
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ) p[i] = i, sz[i] = 1;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    
    for(int i = 1; i <= n; i ++ ) merge(a[i], i);
    vector<int> f;
    for(int i = 1; i <= n; i ++ ){
        if(find(i) == i) f.push_back(sz[i]);
    }
    sort(f.begin(), f.end());
    cout << min(3, f[0]) << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();
    return 0;
}