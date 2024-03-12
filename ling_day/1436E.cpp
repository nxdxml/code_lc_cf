#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 1e5 + 5;

struct SegTree {
    int mn[N << 2];
    void modify(int u, int l, int r, int x, int v){
        // mn[u] = min(mn[u], v);
        // mn[u] = v;
        if(l == r) {
            mn[u] = v;
            return ;
        }
        int mid = l + r >> 1;
        if(x <= mid) modify(u << 1, l, mid, x, v);
        else modify(u << 1 | 1, mid + 1, r, x, v);
        mn[u] = min(mn[u << 1], mn[u << 1 | 1]);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(ql <= l && r <= qr) return mn[u];
        if(ql > qr) return 0;
        int mid = l + r >> 1;
        if(qr <= mid) return query(u << 1, l, mid, ql, qr);
        if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
        return min(query(u << 1, l, mid, ql, qr), query(u << 1 | 1, mid + 1, r, ql, qr));
    }
};
// 上一次出现位置
int last[N], a[N];
bool st[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    SegTree tr;
    for(int i = 1; i < (N << 2); i ++ ) tr.mn[i] = 0;
    for(int i = 1; i <= n; i ++ ){
        int x = a[i];
        if(x == 1) st[2] = 1;
        else {
            st[1] = 1;
            if(tr.query(1, 1, 100000, 1, x - 1) > last[x]) st[x] = 1;
        }
        tr.modify(1, 1, 100000, a[i], i);
        last[x] = i;
    }
    for(int x = 2; x <= n + 1; x ++ ){
        // cout << x << ' ' << tr.query(1, 1, 100000, 1, x - 1) << endl;
        if(tr.query(1, 1, 100000, 1, x - 1) > last[x]) st[x] = 1;
    }

    // return 0;
    for(int i = 1; ; i ++ ){
        if(!st[i]){
            cout << i << endl;
            return 0;
        }
    }


    return 0;
}