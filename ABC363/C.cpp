/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

bool is_hw(string s){
    int n = s.size();
    for(int i = 0; i < n / 2; i ++ ){
        if(s[i] != s[n - 1 - i]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    sort(s.begin(), s.end());
    do{
        bool fg = 1;
        for(int i = 0; i < n - k + 1; i ++ ){
            if(is_hw(s.substr(i, k))) {
                fg = 0;
                break;
            }
        }
        if(fg) ans ++ ;
    } while(next_permutation(s.begin(), s.end()));
    

    cout << ans << endl;

    return 0;
}