#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int ans;
int l[3005];
int r[3005];
bool vis[3005];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i=1 ; i<=n*2 ; i++ ){
        int x;
        cin >> x;
        if( l[x]==0 ) l[x]=i;
        else r[x]=i;
    }

    for( int s=0 ; s<n ; s++ ){
        int mn=1e9, x;
        for( int i=1 ; i<=n ; i++ ){
            if( vis[i] ) continue;
            if( r[i]-l[i]-1<mn ){
                mn=r[i]-l[i]-1;
                x=i;
            }
        }
        vis[x]=true;
        ans+=mn+1;
        for( int i=1 ; i<=n ; i++ ){
            if( vis[i] ) continue;
            if( l[x]<l[i] && l[i]<r[x] ) l[i]--;
            else if( l[i]>r[x] ) l[i]-=2;
            if( l[x]<r[i] && r[i]<r[x] ) r[i]--;
            else if( r[i]>r[x] ) r[i]-=2;
        }
    }

    cout << ans << '\n';

    return 0;
}