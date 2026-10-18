#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q, t=1;
int cnt;
ll mst;
ll v[200005];
ll bit[200005];
ll ans[200005];
int p[200005];
int d[200005];
int tin[200005];
int tout[200005];
int anc[200005][20];
vector<int> a[200005];
vector< pair<int,int> > ask[200005];
vector< tuple<ll,int,int> > e;

void add( int i, ll k ){
    while( i<=n ){
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

int findroot( int i ){
    if( p[i]==i ) return i;
    return p[i]=findroot(p[i]);
}

void mer( int x, int y, ll z ){
    x=findroot(x);
    y=findroot(y);
    if( x!=y ){
        mst+=z;
        a[cnt].push_back(x);
        a[cnt].push_back(y);
        v[cnt]=z;
        p[x]=p[y]=cnt;
        cnt++;
    } 
}

void dfs( int i, int pa ){
    tin[i]=t++;
    anc[i][0]=pa;
    for( int j=1 ; j<20 ; j++ ) anc[i][j]=anc[anc[i][j-1]][j-1];
    for( int u : a[i] ){
        dfs( u, i );
    }
    tout[i]=t++;
}

bool is_anc( int i, int j ){
    if( tin[i]<=tin[j] && tout[i]>=tout[j] ) return true;
    return false;
}

int lca( int i, int j ){
    if( is_anc( j, i ) ) swap( i, j );
    if( is_anc( i, j ) ) return i;
    for( int k=19 ; k>=0 ; k-- ){
        if( !is_anc( anc[i][k], j ) ){
            i=anc[i][k];
        }
    }
    return anc[i][0];
}

int main(){

    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    cnt=n+1;
    for( int i=1 ; i<=2*n ; i++ ) p[i]=i;
    for( int i=0 ; i<m ; i++ ){
        int x, y; ll z;
        cin >> x >> y >> z;
        e.push_back({z, x+1, y+1});
    }
    sort( e.begin(), e.end() );
    for( int i=0 ; i<m ; i++ ){
        int x, y; ll z;
        tie( z, x, y )=e[i];
        mer( x, y, z );
    }

    tin[0]=0;
    dfs( cnt-1, 0 );
    tout[0]=t;

    for( int i=0 ; i<q ; i++ ){
        int l, r;
        cin >> l >> r;
        ask[r+1].push_back({l+1, i});
    }
    for( int i=1 ; i<=n ; i++ ){
        int x=cnt-1;
        while( x!=i ){
            int y=x;
            int nxt;
            if( d[x]!=0 ) y=lca( d[x], i );
            for( int u : a[y] ){
                if( is_anc( u, i ) ) nxt=u;
                else if( d[x]!=0 ){
                    d[u]=d[x];
                    add( d[x], -v[anc[x][0]]+v[y] );
                }
            }
            d[x]=i;
            x=nxt;
        }
        for( auto p : ask[i] ){
            ans[p.second]=mst-(sum( i )-sum( p.first-1 ));
        }
    }

    for( int i=0 ; i<q ; i++ ) cout << ans[i] << '\n';

    return 0;
}