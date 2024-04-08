#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 1e5 + 5;
struct SegTree {
    LL sm[N << 2], lz[N << 2];
    void modify(int u, int l, int r, int x, int v){
        sm[u] += v;
        if(l == r) return ;
        int mid = l + r >> 1;
        if(x <= mid) modify(u << 1, l, mid, x, v);
        else modify(u << 1 | 1, mid + 1, r, x, v);
    }

    void change(int u, int l, int r, int cl, int cr, int v){
        if(cl <= l && r <= cr){
            sm[u] += (LL)v * (r - l + 1);
            lz[u] += v;
            return ;
        }
        int mid = l + r >> 1;

        // spread
        if(lz[u]){
            sm[u << 1] += lz[u] * (mid - l + 1);
            sm[u << 1 | 1] += lz[u] * (r - mid);
            lz[u << 1] += lz[u];
            lz[u << 1 | 1] += lz[u];
            lz[u] = 0;
        }

        
        if(cl <= mid) change(u << 1, l, mid, cl, cr, v);
        if(cr > mid) change(u << 1 | 1, mid + 1, r, cl, cr, v);
        sm[u] = sm[u << 1] + sm[u << 1 | 1];
    }

    LL query(int u, int l, int r, int ql, int qr){
        if(ql <= l && r <= qr) return sm[u];
        if(ql > qr) return 0;
        int mid = l + r >> 1;

        // spread
        if(lz[u]){
            sm[u << 1] += lz[u] * (mid - l + 1);
            sm[u << 1 | 1] += lz[u] * (r - mid);
            lz[u << 1] += lz[u];
            lz[u << 1 | 1] += lz[u];
            lz[u] = 0;
        }

        if(qr <= mid) return query(u << 1, l, mid, ql, qr);
        if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
        return query(u << 1, l, mid, ql, qr) + query(u << 1 | 1, mid + 1, r, ql, qr);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int n, m;
    // cin >> n >> m;
    // int R = 100000;
    // SegTree tr;
    // for(int i = 1; i <= n; i ++ ){
    //     int x;
    //     cin >> x;
    //     tr.modify(1, 1, R, i, x);
    // }
    // while(m -- ){
    //     int op;
    //     cin >> op;
        
    //     if(op == 1){
    //         int cl, cr, v;
    //         cin >> cl >> cr >> v;
    //         tr.change(1, 1, R, cl, cr, v);
    //     } else {
    //         int ql ,qr;
    //         cin >> ql >> qr;
    //         cout << tr.query(1, 1, R, ql, qr) << endl;
    //     }
    // }
    
    int n, m;
    cin >> n >> m;
    vector<PII> d(m);
    SegTree tr;
    int R = 100000;
    int ans = 0;
    for(int i = 0; i < m; i ++ ){
        cin >> d[i].first >> d[i].second;
    }
    for(int i = 0; i < 1 << m; i ++ ){
        // 修改
        for(int j = 0; j < m; j ++ ){
            if(i >> j & 1){
                int cl = d[j].first;
                int cr = d[j].second;
                tr.change(1, 1, R, cl, cr, 1);
            }
        }
        // check
        bool fg = 1;
        for(int j = 0; j < m; j ++ ){
            if(i >> j & 1){
                int ql = max(d[j].first - 1, 1);
                int qr = min(d[j].second + 1, 100000);
                int t1 = tr.query(1, 1, R, ql, ql);
                int t2 = tr.query(1, 1, R, qr, qr);
                if(t1 <= 1 || t2 <= 1){
                    fg = 0;
                    break;
                }
            }
        }
        ans += fg;
        // 还原
        for(int j = 0; j < m; j ++ ){
            if(i >> j & 1){
                int cl = d[j].first;
                int cr = d[j].second;
                tr.change(1, 1, R, cl, cr, -1);
            }
        }
    }
    cout << ans << endl;

    return 0;
}