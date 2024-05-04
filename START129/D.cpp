#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int cnt0 = 0;
    int cnt1 = 0;
    for(int i = 0; i < n; i ++ ){
        cnt0 += s[i] == '0';
        cnt1 += s[i] == '1';
    }
    if(n == 1) {
        cout << "Bob\n";
        return ;
    }
    if((n % 2 && abs(cnt0 - cnt1) != 1) || cnt0 == cnt1) cout << "Bob\n";
    else cout << "Alice\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T -- ) solve();

    return 0;
}