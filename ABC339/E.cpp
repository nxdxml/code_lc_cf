#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 5e5 + 5;

struct SegTree {
    int mx[N << 2];
    void modify(int u, int l, int r, int x, int v) {
        mx[u] = max(mx[u], v);
        if(l == r) return ;
        int mid = l + r >> 1;
        if(x <= mid) modify(u << 1, l, mid, x, v);
        else modify(u << 1 | 1, mid + 1, r, x, v);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(l >= ql && r <= qr) return mx[u];
        if(ql > qr) return 0;
        int mid = l + r >> 1;
        if(qr <= mid) return query(u << 1, l, mid, ql, qr);
        if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
        return max(query(u << 1, l, mid, ql, qr), query(u << 1 | 1, mid + 1, r, ql, qr));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    // cout << "#";
    // return 0;
    SegTree tr;
    
    for(int i = 0; i < n; i ++ ){
        int x = a[i];
        tr.modify(1, 1, 500000, x, 1 + tr.query(1, 1, 500000, max(1, x - d), min(500000, x + d)));
    }
    cout << tr.mx[1] << endl;
    return 0;
}