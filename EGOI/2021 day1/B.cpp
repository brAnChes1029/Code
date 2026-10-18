#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[1000005];
ll l[500005];
ll r[500005];
ll bit[1000005];
ll ans;

void add( int i, ll k ){
    while( i<=n*2 ){
        bit[i]+=k;
        i+=(i&(-i));
    }
}

ll sum( int i ){
    ll re=0;
    while( i>0 ){
        re+=bit[i];
        i-=(i&(-i));
    }
    return re;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i=1 ; i<=n*2 ; i++ ){
        int x;
        cin >> x;
        if( !l[x] ) l[x]=i;
        else r[x]=i;
        a[i]=x;
    }

    for( int i=1 ; i<=n*2 ; i++ ){
        int x=a[i];
        if( l[x]==i ) continue;
        else{
            ans+=(r[x]-l[x])-(sum(r[x])-sum(l[x]));
            add( l[x], 1 );
            add( r[x], 1 );
        }
    }
    cout << ans << '\n';

    return 0;
}