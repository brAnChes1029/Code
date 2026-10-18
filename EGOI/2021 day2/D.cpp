#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int p[50];
int sz[50];
int edge[50];
ll pre[50];
ll ans[50];
multiset<ll> tree;
unordered_map<ll,ll> mp[50];

int findroot( int i ){
    if( p[i]==i ) return i;
    return p[i]=findroot(p[i]);
}
void mer( int x, int y ){
    x=findroot(x); y=findroot(y);
    if( x!=y ){
        p[y]=x; sz[x]+=sz[y]; edge[x]+=edge[y]+1;
    }
    else edge[x]++;
}

ll ha( multiset<ll> &st ){ // multiset hash
    ll re=0;
    for( ll u : st ) re=( re*1029 + u )%1029000029;
    return re;
}

ll dfs( ll i, multiset<ll> t, ll j ){
    if( i>n+1 || t.empty() ) return 0;
    ll h=ha(t);
    if( mp[j][h] ) return mp[j][h];

    ll re=0;
    multiset<ll> t2=t;
    ll mul=(1LL<<(j+n+1-i)), s=1, last_sz=0;
    for( ll u : t ) s*=u;
    for( auto it=t.begin() ; it!=t.end() ; it++ ){
        ll u=*it;
        if( u==last_sz ) continue;

        t2.erase(t2.find(u)); // tree + edge
        s/=u;
        re=max( re, s*mul*2 - dfs( i+1, t2, j+1 ) );

        if( j ) re=max( re, s*mul - dfs( i+1, t2, j ) ); // tree + jelly

        t2.insert(u); // tree + tree
        s*=u;
        ll last2=0;
        for( auto it2=next(it) ; it2!=t.end() ; it2++ ){
            ll v=*it2;
            if( v==last2 ) continue;
            t2.erase(t2.find(u)); s/=u;
            t2.erase(t2.find(v)); s/=v;
            t2.insert(u+v); s*=(u+v);
            re=max( re, s*mul - dfs( i+1, t2, j ) );
            t2.insert(u); s*=u;
            t2.insert(v); s*=v;
            t2.erase(t2.find(u+v)); s/=(u+v);
            last2=v;
        }

        last_sz=u;
    }

    mp[j][h]=re;
    return re;
}

int main(){

    cin >> n >> k;
    for( int i=1 ; i<=n ; i++ ) p[i]=i, sz[i]=1;
    pre[0]=(1LL<<(n+1));
    for( int i=1 ; i<=k ; i++ ){
        int x, y;
        cin >> x >> y;
        mer( x, y );
        pre[i]=(1LL<<(n+1-i));
        for( int j=1 ; j<=n ; j++ ){
            if( p[j]==j ){
                if( edge[j]==sz[j]-1 ) pre[i]*=sz[j];
                else if( edge[j]==sz[j] ) pre[i]*=2;
                else pre[i]=0;
            }
        }
        ans[i&1]+=pre[i-1]-pre[i];
    }
    if( !pre[k] ){
        cout << ans[0] << ' ' << (1LL<<(n+1))-ans[0];
        return 0;
    }

    ll jelly=0;
    for( int i=1 ; i<=n ; i++ ){
        if( p[i]==i ){
            if( edge[i]==sz[i]-1 ) tree.insert(sz[i]);
            else jelly++;
        }
    }
    ans[k&1]+=dfs( k+1, tree, jelly );
    if( k&1 ){
        cout << (1LL<<(n+1))-ans[1] << ' ' << ans[1];
    }
    else{
        cout << ans[0] << ' ' << (1LL<<(n+1))-ans[0];
    }

    return 0;
}