/*
    最大的数字频率x能有x - 1个坑，其他的思考怎么往这里面填就行了
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
int a[N];
void solve(){
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; i ++ ) {
        cin >> a[i];
        cnt[a[i]] ++ ;
    }
    sort(cnt.begin(), cnt.end());
    int sum = 0;
    for(int i = n - 1; i >= 1; i -- ){
        if(cnt[i] == cnt[n]) sum += cnt[n] - 1;
        else sum += cnt[i];
    }
    cout << sum / (cnt[n] - 1) << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}