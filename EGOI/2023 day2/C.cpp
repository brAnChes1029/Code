#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
set< pair<int,int> > forbid;
set<int> st;
vector<int> a[300000];
vector<int> tree[300005];
int ind1[300005];
int ind2[300005];
bool vis[300005];
queue<int> q;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for( int i=0 ; i<m ; i++ ){
        int x, y;
        cin >> x >> y;
        a[y].push_back(x);
        ind1[x]++;
        ind2[x]++;
    }
    for( int i=0 ; i<k ; i++ ){
        int x, y;
        cin >> x >> y;
        forbid.insert({x, y});
    }

    for( int i=0 ; i<n ; i++ ){
        if( ind1[i]==0 ){
            vis[i]=1;
            q.push(i);
        }
        else if( ind1[i]>=2 ){
            cout << "NO\n";
            return 0;
        }
    }
    while( !q.empty() ){
        int i=q.front();
        q.pop();
        for( int u : a[i] ){
            ind1[u]--;
            if( ind1[u]==0 ){
                vis[u]=1;
                q.push(u);
            }
        }
    }
    for( int i=0 ; i<n ; i++ ){
        if( !vis[i] ){
            cout << "NO\n";
            return 0;
        }
    }

    for( int i=0 ; i<n ; i++ ){
        if( ind2[i]==0 ) st.insert(i);
        vis[i]=false;
    }
    int last;
    for( int x=0 ; x<n ; x++ ){
        if( ind2[x]!=0 ) continue;
        if( ind2[x]==0 && vis[x] ) continue;
        last=x;
        st.erase(x);
        q.push(last);
        vis[last]=true;
        while( !q.empty() ){
            int i=q.front();
            q.pop();
            for( int u : a[i] ){
                tree[i].push_back(u);
                q.push(u);
                vis[u]=true;
            }
            for( auto it=st.begin() ; it!=st.end() ; ){
                int u=*it;
                if( !forbid.count({ u, i }) ){
                    tree[i].push_back(u);
                    if( !vis[u] ) q.push(u), vis[u]=true;
                    it=st.erase(it);
                }
                else{
                    it++;
                }
            }
        }
        st.insert(x);
    }

    for( int i=0 ; i<n ; i++ ) vis[i]=false;
    q.push(last);
    vis[last]=true;
    while( !q.empty() ){
        int i=q.front();
        q.pop();
        for( int u : tree[i] ){
            vis[u]=true;
            q.push(u);
        }
    }
    for( int i=0 ; i<n ; i++ ){
        if( !vis[i] ){
            cout << "NO\n";
            return 0;
        }
    }
    for( int i=0 ; i<n ; i++ ){
        for( int u : tree[i] ){
            cout << u << ' ' << i <<'\n';
        }
    }

    return 0;
}