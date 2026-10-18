#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
int a[20005][105];
int sum[20005];
int dp[2][10005];
bitset<105> b[2][10005];
pair<int,int> v[20005];

void knapsack( int i, int d ){
    for( int t=0 ; t<=m*k ; t++ ){
        b[0][t].reset();
        b[1][t].reset();
    }
    b[0][0][0]=1;
    int all=0;
    for( int j=1 ; j<=m ; j++ ){
        all+=a[i][j];
        for( int t=max( 0, all-d ) ; t<=all ; t++ ) b[j&1][t].reset();
        for( int t=max( 0, all-d ) ; t<=all ; t++ ){
            if( t>=a[i][j] ) b[j&1][t]=b[j&1^1][t-a[i][j]];
            b[j&1][t]|=(b[j&1^1][t]<<1);
        }
    }
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for( int i=1 ; i<=n ; i++ ){
        for( int j=1 ; j<=m ; j++ ){
            cin >> a[i][j];
            sum[i]+=a[i][j];
        }
        v[i]={ -sum[i], i };
    }
    sort( v+1, v+n+1 );
    for( int i=1 ; i<=n ; i++ ) v[i].first*=-1;
    sum[n+1]=m*k;
    v[0]={ m*k, n+1 };

    for( int i=1 ; i<=n ; i++ ){
        int p=v[i].second;
        knapsack( p, v[i].first-v[i+1].first );
        memset( dp[i&1], 0x3f, sizeof(dp[i&1]) );
        for( int j=v[i+1].first ; j<=v[i].first ; j++ ){
            for( int c=0 ; c<=(v[i-1].first-v[i+1].first)/k ; c++ ){
                int h=j+c*k;
                if( b[m&1][j][c] ){
                    if( v[i-1].second<v[i].second ){
                        dp[i&1][j]=min( dp[i&1][j], dp[i&1^1][h]+m-c );
                    }
                    else{
                        dp[i&1][j]=min( dp[i&1][j], dp[i&1^1][h+1]+m-c );
                    }
                }
            }
        }
        for( int j=v[i].first ; j>=v[i+2].first ; j-- ){
            dp[i&1][j]=min( dp[i&1][j], dp[i&1][j+1] );
        }
    }

    cout << dp[n&1][0] << '\n';

    return 0;
}