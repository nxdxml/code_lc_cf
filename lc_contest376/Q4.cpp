#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
// const int N = 1e5 + 5;
// mid1 = l + r >> 1;
// mid2 = l + r + 1 >> 1;
// cost[mid1] == cost[mid2];
int maxFrequencyScore(vector<int>& a, long long k) {
    sort(a.begin(), a.end());
    int i = 0, j = 0, ans = 0;
    long long cost = 0;
    int n = a.size();
    while(j < n){
        cost += a[j] - a[i + j >> 1];
        if(cost > k){
            // 第一次不合法
            ans = max(ans, j - i);
            while(cost > k){
                i ++ ;
                cost -= (a[i + j >> 1] - a[i - 1]);
            }
            
        }
        j ++ ;
    }
    ans = max(ans, j - i);
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long k;
    int n; cin >> n >> k;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    cout << maxFrequencyScore(a, k) << endl;

    return 0;
}

