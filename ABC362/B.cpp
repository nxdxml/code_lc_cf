/*

*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using PII = pair<int, int >;
using LL = long long;
// const int N = 2e5 + 5;
int p[3][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 3; i ++ ){
        cin >> p[i][0] >> p[i][1];
    }

    auto get_dist = [&](int i, int j){
        int dx = p[i][0] - p[j][0];
        int dy = p[i][1] - p[j][1];
        return dx * dx + dy * dy;
    };

    int a = get_dist(0, 1);
    int b = get_dist(0, 2);
    int c = get_dist(1, 2);
    
    if((a == b + c) || (b == a + c) || (c == a + b)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}