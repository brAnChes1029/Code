#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
int x, y;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    cin >> x >> y;

    if( n==2 ){
        cout << y << ' ' << x << '\n';
    }
    else{
        for( int i=1 ; i<n ; i++ ){
            if( x==i && y==0 ){
                cout << 0 << ' ' << i << '\n';
            }
            else{
                cout << i << ' ' << 0 << '\n';
            }
        }
    }

    return 0;
}