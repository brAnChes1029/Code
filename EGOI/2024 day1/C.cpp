#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, t;
int ans;
int const BLOCK=322;
int c[100005];
int dep[100005];
int tin[100005];
int tout[100005];
int up[100005];
bool cal[100005];
vector<int> v[100005];
vector<int> a[100005];
vector<int> d[100005];
unordered_map<int,int> mp;
map< pair<int,int>, int > cnt1;
unordered_map<int,int> cnt2;
unordered_map<int,int> cnt3;

void dfs( int i ){
    tin[i]=t++;
    d[dep[i]].push_back(tin[i]);
    cnt1[{ c[i], dep[i] }]++;
    if( !up[c[i]] ) cal[i]=true;
    up[c[i]]++;
    for( int u : a[i] ){
        dep[u]=dep[i]+1;
        dfs( u );
    }
    tout[i]=t++;
    up[c[i]]--;
}

int mx_dep;
void dfs2( int i, int co ){
    cnt2[dep[i]]++;
    mx_dep=max( mx_dep, dep[i] );
    if( c[i]==co ) cnt3[dep[i]]++;
    for( int u : a[i] ){
        dfs2( u, co );
    }
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
        if( v[c[i]].size()<=BLOCK ){
            int mx=1;
            int sw=0;
            mp.clear();
            for( int u : v[c[i]] ){
                if( dep[u]<=dep[i] ) continue;
                if( tin[i]<=tin[u] && tout[u]<=tout[i] ){
                    if( !mp[dep[u]] ){
                        int l=lower_bound( d[dep[u]].begin(), d[dep[u]].end(), tin[i] )-d[dep[u]].begin();
                        int r=lower_bound( d[dep[u]].begin(), d[dep[u]].end(), tout[i] )-d[dep[u]].begin();
                        mp[dep[u]]=r-l;
                    }
                    mp[dep[u]]--;
                    if( mp[dep[u]]==0 ) mp[dep[u]]=-1;
                    mx++;
                }
            }
            for( int u : v[c[i]] ){
                if( dep[u]<=dep[i] ) continue;
                if( !(tin[i]<=tin[u] && tout[u]<=tout[i]) ){
                    if( !mp[dep[u]] ){
                        int l=lower_bound( d[dep[u]].begin(), d[dep[u]].end(), tin[i] )-d[dep[u]].begin();
                        int r=lower_bound( d[dep[u]].begin(), d[dep[u]].end(), tout[i] )-d[dep[u]].begin();
                        mp[dep[u]]=r-l;
                    }
                    if( mp[dep[u]]==0 ) mp[dep[u]]=-1;
                    if( mp[dep[u]]==-1 ) continue;
                    mp[dep[u]]--;
                    if( mp[dep[u]]==0 ) mp[dep[u]]=-1;
                    mx++;
                    sw++;
                }
            }
            ans=max( ans, make_pair(mx, -sw) );
        }
        else{
            if( !cal[i] ) continue;
            cnt2.clear(), cnt3.clear();
            mx_dep=0;
            dfs2( i, c[i] );
            pair<int,int> p={0, 0};
            for( int j=dep[i]+1 ; j<=mx_dep ; j++ ){
                p.first+=min( cnt2[j], cnt1[{c[i], j}] );
                p.second+=cnt3[j];
            }
            p.second=-(p.first-p.second);
            p.first++;
            ans=max( ans, p );
        }
    }

    cout << ans.first << ' ' << -ans.second << '\n';

    return 0;
}