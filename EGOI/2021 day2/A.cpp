#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll q;
ll a[100005];
ll dp[100005];
ll ans;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    q=100-q;
    for( int i=1 ; i<=n ; i++ ){
        cin >> a[i];
    }
    sort( a+1, a+n+1, greater<ll>() );

    for( int i=1 ; i<=n ; i++ ){
        dp[i]=dp[i-1]+a[i]/100*q;
        if( i>=3 ) dp[i]=min( dp[i], dp[i-3]+a[i-2]+a[i-1] );
    }

    cout << dp[n] << '\n';

    return 0;
}