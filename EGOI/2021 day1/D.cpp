#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int h[2005], p[2005], a[2005], b[2005], c[2005];
int la[2005], lb[2005], ra[2005], rb[2005];
ll dp[2005][2005];
vector<int> as, bs;
priority_queue< pair<ll,int> > pqi[2005], pqj[2005];

ll cal( priority_queue< pair<ll,int> > &pq, int l, int r, int aa, int bb ){
    while( !pq.empty() ){
        int i=pq.top().second;
        if( a[i]>bb || b[i]<aa || p[i]<l || p[i]>r ){
            pq.pop();
        }
        else{
            return -pq.top().first;
        }
    }
    return 1e15;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for( int i=1 ; i<=n ; i++ ) cin >> h[i];
    for( int i=1 ; i<=k ; i++ ){
        cin >> p[i] >> c[i] >> a[i] >> b[i];
        as.push_back(i);
        bs.push_back(i);
    }
    sort( as.begin(), as.end(), [&]( int x, int y ){ return a[x]<a[y]; } );
    sort( bs.begin(), bs.end(), [&]( int x, int y ){ return b[x]>b[y]; } );

    for( int i=1 ; i<=k ; i++ ){
        la[i]=p[i]+1;
        while( la[i]>1 && h[la[i]-1]>=a[i] ) la[i]--;
        ra[i]=p[i]-1;
        while( ra[i]<n && h[ra[i]+1]>=a[i] ) ra[i]++;
        lb[i]=p[i]+1;
        while( lb[i]>1 && h[lb[i]-1]<=b[i] ) lb[i]--;
        rb[i]=p[i]-1;
        while( rb[i]<n && h[rb[i]+1]<=b[i] ) rb[i]++;
    }

    for( int i : as ){
        for( int j : bs ){
            dp[i][j]=1e15;
            int l=max( la[i], lb[j] );
            int r=min( ra[i], rb[j] );
            if( p[i]>r || p[i]<l || p[j]>r || p[j]<l ) continue;
            if( a[j]<a[i] && b[j]<b[i] ) continue;
            
            if( l==1 && r==n ) dp[i][j]=0;
            else if( b[j]<b[i] ) dp[i][j]=dp[i][i];
            else if( a[j]<a[i] ) dp[i][j]=dp[j][j];
            else{
                dp[i][j]=min({ dp[i][j], cal( pqi[i], l, r, a[i], b[j] ), cal( pqj[j], l, r, a[i], b[j] ) });
            }
            pqi[i].push({ -(dp[i][j]+c[j]) ,j });
            pqj[j].push({ -(dp[i][j]+c[i]), i });
        }
    }

    for( int i=1 ; i<=k ; i++ ){
        if( dp[i][i]>=1e15 ) cout << -1 << '\n';
        else cout << dp[i][i]+c[i] << '\n'; 
    }

    return 0;
}