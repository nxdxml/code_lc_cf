#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

int maxSubarrayLength(vector<int>& a, int k) {
    int n = a.size();
    int ans = 0;
    map<int, int> hashMap;
    for(auto x : a){
        hashMap[x] = 0;
    }
    int i = 0, j;
    for(int j = 0; j < n; j ++ ){
        hashMap[a[j]] ++;
        while(hashMap[a[j]] > k){
            hashMap[a[i++]] --;
        }
        ans = max(ans, j - i + 1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    cout << maxSubarrayLength(a, k) << endl;

    return 0;
}