#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

// const int N = 1e5 + 5;
// bool st[N];

int minimumAddedCoins(vector<int>& f, int target) {
    sort(f.begin(), f.end());
    bitset<100001> S;
    S[0] = 1;
    for(int i = 0; i < f.size(); i ++ ){
        int x = f[i];
        int a = S.count();
        S |= S << x;
        if(a == S.count())break;        
    }

    int ans = 0;
    for(int i = 1; i <= target; i ++ ){
        if(S[i] == 0){
            // cout << i << endl;
            S |= S << i;
            i = i * 2 - 1;
            ans ++;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target;
    cin >> n >> target;
    vector<int> coins(n, 0);
    for(int i = 0; i < n; i ++ ) cin >> coins[i];

    cout << minimumAddedCoins(coins, target) << endl;

    return 0;
}