#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, w;
int b[505][505], c[505][505];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> w;
    for( int i=1 ; i<n ; i++ ){
        for( int j=0 ; j<i ; j++ ){
            cin >> c[i][j];
        }
    }
    for( int i=1 ; i<n ; i++ ){
        for( int j=0 ; j<i ; j++ ){
            cin >> b[i][j];
        }
    }

    if( c[1][0]+b[1][0]<w ){
        cout << "NO\n";
    }
    else{
        cout << 2*(n-1) << '\n';
        for( int i=0 ; i<n-1 ; i++ ) cout << i << ' ' << i+1 << ' ' << b[1][0] << '\n';
        for( int i=0 ; i<n-1 ; i++ ) cout << i << ' ' << i+1 << ' ' << w-c[1][0] << '\n';
    }

    return 0;
}