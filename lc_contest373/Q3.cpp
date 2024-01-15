#include<bits/stdc++.h>
#define endl '\n'
#define pair<int, int > PII
using namespace std;


const int N = 1e5 + 5;
struct node{
    int val;
    int idx;
}nodes[N];

vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i ++ ){
            nodes[i].val = nums[i];
            nodes[i].idx = i;
        }
        sort(nums.begin(), nums.end());
        sort(nodes, nodes + n, [](auto t1, auto t2){return t1.val < t2.val;});
        // for(int i = 0; i < n; i ++ ){
            // cout << nodes[i].val << " " << nodes[i].idx << endl;
        // }
        int i = 0, j = 0;
        for(; j < n; j ++ ){
            if(i == j || abs(nodes[j].val - nodes[j - 1].val) <= limit) continue;
            // deal (i, j - 1)
            
            sort(nodes + i, nodes + j, [](auto t1, auto t2){return t1.idx < t2.idx;});
        
            // cout << i << "  " << j - 1 << endl;
            // for(int t = i; t < j; t ++ ){
            //     cout << nodes[t].val << " " << nodes[t].idx << endl;
            // }

            for(int k = i; k <= j - 1; k ++ ) ans[nodes[k].idx] = nums[k];
            i = j;
        }
        // j == n
        sort(nodes + i, nodes + j, [](auto t1, auto t2){return t1.idx < t2.idx;});
        for(int k = i; k <= j - 1; k ++ ) ans[nodes[k].idx] = nums[k];

        // for(int i = 0; i < n; i ++ ){
        //     cout << nodes[i].val << " " << nodes[i].idx << endl;
        // }

        return ans;
        
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, limit;
    
    cin >> n >> limit;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i ++ ){
        cin >> nums[i];
    }
    auto ans = lexicographicallySmallestArray(nums, limit);
    for(int i = 0; i < n; i ++ ) cout << ans[i] << " ";
    puts("");

    return 0;
}