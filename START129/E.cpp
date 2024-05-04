#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    if(n == 1 || (k & 1) || n > k) {
        cout << -1 << endl;
        return ;
    }
    vector<int> a(n);
    int sum = k - n + 2;
    for(int i = 0; i < n; i ++ ){
        if(i < n - 2) a[i] = 1;
        else if(i == n - 2){
            a[i] = sum / 2;
        } else if(i == n - 1) {
            a[i] = sum - sum / 2;
        }
    }
    // int ck = 0;
    // int ss = 0;
    for(int i = 0; i < n; i ++ ){
        cout << a[i];
        if(i != n - 1) cout << " ";
        // ck ^= a[i];
        // ss += a[i];
    }
    cout << endl;
    // cout << (ck == 0 || ss == k) << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}