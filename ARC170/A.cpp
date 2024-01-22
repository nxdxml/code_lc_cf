#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 1e5 + 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s, p;
    cin >> s >> p;

    int sa = n;
    for(int i = 0; i < n; i ++ ){
        if(s[i] == 'A'){
            sa = i;
            break;
        }
    }
    int pa = n;
    for(int i = 0; i < n; i ++ ){
        if(p[i] == 'A'){
            pa = i;
            break;
        }
    }

    if(sa < pa){
        cout << -1 << endl;
        return 0;
    }


    int sb = -1;
    for(int i = n - 1; i >= 0; i -- ){
        if(s[i] == 'B'){
            sb = i;
            break;
        }
    }
    int pb = -1;
    for(int i = n - 1; i >= 0; i --){
        if(p[i] == 'B'){
            pb = i;
            break;
        }
    }

    if(sb > pb){
        cout << -1 << endl;
        return 0;
    }
    
    int ans = 0;
    int t = 0;
    for(int i = 0; i < n; i ++ ){
        if(s[i] != p[i]){
            if(p[i] == 'A') t ++ , ans ++ ;
            else {
                if(t) t --;
                else ans ++ ;
            }
        }
    }
    cout << ans << endl;

    return 0;
}