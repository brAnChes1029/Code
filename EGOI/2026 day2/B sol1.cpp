#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
ll mx;
ll a[100005];
ll pre[200005];
ll ans[100005];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for( int i=0 ; i<n ; i++ ){
        cin >> a[i];
        mx=max( mx, a[i] );
        ans[1]+=a[i];
        pre[a[i]]++;
    }
    for( int i=1 ; i<200005 ; i++ ) pre[i]+=pre[i-1];

    for( int i=2 ; i<=mx ; i++ ){
        for( int j=1 ; i*j<=mx ; j++ ){
            ans[i]+=j*(pre[i*j+i-1]-pre[i*j-1]);
        }
    }

    while( q-- ){
        ll x;
        cin >> x;
        ll d=(mx/x)+(mx%x!=0);
        if( ans[d]>=x ) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}