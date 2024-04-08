#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int t = 0;
    for(int i = 0; i < n; i ++ ){
        t *= 10;
        if(s[i] == '0') t += 1;
    
    }
    if(t == 0){
        if(s[n - 1] == '1') cout << 2 << endl;
        else cout << 1 << endl;
        return ;
    }
    cout << t << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();
    

    return 0;
}