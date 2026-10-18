#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
ll a[55];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while( t-- ){
        cin >> n;
        for( int i=0 ; i<=n ; i++ ) a[i]=0;
        for( int i=0 ; i<n ; i++ ) cin >> a[i];
        ll ans=0;
        a[n]--;
        for( int i=n ; i>=0 ; i-- ){
            if( a[i]<0 ){
                ans-=a[i];
                for( int j=i-1 ; j>=0 ; j-- ){
                    a[j]+=a[i];
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}