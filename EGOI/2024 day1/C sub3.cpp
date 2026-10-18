#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, t;
int ans;
int c[100005];
int dep[100005];
int tin[100005];
int tout[100005];
vector<int> v[100005];
vector<int> a[100005];
vector< pair<int,int> > d[100005];
map<int,int> mp;

void dfs( int i ){
    tin[i]=t++;
    d[dep[i]].push_back({ tin[i], i });
    for( int u : a[i] ){
        dep[u]=dep[i]+1;
        dfs( u );
    }
    tout[i]=t++;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for( int i=0 ; i<n ; i++ ){
        cin >> c[i];
        v[c[i]].push_back(i);
    }
    for( int i=1 ; i<n ; i++ ){
        int x;
        cin >> x;
        a[x].push_back(i);
    }

    t=1;
    dep[0]=0;
    dfs( 0 );

    pair<int,int> ans={0,0};
    for( int i=0 ; i<n ; i++ ){
        int cnt=1;
        int sw=0;
        mp.clear();
        for( int u : v[c[i]] ){
            if( dep[u]<=dep[i] ) continue;
            if( tin[i]<=tin[u] && tout[u]<=tout[i] ){
                if( !mp[dep[u]] ){
                    int l=lower_bound( d[dep[u]].begin(), d[dep[u]].end(), make_pair(tin[i], 0) )-d[dep[u]].begin();
                    int r=lower_bound( d[dep[u]].begin(), d[dep[u]].end(), make_pair(tout[i], 0) )-d[dep[u]].begin();
                    mp[dep[u]]=r-l;
                }
                mp[dep[u]]--;
                if( mp[dep[u]]==0 ) mp[dep[u]]=-1;
                cnt++;
            }
        }
        for( int u : v[c[i]] ){
            if( dep[u]<=dep[i] ) continue;
            if( !(tin[i]<=tin[u] && tout[u]<=tout[i]) ){
                if( !mp[dep[u]] ){
                    int l=lower_bound( d[dep[u]].begin(), d[dep[u]].end(), make_pair(tin[i], 0) )-d[dep[u]].begin();
                    int r=lower_bound( d[dep[u]].begin(), d[dep[u]].end(), make_pair(tout[i], 0) )-d[dep[u]].begin();
                    mp[dep[u]]=r-l;
                }
                if( mp[dep[u]]==0 ) mp[dep[u]]=-1;
                if( mp[dep[u]]==-1 ) continue;
                mp[dep[u]]--;
                if( mp[dep[u]]==0 ) mp[dep[u]]=-1;
                cnt++;
                sw++;
            }
        }
        ans=max( ans, make_pair(cnt, -sw) );
    }

    cout << ans.first << ' ' << -ans.second << '\n';

    return 0;
}