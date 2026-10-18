#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
int root_cnt;
set<int> b[105];
vector<int> a[105];
vector<int> tree[105];
int ind1[105];
int ind2[105];
bool ok[105];
bool vis[105];
bool root[105];
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
        b[x].insert(y);
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
        if( ind2[i]==0 ){
            q.push(i);
            root[i]=true;
            root_cnt++;
            tree[i].push_back(i);
            while( !q.empty() ){
                int j=q.front();
                q.pop();
                for( int u : a[j] ){
                    tree[i].push_back(u);
                    q.push(u);
                }
            }
        }
    }

    for( int i=0 ; i<n ; i++ ){
        if( !root[i] ) continue;
        for( int j=0 ; j<n ; j++ ) ok[j]=false;
        vector< pair<int,int> > ans;
        for( int u : tree[i] ) ok[u]=true;
        while( 1 ){
            bool f2=false;
            for( int j=0 ; j<n ; j++ ){
                if( ok[j] ) continue;
                if( !root[j] ) continue;
                bool f=false;
                for( int l=0 ; l<n ; l++ ){
                    if( ok[l] && !b[j].count(l) ){
                        ans.push_back({ j, l });
                        f=true;
                        break;
                    }
                }
                if( f ){
                    for( int u : tree[j] ){
                        ok[u]=true;
                    }
                    f2=true;
                    break;
                }
            }
            if( !f2 ) break;
        }

        bool ch=true;
        for( int i=0 ; i<n ; i++ ){
            if( !ok[i] ) ch=false;
        }
        if( ch ){
            for( int i=0 ; i<n ; i++ ){
                for( int u : a[i] ){
                    cout << u << ' ' << i << '\n';
                }
            }
            for( auto p : ans ) cout << p.first << ' ' << p.second << '\n';
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}