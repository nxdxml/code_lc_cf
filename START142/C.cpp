#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long ll;
// const int N = 1e5 + 5;

void solve(){
	int x;
	cin >> x;
	int t = 1;
	while(t < x){
		t <<= 1;
	}
	if(t == x) cout << 0 << endl;
	else cout << x * 2 - t << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
	cin >> T;
	while(T -- ) solve();
    

    return 0;
}