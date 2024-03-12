#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;
char g[20][20];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < 5; i ++ ) {
        string s;
        getline(cin, s);
        // cout << s << endl;
        for(int j = 0; j < 10; j ++ ){
            g[i][j] = s[j];
        }
    }
    if(g[2][4] == '>'){
        int a = g[1][0] - '0';
        int b = g[3][0] - '0';
        cout << (a | b) << endl;
        return 0;
    }
    if(g[2][1] == '*'){
        int a = g[2][0] - '0';
        cout << !a << endl;
        return 0;
    }
    // cout << "#";
    int a = g[1][0] - '0';
    int b = g[3][0] - '0';
    // cout << a << " " << g[3][0] << endl;
    cout << (a & b) << endl;
    

    return 0;
}