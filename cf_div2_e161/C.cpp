#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

void solve(){
    int n, m;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    // 0 8 12 15 20
    cin >> m;
    vector<int> pre(n + 1);
    pre[2] = 1;
    for(int i = 3; i <= n; i ++ ){
        int t1 = a[i - 1] - a[i - 2];
        int t2 = a[i] - a[i - 1];
        if(t1 < t2) pre[i] = pre[i - 1] + t2;
        else pre[i] = pre[i - 1] + 1;
    }

    vector<int> post(n + 1);

    post[n - 1] = 1;
    for(int i = n - 2; i >= 0; i -- ){
        int t1 = a[i + 1] - a[i];
        int t2 = a[i + 2] - a[i + 1];
        if(t1 < t2) post[i] = post[i + 1] + 1;
        else post[i] = post[i + 1] + t1;
    }


    while(m -- ){
        int l, r;
        cin >> l >> r;
        if(l < r) cout << pre[r] - pre[l] << endl;
        else cout << post[r] - post[l] << endl;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}