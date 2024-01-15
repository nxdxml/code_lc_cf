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
    while (T -- )
    {
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        int n = s.size();
        for(int i = 0; i < n; i ++ ){
            if(s[i] =='0') cnt0 ++;
            else cnt1 ++;
        }
        if(cnt0 == cnt1){
            cout << 0 << endl;
            continue;
        }
        int c0 = 0, c1 = 0;
        for(int i = 0; i < n; i ++ ){
            if(s[i] =='0') c0 ++;
            else c1 ++;
            if(c0 > cnt1 || c1 > cnt0){
                cout << n - i << endl;
                break;
            }
        }
        
    }
    
    

    return 0;
}