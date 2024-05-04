/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

void solve(){
	int n;
	cin >> n;
	int cnt = 0;

	for(int i = 0; i < n; i ++ ){
		int x;
		cin >> x;
		cnt += (x == 2);
	}
	if(cnt % 8 == 0) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
	cin >> T;
	while(T -- ) solve();

    return 0;
}