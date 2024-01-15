#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
const int N = 1e5 + 5;
int f[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    string s1 = "kira";
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0, j = 0; i < n; i ++ ){
        if(s[i] == s1[j]){
            j = (j + 1) % 4;
            if(j == 0){
                cnt ++ ;
            }
        }
        f[i] = cnt;
    }

    string s2 = "ikod";

    cnt = 0;
    int ans = 0;
    for(int i = n - 1, j = 0; i > 0; i -- ){
        if(s[i] == s2[j]){
            j = (j + 1) % 4;
            if(j == 0){
                cnt ++ ;
            }
        }
        if(cnt < 1 || f[i - 1] < 1) continue;
        ans = max(ans, cnt + f[i - 1]);
    }
    cout << ans * 4 << endl;

    return 0;
}