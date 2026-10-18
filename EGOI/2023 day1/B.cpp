#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int node=1;
int idx[600005];
int who[600005];
int cnt[600005];
int dis[600005];
int t[600005];
vector<int> a[600005];

set< pair<int,int> > st;

void dfs( int i ){
    if( who[i]==1e9 ){
        cnt[st.begin()->second]++;
        return;
    }
    for( int u : a[i] ){
        auto it=st.lower_bound({ -dis[who[i]], who[i] });
        dis[who[i]]+=t[i]-t[u];
        st.insert({ -dis[who[i]], who[i] });
        if( it!=st.end() ) st.erase( it );
        dfs( u );
        auto it2=st.lower_bound({ -dis[who[i]], who[i] });
        dis[who[i]]-=t[i]-t[u];
        st.insert({ -dis[who[i]], who[i] });
        st.erase( it2 );
    }
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i=1 ; i<=m ; i++ ){
        int x, y;
        cin >> x >> y;
        int m=node++; // medal
        who[m]=1e9;

        int xi, yi;
        if( idx[x]==0 ) xi=node++, who[xi]=x, idx[x]=xi;
        else xi=idx[x];
        if( idx[y]==0 ) yi=node++, who[yi]=y, idx[y]=yi;
        else yi=idx[y];
        a[xi].push_back(m);
        a[xi].push_back(yi);
        t[m]=t[yi]=i;
        idx[y]=0;
    }

    for( int i=1 ; i<node ; i++ ){
        if( t[i]==0 ){
            t[i]=m+1;
            st.clear();
            dfs( i );
        }
    }

    for( int i=0 ; i<n ; i++ ){
        cout << cnt[i] << ' ';
    }

    return 0;
}