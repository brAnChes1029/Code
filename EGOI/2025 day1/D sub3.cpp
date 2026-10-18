#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q;
int t=1;
int p[100005];
int rk[100005];
int tin[100005];
int tout[100005];
int nxt[100005][20];
ll mx[100005][20];
vector< pair<int,ll> > a[100005];
vector< tuple<ll,int,int> > v;

int findroot( int i ){
    if( p[i]==i ) return i;
    return p[i]=findroot( p[i] );
}

void dfs( int i, int p, ll c ){
    tin[i]=t++;
    nxt[i][0]=p;
    mx[i][0]=c;
    for( int j=1 ; j<=17 ; j++ ){
        nxt[i][j]=nxt[nxt[i][j-1]][j-1];
        mx[i][j]=max( mx[i][j-1], mx[nxt[i][j-1]][j-1] );
    }
    for( auto u : a[i] ){
        if( u.first==p ) continue;
        dfs( u.first, i, u.second );
    }
    tout[i]=t++;
}

bool is_anc( int i, int j ){
    if( tin[i]<=tin[j] && tout[j]<=tout[i] ) return true;
    return false;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for( int i=1 ; i<=m ; i++ ){
        int x, y;
        ll z;
        cin >> x >> y >> z;
        x++, y++;
        v.push_back({ z, x, y });
    }
    sort( v.begin(), v.end() );

    ll cost=0;
    for( int i=1 ; i<=n ; i++ ){
        p[i]=i;
        rk[i]=1;
    }
    for( int c=0 ; c<m ; c++ ){
        ll z;
        int i, j;
        tie( z, i, j )=v[c];
        int pi=findroot(i);
        int pj=findroot(j);
        if( pi!=pj ){
            if( rk[pi]<rk[pj] ) swap( pi, pj );
            p[pj]=pi;
            rk[pi]+=rk[pj];
            cost+=z;
            a[i].push_back({j, z});
            a[j].push_back({i, z});
        }
    }

    tin[0]=0;
    dfs( 1, 0, 0 );
    tout[0]=t;

    while( q-- ){
        int x, y;
        cin >> x >> y;
        x++, y++;
        if( is_anc( y, x ) ) swap( x, y );
        if( is_anc( x, y ) ){
            ll ans=0;
            for( int j=17 ; j>=0 ; j-- ){
                if( is_anc( x, nxt[y][j] ) ){
                    ans=max( ans, mx[y][j] );
                    y=nxt[y][j];
                }
            }
            cout << cost-ans << '\n';
        }
        else{
            ll ans=0;
            int lca=x;
            for( int j=17 ; j>=0 ; j-- ){
                if( !is_anc( nxt[lca][j], y ) ){
                    ans=max( ans, mx[lca][j] );
                    lca=nxt[lca][j];
                }
            }
            ans=max( ans, mx[lca][0] );
            lca=nxt[lca][0];
            for( int j=17 ; j>=0 ; j-- ){
                if( is_anc( lca, nxt[y][j] ) ){
                    ans=max( ans, mx[y][j] );
                    y=nxt[y][j];
                }
            }
            cout << cost-ans << '\n';
        }
    }

    return 0;
}