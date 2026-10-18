#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
ll mx;
ll a[100005];
ll up[100005];
bool vis[100005];

void cal( ll t ){
    for( int i=0 ; i<n ; i++ ){
        up[t]+=(a[i]/t);
    }
    vis[t]=true;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for( int i=0 ; i<n ; i++ ){
        cin >> a[i];
        mx=max( mx, a[i] );
    }

    while( q-- ){
        ll k;
        cin >> k;
        ll t=mx/k;
        if( mx%k!=0 ) t++;
        if( !vis[t] ) cal(t);
        if( up[t]>=k ) cout << "YES\n";
        else cout << "NO\n"; 
    }

    return 0;
}