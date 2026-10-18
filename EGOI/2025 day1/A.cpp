#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
int idx1, idx2;
int a[500005];
int pos[500005];
bool mp[500005];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t >> n;
    for( int i=0 ; i<n ; i++ ) cin >> a[i], pos[a[i]]=-1e9;
    for( int i=0 ; i<n ; i++ ){
        if( mp[a[i]] ) break;
        mp[a[i]]=true;
        idx1=i;
    }
    memset( mp, 0, sizeof(mp) );
    for( int i=n-1 ; i>=0 ; i-- ){
        if( mp[a[i]] ) break;
        mp[a[i]]=true;
        idx2=i;
        pos[a[i]]=i;
    }

    int ans=n-idx2;
    int l=0, r=idx2-1;
    int mx=idx2-1;
    for( int i=0 ; i<=idx1 ; i++ ){
        mx=max( mx, pos[a[i]] );
        if( (i+1)+(n-mx-1)>ans ){
            ans=(i+1)+(n-mx-1);
            l=i+1;
            r=mx;
        }
    }

    cout << l << ' ' << r << '\n';

    return 0;
}