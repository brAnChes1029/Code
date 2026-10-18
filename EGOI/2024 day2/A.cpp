#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q;
vector<int> v;
map<int,int> mp;

int dis( int x, int y ){
    if( x>y ) swap( x, y );
    return min( y-x, 2*n-(y-x) );
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for( int i=0 ; i<m ; i++ ){
        int x;
        cin >> x;
        v.push_back(x);
        mp[x]=x+n;
        mp[x+n]=x;
    }
    for( int i=0 ; i<m ; i++ ){
        v.push_back(v[i]+n);
    }

    while( q-- ){
        int x, y;
        cin >> x >> y;
        int ans=dis( x, y );
        auto l=lower_bound( v.begin(), v.end(), x );
        if( l==v.begin() ) l=v.end();
        l--;
        ans=min( ans, dis( x, *l )+1+dis( mp[*l], y ) );

        auto r=lower_bound( v.begin(), v.end(), x );
        if( r==v.end() ) r=v.begin();
        if( r!=v.end() ) ans=min( ans, dis( x, *r )+1+dis( mp[*r], y )  );

        cout << ans << '\n';
    }

    return 0;
}