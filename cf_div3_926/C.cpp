#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
int a[N], b[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i ++ ){
            cin >> a[i];
        }
        string s;
        cin >> s;
        int ll = 0, rr = n - 1;
        for(int i = 0; i < n; i ++ ){
            if(s[i] == 'L') b[n - i - 1] = a[ll ++ ];
            else b[n - i - 1] = a[rr -- ];
        }
        int t = 1;
        vector<int> ans;
        for(int i = 0; i < n; i ++ ){
            t = t * b[i] % m;
            ans.push_back(t);
        }
        for(int i = n - 1; i >= 0; i -- ) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}