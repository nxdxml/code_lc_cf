// d = 1
// sum0 = 0
// sum1 = 1*a1
// sum2 = 1*a1 + 2*a2
// sum3 = 1*a1 + 2*a2 + 3*a3
// sum4 = 1*a1 + 2*a2 + 3*a3 + 4*a4

// 1*a2 + 2*a3 + 3*a4 = sum[4] - sum[1] - 1 * (pre[4] - pre[1])
// 

// d = 2
// sum0 = 0
// sum2 = 1*a1
// sum4 = 1*a1 + 2*a3
// sum6 = 1*a1 + 2*a3 + 3*a5
// sum8=  1*a1 + 2*a3 + 3*a5 + 4*a7

// sum1 = 0
// sum3 = 1*a2
// sum5 = 1*a2 + 2*a4
// sum7 = 1*a2 + 2*a4 + 3*a6

// pre0 = 0
// pre2 = a1
// pre4 = a1 + a3
// pre6 = a1 + a3 + a5
// pre8 = a1 + a3 + a5 + a7

// pre1 = 0
// pre3 = a2
// pre5 = a2 + a4
// pre7 = a2 + a4 + a6

// sum[i] = sum[i - 2] + i/2 * a[i - 1]
// 对于 1*a3 + 2*a5 + 3*a7
// sum[8] - sum[2] - 1*(a3 + a5 + a7) = sum[8] - sum[2] - 1 * (pre[8] - pre[2])
// 


#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int M = 300;
const int N = 1e5 + 5 + M;

LL pre[M][N], sum[M][N];


void solve(){
    int n, q;
    cin >> n >> q;
    vector<LL> a(n + 1);
    for(int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        // cout << i << " " << a[i] << endl;    
    }
    

    for(int i = 1; i < M; i ++ ){
        for(int j = 1; j <= n + i - 1; j ++ ){
            if(j < i){
                pre[i][j] = 0, sum[i][j] = 0;
                // continue;
            } else {
                pre[i][j] = pre[i][j - i] + a[j - i + 1];
                sum[i][j] = sum[i][j - i] + a[j - i + 1] * (LL)(j/i);
                
            }
            // cout << i << " " << j << " " << pre[i][j] << " " << sum[i][j] << endl;
            
        }
    }
    int s, d, k;
    while(q -- ){
        cin >> s >> d >> k;
        int L = s - 1;
        int R = L + d * k;
        // cout << endl << L << " " << R << " ";
        if(d < M){
            cout << sum[d][R] - sum[d][L] - (pre[d][R] - pre[d][L]) * (LL)(L / d) << " ";
        } else {
            LL ans = 0;
            for(int i = 1; i <= k; i ++ ){
                ans += (LL)a[s + (i - 1) * d] * i;
            }
            cout << ans << " ";
        }
    }
    cout << endl;
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}