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
    while(T -- ){
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++ ) cin >> a[i];
        int ans = 0;
        sort(a, a + n);
        int i = 0, j = 0, t = 0;
        for( ; i < n; i ++ ){
            if(i && a[i] == a[i - 1]) {
                t ++;
                continue;
            }
            if(a[i] - a[j] >= n){
                ans = max(ans, i - j - t);
                while(a[i] - a[j] >= n) {
                    j ++;
                    if(a[j] == a[j - 1]) t--;
                }
            }
        }
        ans = max(ans, i - j - t);
        cout << ans << endl;
    }
    

    return 0;
}