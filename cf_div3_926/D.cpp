#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int, int > PII;
typedef long long LL;
// const int N = 2e5 + 5;
bool st[4][8];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    map<char, int> m;
    m['C'] = 0;
    m['D'] = 1;
    m['S'] = 2;
    m['H'] = 3;
    map<int, char> rm;
    rm[0] = 'C';
    rm[1] = 'D';
    rm[2] = 'S';
    rm[3] = 'H';
    while(T -- ){
        int n;
        cin >> n;
        n *= 2;
        char key;
        cin >> key;
        // cout << key << endl;
        int t = m[key];
        vector<int> cnt(4, 0);
        memset(st, 0, sizeof st);
        for(int i = 0; i < n; i ++ ){
            string s;
            cin >> s;
            // cout << s << " ";
            cnt[m[s[1]]] ++ ;
            st[m[s[1]]][s[0] - '2'] = 1;
        }
        int sum = 0;
        for(int i = 0; i < 4; i ++ ){
            if(i == t) continue;
            sum += (cnt[i] & 1);
        }
        if(sum > cnt[t]) cout << "IMPOSSIBLE" << endl;
        else {
            int p = 0;
            for(int i = 0; i < 4; i ++ ){
                if(i == t) continue;
                int d = 0;
                for(int j = 0; j < 8; j ++ ){
                    if(!st[i][j]) continue;
                    cout <<  char(j + '2') << rm[i] << " ";
                    d ++ ;
                    if(d % 2 == 0) cout << endl;
                }
                while(!st[t][p]){
                    p ++ ;
                }
                if(d & 1) {
                    cout  << char(p + '2')<< rm[t] << endl;
                    st[t][p] = 0; 
                }
                
            }
            int dd = 0;
            for(int j = 0; j < 8; j ++ ){
                if(!st[t][j]) continue; 
                cout  << char(j + '2')<< rm[t] << " ";
                dd ++;
                if(dd % 2 == 0) cout << endl;
            }
        }
    }
    

    return 0;
}