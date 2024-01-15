#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
const int N = 2e5 + 5;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        int n;
        cin >> n;
        vector<int> ans;
        for(int i = 0; i < n; i ++ ){
            cin >> a[i];
        }
        int cnt = 1;
        ans.push_back(1);
        int color = 1;
        bool fg = 1;
        int pos = -1;
        for(int i = 1; i < n; i ++ ){
            if(a[i] == a[i - 1]) ans.push_back(color), pos = i;
            else color ^= 3, ans.push_back(color), cnt = 2;
        }
        if(a[0] != a[n - 1] && color == 1){
            if(pos == -1){
                cnt = 3;
                ans[n - 1] = 3;
            } else {
                for(int i = pos; i < n; i ++ ){
                    ans[i] ^= 3;
                }
            }
            
        }
        cout << cnt << endl;
        for(auto x : ans) cout << x << " ";
        cout << endl;
    }
    

    return 0;
}