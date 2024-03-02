#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;

void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    stringstream ss;
    ss << s1[0];
    int cnt = 0;
    for(int i = 1; i < n; i ++ ){
        if(s1[i] == s2[i - 1]) {
            ss << s1[i];
            cnt ++ ;
        } else if(s1[i] == '0'){
            ss << s1[i];
            cnt = 0;
        } else {
            ss << s2.substr(i - 1, n - i);
            break;
        }
    }
    ss << s2[n - 1];
    cout << ss.str() << endl;
    cout << cnt + 1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}