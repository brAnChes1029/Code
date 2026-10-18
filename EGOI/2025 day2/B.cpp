#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> a[200005];
vector<int> b[200005];
int dis[200005];
int ans[200005];
int ind[200005];
queue<int> q;
priority_queue< pair<int,int> > pq;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i=0 ; i<m ; i++ ){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        b[y].push_back(x);
        ind[x]++;
    }

    q.push(0);
    dis[0]=1;
    while( !q.empty() ){
        int i=q.front();
        q.pop();
        for( int u : a[i] ){
            if( dis[u]==0 ){
                dis[u]=dis[i]+1;
                q.push(u);
            }
        }
    }
    for( int i=0 ; i<n ; i++ ){
        dis[i]--;
        ans[i]=1e9;
    }

    for( int u : b[n-1] ){
        ans[u]=max( 1, dis[u] );
        ind[u]--;
        pq.push({ -ans[u], u });
    }
    while( !pq.empty() ){
        int w, i;
        tie(w, i)=pq.top();
        pq.pop();
        if( -w!=ans[i] ) continue;
        for( int u : b[i] ){
            if( ans[u]==1e9 && dis[u]>=ans[i]+1 ){
                ans[u]=dis[u];
                pq.push({ -ans[u], u });
            }
            if( ans[i]+1>dis[u] && ans[i]+1<ans[u] ){
                ans[u]=ans[i]+1;
                pq.push({ -ans[u], u });
            }
        }
    }

    for( int i=0 ; i<n-1 ; i++ ) cout << ans[i] << ' ';

    return 0;
}