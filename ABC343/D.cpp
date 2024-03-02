#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 2e5 + 5;
LL a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    map<LL, int > mp;
    mp[0] = n;
    for(int i = 1; i <= m; i ++ ){
        int x, y;
        cin >> x >> y;
        if(--mp[a[x]] == 0) mp.erase(a[x]);
        a[x] += y;
        mp[a[x]] ++;
        cout << mp.size() << endl;
    }

    return 0;
}