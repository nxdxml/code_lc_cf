#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;

int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
    int ans = 0;
    for(int i = 0; i < k; i ++ ){
        // 使用第i+1台
        // 二分最多能造多少份
        
        auto check = [&](int x) -> bool {
            long long sum = 0;
            long long t = 0;
            for(int j = 0; j < n; j ++ ){
                sum += (long long)cost[j] * (max((long long)x * composition[i][j] - stock[j], t));
                if(sum > budget) return false;
            }  
            return true;
        };
        
        int l = 0, r = 2e8;
        while(l < r){
            int mid = l + r + 1 >> 1;
            // r = mid
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, l);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
        

    return 0;
}