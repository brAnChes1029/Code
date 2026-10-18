#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int ans;
int c[100005];
int cnt[100005];
vector<int> a[100005];

void dfs( int i ){
    for( int u : a[i] ){
        dfs( u );
    }
    cnt[c[i]]++;
    ans=max( ans, cnt[c[i]] );
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for( int i=0 ; i<n ; i++ ) cin >> c[i];
    for( int i=1 ; i<n ; i++ ){
        int x;
        cin >> x;
        a[x].push_back(i);
    }

    dfs( 0 );

    cout << ans << ' ' << 0;

    return 0;
}