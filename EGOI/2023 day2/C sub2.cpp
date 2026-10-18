#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
int x, y, p, q;

bool ok( int a, int b, int c, int d ){
    if( x==a && y==b ) return false;
    if( x==c && y==d ) return false;
    if( p==a && q==b ) return false;
    if( p==c && q==d ) return false;
    return true;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    cin >> x >> y >> p >> q;

    if( n==2 ){
        cout << "NO\n";
    }
    else if( n==3 ){
        if( ok( 2, 1, 1, 0 ) ) cout << "2 1\n1 0\n";
        else if( ok( 1, 2, 2, 0 ) ) cout << "1 2\n2 0\n";
        else if( ok( 1, 0, 2, 0 ) ) cout << "1 0\n2 0\n";
        else if( ok( 2, 0, 0, 1 ) ) cout << "2 0\n0 1\n";
        else if( ok( 0, 2, 2, 1 ) ) cout << "0 2\n2 1\n";
        else if( ok( 0, 1, 2, 1 ) ) cout << "0 1\n2 1\n";
        else if( ok( 1, 0, 0, 2 ) ) cout << "1 0\n0 2\n";
        else if( ok( 0, 1, 1, 2 ) ) cout << "0 1\n1 2\n";
        else if( ok( 0, 2, 1, 2 ) ) cout << "0 2\n1 2\n";
        else cout << "NO\n";
    }
    else{
        for( int i=1 ; i<n ; i++ ){
            if( (x==i && y==0) || (p==i && q==0) ){
                for( int j=1 ; j<n ; j++ ){
                    if( j==i ) continue;
                    if( !(x==i && y==j) && !(p==i && q==j) && !(x==j && y==0) && !(p==j && q==0)  ){
                        cout << i << ' ' << j << '\n';
                        break;
                    }
                }
            }
            else{
                cout << i << ' ' << 0 << '\n';
            }
        }
    }

    return 0;
}