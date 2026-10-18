#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q, t;
vector<int> a[200005];
int pos[2005];
int tin[200005];
int tout[200005];
int nxt[200005][20];
ll ans[2005];

void dfs( int i, int p ){
    tin[i]=++t;
    nxt[i][0]=p;
    for( int j=1 ; j<20 ; j++ ){
        nxt[i][j]=nxt[nxt[i][j-1]][j-1];
    }
    for( int u : a[i] ){
        if( u==p ) continue;
        dfs( u, i );
    }
    tout[i]=++t;
}

bool is_anc( int i, int j ){
    if( tin[i]<=tin[j] && tout[i]>=tout[j] ) return true;
    return false;
}

int lca( int x, int y ){
    if( is_anc( y, x ) ) swap( x, y );
    if( is_anc( x, y ) ){
        int re=0;
        for( int j=19 ; j>=0 ; j-- ){
            if( is_anc( x, nxt[y][j] ) ){
                re+=(1<<j);
                y=nxt[y][j];
            }
        }
        return re;
    }
    else{
        int re=0;
        for( int j=19 ; j>=0 ; j-- ){
            if( !is_anc( nxt[y][j], x ) ){
                re+=(1<<j);
                y=nxt[y][j];
            }
        }
        re++;
        y=nxt[y][0]; // LCA
        for( int j=19 ; j>=0 ; j-- ){
            if( is_anc( y, nxt[x][j] ) ){
                re+=(1<<j);
                x=nxt[x][j];
            }
        }
        return re;
    }
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for( int i=1 ; i<=m ; i++ ) cin >> pos[i];
    for( int i=1 ; i<n ; i++ ){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    tin[0]=0;
    dfs( 1, 0 );
    tout[0]=++t;

    /*
    for( int i=1 ; i<=n ; i++ ){
        cout << i << ' ';
        cout << nxt[i][0] << ' ' << nxt[i][1] << ' ' << nxt[i][2] << '\n';
    }
    */

    while( q-- ){
        char c;
        cin >> c;
        if( c=='q' ){
            int x;
            cin >> x;
            cout << ans[x] << '\n';
        }
        else if( c=='e' ){
            ll x, y;
            cin >> x >> y;
            for( int i=1 ; i<=m ; i++ ){
                if( pos[i]==x ) ans[i]+=y;
            }
        }
        else{
            int l, r, x;
            cin >> l >> r >> x;
            for( int i=l ; i<=r ; i++ ){
                int u=pos[i];
                ans[i]-=lca( u, x );
                pos[i]=x;
            }
        }
    }

    return 0;
}