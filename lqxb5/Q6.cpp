#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll k[3];
ll sec;
ll cal(int x)
{
    if(x<3)
        return k[x];
    else if(x%2)
        return ((cal(x/2)*cal(x/2+1)-k[1])%MOD);
    else{
        ll sto=cal(x/2);
        return ((sto*sto-2)%MOD);
    }
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        scanf("%d%lld",&n,&k[1]);
        k[2]=(k[1]*k[1]-2)%MOD;
        printf("%lld\n",cal(n));
    }
}