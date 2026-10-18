#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, w;
int a[505][505];
int b[505][505];
int c[505][505];
int mn[505][505];
int mx[505][505];
vector< tuple<int,int,int> > v[2];
vector< tuple<int,int,int> > e;
int p[505];
int r[505];

int findroot( int i ){
    if( p[i]==i ) return i;
    return p[i]=findroot(p[i]);
}

void MST( int k ){
    for( int i=0 ; i<n ; i++ ){
        p[i]=i;
        r[i]=1;
    }
    for( int i=0 ; i<v[k].size() ; i++ ){
        int z, x, y;
        tie( z, x, y )=v[k][i];
        int xr=findroot(x);
        int yr=findroot(y);
        if( xr!=yr ){
            if( r[yr]>r[xr] ) swap( xr, yr );
            r[xr]+=r[yr];
            p[yr]=xr;
            e.push_back({ x, y, abs(z) });
            //cout << x << ' ' << y << ' ' << z << '\n';
        }
    }
}

int main(){

    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> w;
    for( int i=1 ; i<n ; i++ ){
        for( int j=0 ; j<i ; j++ ){
            cin >> c[i][j];
            a[i][j]=w-c[i][j];
        }
    }
    for( int i=1 ; i<n ; i++ ){
        for( int j=0 ; j<i ; j++ ){
            cin >> b[i][j];
            if( b[i][j]>=a[i][j] ){
                v[0].push_back({ a[i][j], i, j });
                v[1].push_back({ -b[i][j], i, j });
            }
        }
    }
    sort( v[0].begin(), v[0].end() );
    sort( v[1].begin(), v[1].end() );
    
    MST( 0 );
    MST( 1 );

    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            mn[i][j]=2e9;
            mx[i][j]=0;
        }
        mn[i][i]=0;
        mx[i][i]=2e9;
    }
    for( auto u : e ){
        int x, y, z;
        tie( x, y, z )=u;
        mn[x][y]=mn[y][x]=min( mn[x][y], z );
        mx[x][y]=mx[y][x]=max( mx[x][y], z );
    }
    for( int k=0 ; k<n ; k++ ){
        for( int i=0 ; i<n ; i++ ){
            for( int j=0 ; j<n ; j++ ){
                mn[i][j]=min( mn[i][j], max( mn[i][k], mn[k][j] ) );
                mx[i][j]=max( mx[i][j], min( mx[i][k], mx[k][j] ) );
            }
        }
    }

    for( int i=1 ; i<n ; i++ ){
        for( int j=0 ; j<i ; j++ ){
            if( mn[i][j]!=a[i][j] || mx[i][j]!=b[i][j] ){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << e.size() << '\n';
    for( auto u : e ){
        int x, y, z;
        tie( x, y, z )=u;
        cout << x << ' ' << y << ' ' << z <<'\n';
    }

    return 0;
}