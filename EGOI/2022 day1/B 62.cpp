#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll w, h;
ll f[800];
ll ans[800];
ll const mod=1e9+7;

ll mod_pw( ll x, ll y ){
    if( y==0 ) return 1LL;
    else if( y==1 ) return x;
    else{
        ll z=mod_pw( x, y/2 );
        z=z*z%mod;
        if( y&1 ) return z*x%mod;
        else return z;
    }
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> w >> h;
    assert( w<=700 );

    f[0]=1, f[1]=1;
    for( int i=2 ; i<=w ; i++ ){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    for( int i=1 ; i<=w ; i++ ){
        f[i]=mod_pw( f[i], h );
    }

    for( int i=1 ; i<=w ; i++ ){
        ans[i]=f[i];
        for( int j=1 ; j<i ; j++ ){
            ll x=ans[j]*f[i-j]%mod;
            ans[i]=( ans[i]-x+mod )%mod;
        }
    }

    cout << ans[w] << '\n';

    return 0;
}