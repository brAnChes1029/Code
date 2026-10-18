#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int last=-1;
int light[105][105];

int query( int i, int j, int f ){
    cout << "?" << endl;
    for( int x=0 ; x<n ; x++ ){
        for( int y=0 ; y<n ; y++ ){
            if( f==0 ) cout << ( (x==i && y<=j) ? 1 : 0 );
            else if( f==1 ) cout << ( x==i ? 1 : 0 );
            else if( f==2 ){
                if( x!=i ) cout << 0;
                else if( y==j || y>=2 ) cout << 1;
                else cout << 0;
            }
            else if( f==3 ){
                if( x==i-1 && y==last ) cout << 1;
                else if( x==i && y==j ) cout << 1;
                else cout << 0;
            }
        }
        cout << endl;
    }
    int re;
    cin >> re;
    return re;
}

void ans( bool f, int x ){
    cout << "!" << endl;
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            if( f ) cout << ( i==x ? 1 : 0);
            else cout << light[i][j];
        }
        cout << endl;
    }
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    
    for( int i=0 ; i<n ; i++ ){
        if( query( i, 0, 1 )==n*n ){
            ans( 1, i );
            return 0;
        }
        int l=0, r=n, mid, li;
        while( l<r ){
            mid=(l+r)/2;
            if( mid==0 ){
                if( last!=-1 ){
                    if( query( i, 0, 3 )==2*n ) li=0;
                    else li=1;
                }
                else{
                    if( query( i, 0, 2 )<=query( i, 1, 2) ) li=0;
                    else li=1;
                }
                break;
            }
            if( query( i, mid, 0 )==n*(mid+1) ){
                l=mid+1;
            }
            else{
                li=mid;
                r=mid;
            }
        }
        last=li;
        light[i][li]=1;
    }
    
    ans( 0, 0 );

    return 0;
}