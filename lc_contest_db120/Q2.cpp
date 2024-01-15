#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;
long long incremovableSubarrayCount(vector<int>& a) {
    int n = a.size();
    if(n == 1) return 1;
    
    int idx = 0;
    ll ans = 1;
    for(int i = 0; i < n; i ++ ){
        if(i == 0 || a[i] > a[i - 1]) {
            ans ++ ;
            idx ++ ;
        }
        else break;
    }
    if(idx == n) return ll(n + 1) * n / 2;

    // cout << "idx;" << idx << endl;
    for(int i = n - 1; i >= 0; i -- ){
        if(i == n - 1 || a[i + 1] > a[i]){
            int l = 0, r = idx - 1;
            // <a[i]的第一个数
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(a[mid] < a[i]) l = mid;
                else r = mid - 1;
            }
            if(a[i] <= a[0]) r = -1;
            // cout << a[i] << " " << r << endl;
            ans += r + 2;

        } else break;
    }

    return ans;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    cout << incremovableSubarrayCount(a) << endl;
    

    return 0;
}