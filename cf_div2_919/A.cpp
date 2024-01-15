#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    

    int T;
    cin >> T;
    while(T -- ){
        int n;
        cin >> n;
        int mine = 1;
        int maxe = 1e9;
        unordered_set<int> s;
        for(int i = 0; i < n; i ++ ){
            int op, x;
            cin >> op >> x;
            
            if(op == 1) {
                mine = max(mine, x);
            } else if(op == 2){
                maxe = min(maxe, x);
            } else {
                s.insert(x);
            }
        }
        // bool fg = 1;
        int cnt = maxe - mine + 1;
        
        for(auto x : s){
            if(x >= mine && x <= maxe) cnt --;
        }
        
        cout << max(0, cnt) << endl;

    }
    

    return 0;
}