#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, string> m;
    // int cnt = 0;
    for(int i = 3; i <= 78; i ++ ){
        // cnt ++;
        string t;
        if(i <= 28) {
            t = "aaa";
            t[2] = t[2] + i - 3;
        }
        else if (i <= 53) {
            t = "aaz";
            t[1] = t[1] + i - 3 - 25;
        }
        else {
            t = "azz";
            t[0] = t[0] + i - 3 - 50;
        }
        // cout << i << " " << t << endl;
        m[i] = t;
    }
    int T;
    cin >> T;
    while (T -- )
    {
        int n;
        cin >> n;
        cout << m[n] << endl;
    }
    
    

    return 0;
}