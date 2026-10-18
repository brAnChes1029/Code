#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int s, t, n, m;
vector<int> v;
int a[2005], b[2005];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s >> t >> n >> m;
    for( int i=0 ; i<t*2 ; i++ ){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort( v.begin(), v.end() );
    for( int i=0 ; i<n ; i++ ) cin >> a[i];
    for( int j=0 ; j<m ; j++ ) cin >> b[j];

    bool f=false;
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<m ; j++ ){
            if( a[i]+s<=b[j] || b[j]+s<=a[i] ) continue;

            int x=abs(a[i]-b[j]);
            int y=( ((s-x)&1) ? 1 : 0 ); // 0.5;
            int z=(s-x)/2;
            if( a[i]<b[j] ) z+=x;
            int idx=lower_bound( v.begin(), v.end(), z )-v.begin();
            if( idx&1 ){
                if( z!=v[idx] ) f=true;
            }
            else{
                if( y ){
                    if( z==v[idx] ) f=true;
                }
            }

        }
    }

    cout << ( f ? "YES\n" : "NO\n" );

    return 0;
}