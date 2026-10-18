#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q;
ll pre[100005];
ll suf[100005];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for( int i=1 ; i<=m ; i++ ){
        int x, y;
        ll z;
        cin >> x >> y >> z;
        pre[i]=z;
        suf[i]=z;
    }
    for( int i=1 ; i<=m ; i++ ) pre[i]+=pre[i-1];
    for( int i=m ; i>=1 ; i-- ) suf[i]+=suf[i+1];

    while( q-- ){
        int x, y;
        cin >> x >> y;
        cout << pre[x]+suf[y+1] << '\n';
    }

    return 0;
}