#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, h;
int t[300005];
ll dis[300005];
bool vis[300005];
vector< pair<int,ll> > a[300005];
priority_queue< pair<ll,int> > pq;

bool check( ll x ){
    for( int i=1 ; i<=n ; i++ ) vis[i]=false;
    vis[h]=true;
    queue<int> q;
    q.push(h);
    while( !q.empty() ){
        int i=q.front();
        q.pop();
        if( t[i]==0 && dis[i]<=x ) continue;
        for( auto p : a[i] ){
            if( vis[p.first] ) continue;
            vis[p.first]=true;
            q.push(p.first);
        }
    }
    for( int i=1 ; i<=n ; i++ ){
        if( t[i]==-1 && vis[i] ) return false;
    }
    return true;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i=1 ; i<=n ; i++ ){
        cin >> t[i];
        if( t[i]==1 ) h=i;
    }
    for( int i=0 ; i<m ; i++ ){
        int x, y;
        ll z;
        cin >> x >> y >> z;
        a[x].push_back({ y, z });
        a[y].push_back({ x, z });
    }

    for( int i=1 ; i<=n ; i++ ) dis[i]=1e17;
    dis[h]=0;
    pq.push({ 0, h });
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

    ll l=0, r=1e9+7, mid, ans=-1;
    while( l<r ){
        mid=(l+r)/2;
        if( check(mid) ){
            ans=mid;
            r=mid;
        }
        else{
            l=mid+1;
        }
    }

    if( ans==-1 ){
        cout << "-1\n";
        return 0;
    }
    vector<int> v;
    for( int i=1 ; i<=n ; i++ ){
        if( dis[i]<=ans && t[i]==0 ) v.push_back(i);
    }
    cout << v.size() << '\n';
    for( int u : v ) cout << u << ' ';

    return 0;
}