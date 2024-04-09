/*
n个工作，每个工作有Deadline，需要连续C天完成，价值为W，求最大价值(n,d,c <= 5000)
难度6星

转化为背包问题
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> f(n, vector<int>(3));
    for(int i = 0; i < n; i ++ ){
        cin >> f[i][0] >> f[i][1] >> f[i][2];
    }
    sort(f.begin(), f.end(), [](const auto& t1, const auto& t2){
        return t1[0] < t2[0];
    });
    vector<LL> dp(5005, 0); // 第i天可以获得的工资的最大值
    for(int i = 0; i < n; i ++ ){
        int d = f[i][0];
        int c = f[i][1];
        int w = f[i][2];
        for(int j = d; j >= c; j -- ){
            if(j >= c) dp[j] = max(dp[j], dp[j - c] + w);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;


    return 0;
}