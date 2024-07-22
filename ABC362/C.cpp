/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int a[N][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    LL l_sum = 0, r_sum = 0;
    vector<int> ans(n);
    for(int i = 0; i < n; i ++ ){
        cin >> a[i][0] >> a[i][1];
        l_sum += a[i][0];
        r_sum += a[i][1];
        ans[i] = a[i][1];
    }

    if(r_sum < 0 || l_sum > 0){
        cout << "No" << endl;
        return 0;
    }

    for(int i = 0; i < n; i ++ ){
        int delta = a[i][1] - a[i][0];
        if(r_sum > delta) {
            ans[i] = a[i][0];
            r_sum -= delta;
        } else {
            ans[i] -= r_sum;
            break;
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < n; i ++ ) cout << ans[i] << " ";
    cout << endl;

    return 0;
}