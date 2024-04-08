#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    vector<bool> st(n + 1);
    int pos_x;
    for(int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(a[i] == x) pos_x = i;
    }
    int l = 1, r = n + 1;
    while((r - l) != 1){
        int mid = l + r >> 1;
        st[mid] = 1;
        if(a[mid] <= x) l = mid;
        else r = mid;
    }
    if(a[l] == x){
        cout << 0 << endl;
        return ;
    }
    if(!st[pos_x]){
        cout << 1 << endl;
        cout << l << " " << pos_x << endl;
        return ;
    }
    // a[l] > x

    for(int i = 1; i <= n; i ++ ){
        if(!st[i] && a[i] <= x){
            cout << 2 << endl;
            cout << l << " " << pos_x << endl;
            cout << i << " " << pos_x << endl;
            return ;
        }
    }
    cout << 1 << endl;
    cout << l << " " << pos_x << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}