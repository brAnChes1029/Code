#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll w, h;
ll f[5005];
ll ans[5005];
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

void sol1(){
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
}

ll c[105][105];
ll dp[250005][105];

void sol2(){
    c[0][0]=1;
    for( int i=1 ; i<105 ; i++ ){
        for( int j=0 ; j<=i ; j++ ){
            c[i][j]=( c[i-1][j-1]+c[i-1][j] )%mod;
        }
    }

    for( int j=1 ; j<h ; j++ ) dp[1][j]=c[h][j];
    for( int i=2 ; i<w ; i++ ){
        for( int j=1 ; j<h ; j++ ){
            for( int k=1 ; k<h ; k++ ){
                if( h-k<j ) continue;
                dp[i][j]=( dp[i][j]+dp[i-1][k]*c[h-k][j]%mod )%mod;
            }
            //cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }
    ll re=0;
    for( int j=1 ; j<h ; j++ ){
        re=( re+dp[w-1][j] )%mod;
    }
    if( w==2 ) re++;
    cout << re << '\n';
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> w >> h;

    if( w<5000 ) sol1();
    else sol2();

    return 0;
}