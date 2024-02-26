#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ){
        string s;
        cin >> s;
        int cnt = 0;
        for(int i = 0; i < s.size(); i ++ ){
            cnt += s[i] == 'A';
        }
        if(cnt >= 3) cout << 'A' << endl;
        else cout << 'B' << endl;
    }

    return 0;
}