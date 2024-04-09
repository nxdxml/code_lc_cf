#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ){
        a[i] = s[i] - '0';
    }         
    for(int i = n; i >= 1; i -- ){
        vector<int> b(n + 1);
        bool fg = 1;
        int t = 0;
        for(int j = 0; j < n; j ++ ){
            t ^= b[j];
            if(t == a[j]){
                if(j > n - i){
                    fg = 0;
                    break;
                }
                t ^= 1;
                b[j + i] ^= 1;
            }
        }
        if(fg){
            cout << i << endl;
            break;
        }
    }
   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    

    return 0;
}