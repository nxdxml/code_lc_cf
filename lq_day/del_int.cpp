#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
typedef pair<LL, int> PLI;
const int N = 5e5 + 5;
LL a[N];
int pre[N], back[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    back[0] = 1;
    priority_queue<PLI, vector<PLI>, greater<PLI>> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        pre[i] = i - 1;
        back[i] = i + 1;
        q.push({a[i], i});
    }
    int cnt = 0;
    auto f = [&]() {
        auto [x, pos] = q.top(); q.pop();
        if(x != a[pos]) return;
        cnt ++ ;
        a[pre[pos]] += a[pos];
        a[back[pos]] += a[pos];
        if(back[pos] <= n) q.push({a[back[pos]], back[pos]});
        if(pre[pos] > 0) q.push({a[pre[pos]], pre[pos]});
        pre[back[pos]] = pre[pos];
        back[pre[pos]] = back[pos];
    };
    while(cnt < k){
        f();
    }
    int pos = back[0];
    while(pos <= n){
        cout << a[pos] << ' ';
        pos = back[pos];
    }
    return 0;
}