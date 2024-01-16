#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T -- )
    {
        int x1, x2, x3, x4;
        int y1, y2, y3, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        int len1, len2;
        if(x1 == x2) len1 = abs(y1 - y2), len2 = abs(y3 - y4);
        if(x1 == x3) len1 = abs(y1 - y3), len2 = abs(y2 - y4);
        if(x1 == x4) len1 = abs(y1 - y4), len2 = abs(y2 - y3);

        cout << len1 * len2 << endl;
    }
    
    

    return 0;
}