#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
const int N = 1e5 + 5;
int a[N];
void solve(){
    int n;
    cin >> n;
    vector<bool> st(n + 1);
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
        st[a[i]] = 1;
    }
    int t = -1;
    for(int i = 0; i < n; i ++ ){
        if(!st[i]) {
            t = i;
            break;
        }
    }
    if(t == -1){
        cout << -1 << endl;
        return;
    }
    if(t == 0){
        cout << 2 << endl << "1 1" << endl;
        cout << 2 << " " << n << endl;
        return;
    }
    set<int> s;
    int cnt = 0;
    int pos = -1;
    for(int i = 0; i < n; i ++ ){
        if(a[i] < t){
            s.insert(a[i]);
            if(s.size() == t){
                cnt ++;
                if(cnt == 2){
                    break;
                }
                pos = i;
                s.clear();
            }
        }
    }
    if(cnt != 2){
        cout << -1 << endl;
        return;
    }
    cout << 2 << endl << 1 << " " << pos + 1 << endl << pos + 2 <<" "  <<  n << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        solve();
    }

    return 0;
}