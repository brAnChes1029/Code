#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, f;
ll t;
ll a[105];
ll dp[105][105][5000];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> f >> t;
    for( int i=1 ; i<=n ; i++ ) cin >> a[i];

    for( int i=1 ; i<=n ; i++ ){
        for( int j=1 ; j<=min( i, f ) ; j++ ){
            for( int k=0 ; k<=(i*(i-1)/2) ; k++ ){
                dp[i][j][k]=dp[i-1][j][k];
                if( k-(i-j)>=0 ) dp[i][j][k]=max( dp[i][j][k], dp[i-1][j-1][k-(i-j)]+a[i] );
            }
        }
    }

    int ans=1e9;
    for( int k=0 ; k<=(n*(n-1)/2) ; k++ ){
        if( dp[n][f][k]>=t ){
            ans=min( ans, k );
        }
    }
    if( ans==1e9 ) cout << "NO\n";
    else cout << ans;

    return 0;
}