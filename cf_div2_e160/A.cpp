#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
// const int N = 1e5 + 5;
int T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;

    auto str2int = [&](string s){
        int t = 0;
        for(int i = 0; i < s.size(); i ++ ){
            t *= 10;
            t = t + s[i] - '0';
        }
        return t;
    };

    while(T -- ){
        string s;
        cin >> s;
        int n = s.size();
        bool fg = 0;
        for(int i = 1; i < n; i ++ ){
            string a = s.substr(0, i);
            string b = s.substr(i);
            // cout << a << "  " << b << endl;
            if(a[0] == '0' && a.size() > 1) continue;
            if(b[0] == '0' && b.size() > 1) continue;
            if(str2int(b) > str2int(a)){
                cout << a << " " << b << endl;
                // cout << str2int(a) << " " << str2int(b) << endl;
                fg = 1;
                break;
            }
        }
        if(!fg) cout << -1 << endl;
    }
    

    return 0;
}