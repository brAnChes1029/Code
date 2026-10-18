#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
vector<int> a, b;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for( int i=0 ; i<n ; i++ ){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort( a.begin(), a.end(), greater<int>() );

    while( q-- ){
        int x, y;
        cin >> x >> y;
        for( int i=0 ; i<y ; i++ ) a[i]-=x;
        b=a;
        int ia=0, ib=y;
        for( int i=0 ; i<n ; i++ ){
            if( ia==y ) a[i]=b[ib], ib++;
            else if( ib==n ) a[i]=b[ia], ia++;
            else{
                if( b[ia]>b[ib] ){
                    a[i]=b[ia], ia++;
                }
                else{
                    a[i]=b[ib], ib++;
                }
            }
        }
    }

    for( int i=0 ; i<n ; i++ ) cout << a[i] << ' ';

    return 0;
}