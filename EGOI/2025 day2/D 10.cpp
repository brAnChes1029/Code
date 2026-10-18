#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s="";
vector<int> a[1005];
int dep[1005];
int pa[1005];
int vis[1005];

void dfs( int i, int p, bool b ){
    for( int u : a[i] ){
        if( u==p ) continue;
        dfs( u, i, b );
    }
    if( p==-1 ) return;
    if( i<p ) s+="0";
    else s+="1";
    if( b ) cout << i << '\n';
}

void A(){
    cin >> n;
    for( int i=0 ; i<n-1 ; i++ ){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs( 0, -1, 0 );
    cout << s << '\n';
    dfs( 0, -1, 1 );
}

void B(){
    cin >> n >> s;
    for( int i=0 ; i<n-1 ; i++ ){
        int x, y, ch;
        cin >> x >> y;
        if( x>y ) swap(x, y);
        if( s[i]=='0' ) cout << x << endl;
        else cout << y << endl;
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