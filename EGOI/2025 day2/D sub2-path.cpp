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
        if( a[i].size()==1 ){
            st=i;
            break;
        }
    }
    if( st>a[st][0] ) cout << "0\n";
    else cout << "1\n";
    for( int i=0 ; i<n ; i++ ){
        cout << st << '\n';
        vis[st]=true;
        st=( vis[a[st][0]] ? a[st][1] : a[st][0] );
    }
}

void B(){
    cin >> n >> s;
    int x, y, st;
    cin >> x >> y;
    if( x>y ) swap( x, y );
    if( s=="0" ) st=y;
    else st=x;
    for( int i=1 ; i<n ; i++ ){
        cout << st << endl;
        if( st==x ) st=y;
        else st=x;
        if( i!=n-1 ) cin >> x >> y;
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