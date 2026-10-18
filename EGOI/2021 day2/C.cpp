#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int t[300005];
int st[300005];
ll dis[300005];
vector<int> h;
vector< pair<int,ll> > a[300005];
priority_queue< pair<ll,int> > pq;

bool check( ll x ){
    memset( st, 0, sizeof(st) ); // 1:bad 2:wall 3:able to reach
    queue<int> q;

    for( int i=1 ; i<=n ; i++ ){
        if( t[i]==-1 ){
            st[i]=1;
            q.push(i);
        }
    }
    while( !q.empty() ){
        int i=q.front();
        q.pop();
        for( auto p : a[i] ){
            if( !st[p.first] && t[p.first]==0 && dis[p.first]>x ){
                st[p.first]=1;
                q.push(p.first);
            }
        }
    }

    for( int i=1 ; i<=n ; i++ ){
        if( t[i]==0 && dis[i]<=x ){
            for( auto p : a[i] ){
                if( st[p.first]==1 ){
                    st[i]=2;
                    break;
                }
            }
        }
    }

    q.push(h[0]);
    st[h[0]]=3;
    while( !q.empty() ){
        int i=q.front();
        q.pop();
        for( auto p : a[i] ){
            if( st[p.first]==1 ) return false;
            if( !st[p.first] ){
                st[p.first]=3;
                q.push(p.first);
            }
        }
    }

    for( int u : h ){
        if( st[u]!=3 ) return false;
    }
    return true;
}

int main(){

    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i=1 ; i<=n ; i++ ){
        cin >> t[i];
        if( t[i]==1 ) h.push_back(i);
    }
    for( int i=0 ; i<m ; i++ ){
        int x, y;
        ll z;
        cin >> x >> y >> z;
        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }

    for( int i=1 ; i<=n ; i++ ) dis[i]=1e17;
    for( int u : h ){
        dis[u]=0;
        pq.push({ 0, u });
    }
    while( !pq.empty() ){
        int i;
        ll w;
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

    ll l=0, r=1e15, mid, ans=-1;
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
        cout << -1 << '\n';
        return 0;
    }
    check(ans);
    vector<int> v;
    for( int i=1 ; i<=n ; i++ ){
        if( st[i]==2 ) v.push_back(i);
    }
    cout << v.size() << '\n';
    for( int u : v ) cout << u << ' ';

    return 0;
}