#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int ans;
int l[200005];
int r[200005];
int dp[200005];
int zkw[400005];
set< pair<int,int> > st;

void modify( int x, int y ){
    x+=(n-1);
    zkw[x]=y;
    for( int i=(x>>1) ; i>0 ; (i>>=1) ){
        zkw[i]=max( zkw[i<<1], zkw[i<<1|1] );
    }
}

int query( int l, int r ){
    int re=0;
    for( (l+=n-1), (r+=n-1) ; l<r ; (l>>=1), (r>>=1) ){
        if( l&1 ) re=max( re, zkw[l++] );
        if( r&1 ) re=max( re, zkw[--r] );
    }
    return re;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i=1 ; i<=n ; i++ ){
        cin >> l[i] >> r[i];
    }

    for( int i=1 ; i<=n ; i++ ){
        dp[i]=1;
        for( auto it=st.begin() ; it!=st.end() ; ){
            pair<int,int> p=*it;
            if( p.first<i ){
                modify( p.second, dp[p.second] );
                it=st.erase(it);
            }
            else break;
        }
        if( i-l[i]>1 ) dp[i]=max( dp[i], query( 1, i-l[i] )+1 );
        ans=max( ans, dp[i] );
        st.insert({ i+r[i], i });
    }
    cout << ans << '\n';

    return 0;
}