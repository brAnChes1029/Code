#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;
vector<int> a[1005];
bool vis[1005];

void A(){
    cin >> n;
    for( int i=0 ; i<n-1 ; i++ ){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int st;
    for( int i=0 ; i<n ; i++ ){
        if( a[i].size()!=1 ){
            st=i;
            break;
        }
    }
    if( st==0 ) cout << "0\n";
    else cout << "1\n";
    for( int i=0 ; i<n ; i++ ){
        if( i!=st ) cout << i << '\n';
    }
}

void B(){
    cin >> n >> s;
    int x, y, st;
    cin >> x >> y;
    if( y==0 ) swap( x, y );
    if( s=="0" ) st=0;
    else st=y;
    cout << ( x==st ? y : x ) << endl;
    for( int i=2 ; i<n ; i++ ){
        cin >> x >> y;
        cout << ( x==st ? y : x ) << endl;
    }
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int p;
    cin >> p;
    if( p==1 ) A();
    else B();

    return 0;
}