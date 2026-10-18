#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
vector<int> a[300005];
vector<int> root;
int ind[300005];
bool vis[300005];
queue<int> q;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for( int i=0 ; i<m ; i++ ){
        int x, y;
        cin >> x >> y;
        a[y].push_back(x);
        ind[x]++;
    }

    for( int i=0 ; i<n ; i++ ){
        if( ind[i]==0 ){
            vis[i]=1;
            q.push(i);
            root.push_back(i);
        }
        else if( ind[i]>=2 ){
            cout << "NO\n";
            return 0;
        }
    }
    while( !q.empty() ){
        int i=q.front();
        q.pop();
        for( int u : a[i] ){
            ind[u]--;
            if( ind[u]==0 ){
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
        for( int u : a[i] ){
            cout << u << ' ' << i << '\n';
        }
    }
    for( int i=1 ; i<root.size() ; i++ ){
        cout << root[i] << ' ' << root[0] << '\n';
    }

    return 0;
}