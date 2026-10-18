#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool q, r, b, n, k, p;
set< pair<ll,ll> > move_n={ {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
set< pair<ll,ll> > move_p={ {1, 0} };
set< pair<ll,ll> > move_k={ {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

ll go_b( ll x, ll y, bool f ){
    if( !f ) return 1e17;
    if( (abs(x)+abs(y))&1 ) return 1e17;
    if( x+y==0 || x-y==0 ) return 1;
    else return 2;
}

ll go_n( ll x, ll y, bool f ){
    if( !f ) return 1e17;
    x=abs(x), y=abs(y);
    if( x<y ) swap(x, y);
    if( x==1 && y==0 ) return 3;
    if( x==2 && y==2 ) return 4;
    if( x==1 && y==1 ) return 2;
    ll dis=max((x+1)/2, (x+y+2)/3);
    if( dis%2!=(x+y)%2 ) dis++;
    return dis;
}

ll go_k( ll x, ll y, bool f ){
    if( !f ) return 1e17;
    return max(abs(x), abs(y));
}

ll go_p( ll x, ll y, bool f ){
    if( !f ) return 1e17;
    if( y!=0 || x<0 ) return 1e17;
    return x;
}

int main(){

    int t;
    cin >> t;
    while( t-- ){
        ll x0, y0, x, y;
        string s;
        cin >> s >> x0 >> y0 >> x >> y;
        x-=x0, y-=y0;
        q=p=r=b=n=k=false;
        for( auto u : s ){
            q|=(u=='Q'), r|=(u=='R'), b|=(u=='B'), k|=(u=='K'), n|=(u=='N'), p|=(u=='P');
        }

        if( (x==0 || y==0) && (r || q) ) cout << "1\n";
        else if( (x+y==0 || x-y==0) && (b || q) ) cout << "1\n";
        else if( (n&&move_n.count({x, y})) || (p&&move_p.count({x, y})) || (k&&move_k.count({x, y})) ) cout << "1\n";
        else if( q || r ) cout << "2\n";
        else{
            ll ans=min({ go_b(x, y, b), go_p(x, y, p), go_k(x, y, k), go_n(x, y, n) });
            if( p ) for( auto [x0, y0] : move_p ) ans=min({ ans, go_b(x-x0, y-y0, b)+1, go_k(x-x0, y-y0, k)+1, go_n(x-x0, y-y0, n)+1 });
            if( k ) for( auto [x0, y0] : move_k ) ans=min({ ans, go_b(x-x0, y-y0, b)+1, go_p(x-x0, y-y0, p)+1, go_n(x-x0, y-y0, n)+1 });
            if( n ) for( auto [x0, y0] : move_n ) ans=min({ ans, go_b(x-x0, y-y0, b)+1, go_k(x-x0, y-y0, k)+1, go_p(x-x0, y-y0, p)+1 });
            cout << ( ans>=1e17 ? -1 : ans ) << '\n';
        }
    }

    return 0;
}