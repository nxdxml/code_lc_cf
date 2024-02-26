#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
const int N = 2e5 + 5;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    int S = (1 << 31) - 1;
    while(T -- ){
        int n;
        cin >> n;
        unordered_map<int, int> m;
        int ans = 0;
        for(int i = 0; i < n; i ++ ) cin >> a[i];
        sort(a, a + n);
        int k = 0;
        for(int i = 0; i < n; i ++ ){
            if(a[i] >= S / 2){
                k = i;
                break;
            }
        }
        for(int i = 0; i < n; i ++ ){
            int x = a[i];
            // a[i] < S / 2
            if(i < k) m[x] ++;
            else {
                if(m.count(S - x) && m[S - x]){
                    m[S - x] --;
                    ans ++;
                } 
                // else {
                    // m[x] ++;
                // }
            }
        }
        cout << n - ans << endl;
    }

    return 0;
}