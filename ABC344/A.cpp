#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    stringstream ss;
    int n = s.size();
    int cnt = 0;
    for(int i = 0; i < n; i ++ ){
        if(s[i] == '|'){
            cnt ++;
            continue;
        }
        if(cnt == 1) continue;
        ss << s[i];
    }
    cout << ss.str() << endl;
    return 0;
}