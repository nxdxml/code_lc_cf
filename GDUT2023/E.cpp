#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int ans = 0;
    int sum = 0;
    map<int, int > hashMap;
    hashMap[0] = 0;
    for(int i = 1; i <= n; i ++ ){
        int t;
        cin >> t;
        if(t == 0) t = -1;
        sum += t;
        if(hashMap.count(sum)) ans = max(ans, i - hashMap[sum]);
        else hashMap[sum] = i;
    }
    cout << ans << endl;
    

    return 0;
}