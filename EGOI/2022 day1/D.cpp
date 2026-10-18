#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q, t;
vector<int> a[200005];
int pos[200005];
int tin[200005];
int tout[200005];
int nxt[200005][20];
ll e[200005];

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

//--- segtree ---

struct node{
    int l, r;
    int ls, rs;
    int city;
    ll v;
};
node st[400005];
int cnt=1;

void build( int l, int r, int idx ){
    st[idx].l=l;
    st[idx].r=r;
    st[idx].v=0;
    if( l+1==r ){
        st[idx].city=pos[l];
        return;
    }
    else{
        int mid=(l+r)/2;
        int ls=st[idx].ls=cnt++;
        int rs=st[idx].rs=cnt++;
        build( l, mid, ls );
        build( mid, r, rs );
        if( st[ls].city==st[rs].city ) st[idx].city=st[ls].city;
        else st[idx].city=-1;
    }
}

void push( int idx, int ls, int rs ){
    if( ls==-1 ) return;
    if( st[idx].city!=-1 ) st[ls].city=st[rs].city=st[idx].city;
    st[ls].v+=st[idx].v;
    st[rs].v+=st[idx].v;
    st[idx].v=0;
}

void modify( int ml, int mr, int idx, int l, int r, int x ){
    int ls=st[idx].ls;
    int rs=st[idx].rs;
    if( l+1==r ) ls=rs=-1;
    push( idx, ls, rs );

    if( mr<=l || ml>=r ) return;
    else if( ml<=l && r<=mr && st[idx].city!=-1 ){
        st[idx].v+=( e[st[idx].city]-e[x] - lca( st[idx].city, x ) );
        st[idx].city=x;
        return;
    }
    else{
        int mid=(l+r)/2;
        modify( ml, mr, ls, l, mid, x );
        modify( ml, mr, rs, mid, r, x );
        if( st[ls].city==st[rs].city ) st[idx].city=st[ls].city;
        else st[idx].city=-1;
    }
}

ll now_c;
ll query( int l, int r, int idx, int x ){
    if( st[idx].city!=-1 && now_c==-1 ) now_c=st[idx].city;
    if( l+1==r ){
        return st[idx].v;
    }
    else{
        int mid=(l+r)/2;
        int ls=st[idx].ls;
        int rs=st[idx].rs;
        if( x<mid ) return st[idx].v+query( l, mid, ls, x );
        else return st[idx].v+query( mid, r, rs, x );
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

    build( 1, m+1, 0 );
    /*
    for( int i=0 ; i<cnt ; i++ ){
        cout << i << ' ' << st[i].l << ' ' << st[i].r << ' ' << st[i].ls << ' ' << st[i].rs << ' ' << st[i].city << '\n';
    }
    */

    while( q-- ){
        char c;
        cin >> c;
        if( c=='q' ){
            int x;
            cin >> x;
            now_c=-1;
            ll ans=query( 1, m+1, 0, x );
            cout << ans+e[now_c] << '\n';
        }
        else if( c=='e' ){
            ll x, y;
            cin >> x >> y;
            e[x]+=y;
        }
        else{
            int l, r, x;
            cin >> l >> r >> x;
            modify( l, r+1, 0, 1, m+1, x );
        }
    }

    return 0;
}