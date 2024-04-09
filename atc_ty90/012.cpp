/*
给一个n*m的网格(<=2000*2000)
有两个操作，1为涂色，二为判断是否涂色可达(op_cnt <= 1e5)
难度4星

并查集
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;
int p[2005*2005];
bool st[2005][2005];
int find(int x){
    if(p[x] == x) return p[x];
    return p[x] = find(p[x]);
}

void merge(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa != pb){
        p[pa] = pb;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, Q;
    cin >> n >> m >> Q;
    for(int i = 0; i < n * m; i ++ ) p[i] = i;
    while(Q -- ){
        int op;
        cin >> op;
        auto conv = [&](int i, int j){
            return i * m + j;
        };
        if(op == 1){
            int r1, c1;
            cin >> r1 >> c1;
            r1 --, c1 -- ;
            st[r1][c1] = 1;
            if(r1 >= 1 && st[r1 - 1][c1]) merge(conv(r1, c1), conv(r1 - 1, c1));
            if(c1 >= 1 && st[r1][c1 - 1]) merge(conv(r1, c1), conv(r1, c1 - 1));
            if(r1 < n - 1 && st[r1 + 1][c1]) merge(conv(r1, c1), conv(r1 + 1, c1));
            if(c1 < m - 1 && st[r1][c1 + 1]) merge(conv(r1, c1), conv(r1, c1 + 1));
        } else {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1 --, c1 -- , r2 -- , c2 -- ;
            if(st[r1][c1] && find(conv(r1, c1)) == find(conv(r2, c2))) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    

    return 0;
}