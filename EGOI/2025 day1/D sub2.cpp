#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q;
int p[2005];
int rk[2005];
vector< tuple<ll,int,int> > v;

int findroot( int i ){
    if( p[i]==i ) return i;
    return p[i]=findroot( p[i] );
}

ll mer( int i, int j, ll z ){
    i=findroot(i);
    j=findroot(j);
    if( i!=j ){
        if( rk[i]<rk[j] ) swap( i, j );
        p[j]=i;
        rk[i]+=rk[j];
        return z;
    }
    else return 0;
}

ll mst( int l, int r ){
    ll cost=0;
    for( int i=0 ; i<n ; i++ ){
        p[i]=i;
        rk[i]=1;
    }
    for( int i=l+1 ; i<=r ; i++ ){
        cost+=mer( l, i, 0 );
    }
    for( int c=0 ; c<m ; c++ ){
        ll z;
        int i, j;
        tie( z, i, j )=v[c];
        cost+=mer( i, j, z );
    }
    return cost;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for( int i=1 ; i<=m ; i++ ){
        int x, y;
        ll z;
        cin >> x >> y >> z;
        v.push_back({ z, x, y });
    }
    sort( v.begin(), v.end() );

    while( q-- ){
        int l, r;
        cin >> l >> r;
        cout << mst( l, r ) << '\n';
    }

    return 0;
}