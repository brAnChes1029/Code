#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c2, c5;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll l, r;
    cin >> l >> r;

    ll x2=1;
    for( int i=1 ;  ; i++ ){
        x2*=2;
        if( x2>=1e18 ) break;
        ll a=l/x2;
        ll b=r/x2;
        if( a==b && l%x2!=0 ) break;
        else c2=i;
    }

    ll x5=1;
    for( int i=1 ;  ; i++ ){
        x5*=5;
        if( x5>=1e18 ) break;
        ll a=l/x5;
        ll b=r/x5;
        if( a==b && l%x5!=0 ) break;
        else c5=i;
    }

    cout << min( c2, c5 ) << '\n';

    return 0;
}
