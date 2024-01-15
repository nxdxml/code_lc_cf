#include<bits/stdc++.h>
#define endl '\n'
#define pair<int, int > PII
using namespace std;

bool areSimilar(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i < n; i ++ ){
        if(i & 1){
            for(int j = 0; j < m; j ++ ){
                int t = (j + k) % m;
                if(mat[i][t] != mat[i][j]) return false;

            }
        } else {
            for(int j = 0; j < m; j ++ ){
                int t = ((j - k) % m + m) % m;
                if(mat[i][t] != mat[i][j]) return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m , 0));
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            cin >> mat[i][j];
        }
    }

    cout << areSimilar(mat, k) << endl;
    

    return 0;
}
