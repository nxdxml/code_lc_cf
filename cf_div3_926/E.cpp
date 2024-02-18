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
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = s + "0";
        int sum = 0;
        for(int i = 0; i < n; i ++ ){
            sum += int(s[i] - '0');
        }
        string p = to_string(sum);
        int m = p.size();
        int t = 0;
        int j = n;
        for(int i = m - 1; i >= 0; i --, j -- ){
            int x = (s[j] - '0');
            int y = (p[i] - '0');
            if(x - y - t < 0){
                s[j] = char(x - y - t + 10 + '0');
                t = 1;
            } else {
                s[j] = char(x - y - t + '0');
                t = 0;
            }
        }
        while(t){
            if(s[j] == '0'){
                s[j] = '9';
                j --;
            }else {
                s[j] = s[j] - 1;
                break;
            }
        }


        t = 0;
        for(int i = 0; i <= n; i ++ ){
            int x = s[i] - '0';
            int y = x + t * 10;
            s[i] = char(y / 9 + '0');
            t = y % 9;
        }
        bool fg = 0;
        for(int i = 0; i <= n; i ++ ){
            if(s[i] != '0') fg = 1;
            if(fg) cout << s[i];
        }
        cout << endl;

        // (10s - sum) / 9;
    }
    

    return 0;
}