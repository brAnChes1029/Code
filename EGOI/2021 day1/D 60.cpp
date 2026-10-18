#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int h[305];
int p[305];
int c[305];
int a[305];
int b[305];
int mn[305][305];
int mx[305][305];
int dp[305][305];

int main(){

    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for( int i=1 ; i<=n ; i++ ) cin >> h[i];
    for( int i=1 ; i<=n ; i++ ){
        for( int j=1 ; j<=n ; j++ ){
            mn[i][j]=1e9;
            mx[i][j]=0;
            for( int x=min(i, j) ; x<=max(i, j) ; x++ ){
                mn[i][j]=min( mn[i][j], h[x] );
                mx[i][j]=max( mx[i][j], h[x] );
            }
        }
    }

    for( int i=1 ; i<=k ; i++ ) cin >> p[i] >> c[i] >> a[i] >> b[i];
    for( int x=1 ; x<=k ; x++ ){
        if( a[x]>h[p[x]] || b[x]<h[p[x]] ){
            cout << "-1\n";
            continue;
        }

        for( int i=1 ; i<=n ; i++ ){
            for( int j=1 ; j<=n ; j++ ) dp[i][j]=1e9;
        }
        dp[a[x]][b[x]]=c[x];

        for( int i=a[x] ; i>=1 ; i-- ){
            for( int j=b[x] ; j<=n ; j++ ){
                for( int y=1 ; y<=k ; y++ ){
                    if( mn[p[x]][p[y]]>=i && mx[p[x]][p[y]]<=j ){
                        if( ( b[y]>=i && a[y]<=i ) || ( b[y]>=j && a[y]<=j ) ){
                            dp[min(i, a[y])][max(j, b[y])]=min( dp[min(i, a[y])][max(j, b[y])], dp[i][j]+c[y] );
                        }
                    }
                }
            }
        }

        if( dp[1][n]<1e9 ){
            cout << dp[1][n] << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }

    return 0;
}