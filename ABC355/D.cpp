/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<PII> a(n);
    for(int i = 0; i < n; i ++ ){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](const auto& t1, const auto& t2){
        return t1.first < t2.first;
    });

    LL ans = 0;
    priority_queue<int, vector<int>, greater<>> q;
    for(int i = 0; i < n; i ++ ){
        int l = a[i].first, r = a[i].second;
        while(q.size() && q.top() < l) q.pop();
        ans += q.size();
        
        q.push(r);
    }
    cout << ans << endl;
    

    return 0;
}