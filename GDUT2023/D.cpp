#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
int T;
long long x, y;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T -- ){
        int cnt = 0;
        cin >> x >> y;
        if(x == y){
            cout << 0 << endl;
            continue;
        }


        while(x % 6 == 0 && y % 6 == 0){
            x /= 6, y /= 6;
        }
        while(x % 5 == 0 && y % 5 == 0){
            x /= 5, y /= 5;
        }
        
        while(x % 6 == 0){
            x /= 6;
            cnt ++ ;
        }
        while(x < y){
            x *= 5;
            cnt ++ ;
        }
        if(x == y){
            cout << cnt << endl;
            continue;
        }
        cout << -1 << endl;

    }
    

    return 0;
}