#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int t[15];
ll ans=1e17;
ll dis[15];
bool vis[15];
vector<int> h;
vector<int> v;
vector< pair<int,ll> > a[15];
priority_queue< pair<ll,int> > pq;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i=1 ; i<=n ; i++ ){
        cin >> t[i];
        if( t[i]==1 ) h.push_back(i);
    }
    for( int i=0 ; i<m ; i++ ){
        int x, y;
        ll z;
        cin >> x >> y >> z;
        a[x].push_back({ y, z });
        a[y].push_back({ x, z });
    }

    for( int i=1 ; i<=n ; i++ ) dis[i]=1e17;
    for( int u : h ){
        dis[u]=0;
        pq.push({ 0, u });
    }
    while( !pq.empty() ){
        ll w;
        int i;
        tie( w, i )=pq.top();
        pq.pop();
        if( -w!=dis[i] ) continue;
        for( auto p : a[i] ){
            if( dis[p.first]>dis[i]+p.second ){
                dis[p.first]=dis[i]+p.second;
                pq.push({ -dis[p.first], p.first });
            }
        }
    }

    for( int s=0 ; s<(1<<n) ; s++ ){
        bool f=true;
        ll mx=0;
        for( int i=0 ; i<n ; i++ ){
            if( s&(1<<i) ){
                if( t[i+1]!=0 ) f=false;
                else mx=max( mx, dis[i+1] );
            }
        }
        if( !f ) continue;
        if( mx<ans ){
            for( int i=1 ; i<=n ; i++ ) vis[i]=false;
            queue<int> q;
            q.push(h[0]);
            vis[h[0]]=true;
            while( !q.empty() ){
                int i=q.front();
                q.pop();
                if( s&(1<<(i-1)) ) continue;
                for( auto p : a[i] ){
                    if( vis[p.first] ) continue;
                    vis[p.first]=true;
                    q.push(p.first);
                }
            }
            for( int i=1 ; i<=n ; i++ ){
                if( t[i]==1 && !vis[i] ) f=false;
                if( t[i]==-1 && vis[i] ) f=false;
            }
            if( !f ) continue;
            ans=mx;
            v.clear();
            for( int i=1 ; i<=n ; i++ ){
                if( s&(1<<(i-1)) ) v.push_back(i);
            }
        }
    }

    if( ans==1e17 ){
        cout << "-1\n";
        return 0;
    }
    cout << v.size() << '\n';
    for( int u : v ) cout << u << ' ';

    return 0;
}