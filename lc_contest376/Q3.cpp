// 找中位数前后最近的回文数。
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
// const int N = 1e5 + 5;

long long minimumCost(vector<int>& a) {
    int n = a.size();
    auto check = [&](int x) -> bool {
        int t = 0;
        int sx = x;
        while(x){
            t *= 10;
            t += x % 10;
            x /= 10;
        }
        return t == sx;
    };
    sort(a.begin(), a.end());
    int x = a[n >> 1];
    while(!check(x)) x ++;
    int y = x - 1;
    while(!check(y)) y --;
    long long ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i ++ ){
        ans1 += abs(a[i] - x);
        ans2 += abs(a[i] - y); 
    }
    return min(ans1, ans2);

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    cout << minimumCost(a) << endl;

    return 0;
}