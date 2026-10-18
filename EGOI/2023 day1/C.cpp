#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int x, y;
string s;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    s="";
    for( int j=0 ; j<m-1 ; j++ ) s+='>';
    for( int i=0 ; i<n-1 ; i++ ) s+='v';
    cout << "? " << s << endl;
    cin >> x >> y;
    if( y==m-1 ){
        if( x!=n-1 ){
            cout << "! " << x+1 << ' ' << m-1 << '\n';
            return 0;
        }
    }
    else if( y!=m-1 ){
        cout << "! " << 0 << ' ' << y+1 << '\n';
        return 0;
    }

    s="";
    for( int j=0 ; j<m-2 ; j++ ) s+='>';
    for( int j=0 ; j<m-1 ; j++ ){
        for( int i=0 ; i<n ; i++ ) s+='v';
        s+='>';
        s+='v';
        s+='<';
        for( int i=0 ; i<n ; i++ ) s+='^';
        s+='<';
    }
    for( int i=0 ; i<n ; i++ ) s+='v';
    cout << "? " << s << endl;

    cin >> x >> y;
    cout << "! " << x+1 << ' ' << y << '\n';

    return 0;
}