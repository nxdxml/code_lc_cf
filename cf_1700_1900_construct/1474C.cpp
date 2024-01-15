#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
const int N = 1e3 + 5;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T -- ){
        int n;
        cin >> n;
        multiset<int> ss;
        for(int i = 0; i < 2 * n; i ++ ) {
            cin >> a[i];
            ss.insert(a[i]);
        }
        sort(a, a + 2 * n);
        
        // 5 1 3 2
        bool fg1 = 1;
        for(int i = 0; i < 2 * n - 1; i ++ ){
            int xx = a[i] + a[2 * n - 1];
            int x = xx;
            // cout << x << endl;
            multiset<int> s = ss;
            
            vector<int> ans;
            bool fg = 1;
            for(int j = 0; j < n; j ++ ){
                auto it1 = s.end();
                it1 --;
                int y = x - *it1;
                s.erase(it1);

                if(s.find(y) == s.end()) {
                    fg = 0;
                    break;
                }

                auto it2 = s.find(y);
                s.erase(it2);

                ans.push_back(x - y);
                ans.push_back(y);

                x = max(x - y, y);

            }
            if(fg){
                fg1 = 0;
                cout << "YES" << endl;
                cout << xx << endl;
                for(int j = 0; j < n; j ++ ){
                    cout << ans[j * 2] << " " << ans[j * 2 + 1] << endl;
                }
                break;
            }
        }
        if(fg1){
            cout << "NO" << endl;
        }


    }
    

    return 0;
}