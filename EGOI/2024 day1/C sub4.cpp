#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int ans;
int c[2005];
int dep[2005];
int cnt2[2005];
int cnt3[2005];
int cnt[2005][2005];
vector<int> a[2005];

void dfs( int i ){
    cnt[c[i]][dep[i]]++;
    for( int u : a[i] ){
        dep[u]=dep[i]+1;
        dfs( u );
    }
}

void dfs2( int i, int co ){
    cnt2[dep[i]]++;
    if( c[i]==co ) cnt3[dep[i]]++;
    for( int u : a[i] ){
        dfs2( u, co );
    }
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

    dep[0]=0;
    dfs( 0 );

    pair<int,int> ans={0, 1e9};
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ) cnt2[j]=cnt3[j]=0;
        dfs2( i, c[i] );
        pair<int,int> cal={0, 0};
        for( int j=dep[i]+1 ; j<n ; j++ ){
            cal.first+=min( cnt2[j], cnt[c[i]][j] );
            cal.second+=cnt3[j];
        }
        cal.second=-(cal.first-cal.second);
        cal.first++;
        ans=max( ans, cal );
    }

    cout << ans.first << ' ' << -ans.second << '\n'; 

    return 0;
}