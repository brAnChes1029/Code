#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int root=-1, I=-1, s=-1;
int color[105];
int pa[105];
int dep[105];
bool vis[105];
bool path[105];
vector<int> a[105], c[105];
set<int> b[105];
set< pair<int,int> > e;

void print(){
    for( int i=0 ; i<n ; i++ ) cout << color[i] << ' ';
    cout << '\n';
}

void sol_path(){
    vector<int> v;
    int x=0;
    while( v.size()<n ){
        v.push_back(x);
        if( !b[x].empty() ) x=*b[x].begin();
    }

    cout << 600 << '\n';
    for( int r=0 ; r<600 ; r++ ){
        if( r&1 ){
            for( int i=0 ; i<n ; i++ ) color[v[i]]=i/2;
        }
        else{
            for( int i=0 ; i<n ; i++ ) color[v[i]]=(i+1)/2;
        }
        print();
    }
}

void dfs1( int i, int p ){
    vis[i]=true;
    path[i]=true;
    int child=0;
    for( int u : a[i] ){
        if( u==p || vis[u] ) continue;
        b[i].insert(u);
        dfs1( u, i );
        path[i]&=path[u];
        child++;
    }
    if( child>1 ) path[i]=false;
    
    if( child>=2 && root==-1 ){
        bool f=true;
        for( int u : b[i] ){
            f&=path[u];
        }
        if( !f ) return;
        for( int u : b[i] ){
            if( !e.count({ u, p }) ){
                root=u;
                break;
            }
        }
        if( root==-1 ) root=*b[i].begin();
        I=i;
        c[root].clear();
        c[root].push_back(i);
        if( !b[root].empty() ) c[root].push_back(*b[root].begin());
        c[i].clear();
        for( int u : b[i] ){
            if( u!=root ) c[i].push_back(u);
        }
        if( p>=0 ) c[i].push_back(p);
    }
}

void dfs2( int i, int p ){
    pa[i]=p;
    if( pa[i]==root && i!=I ) s=i;
    vis[i]=true;
    for( int u : c[i] ){
        if( u==p || vis[u] ) continue;
        dep[u]=dep[i]+1;
        dfs2( u, i );
    }
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i=0 ; i<m ; i++ ){
        int x, y;
        cin >> x >> y;
        e.insert({x, y}); e.insert({y, x});
        a[x].push_back(y); c[x].push_back(y);
        a[y].push_back(x); c[y].push_back(x);
    }

    dfs1( 0, 101 );
    if( root==-1 ){
        sol_path();
        return 0;
    }
    memset( vis, 0, sizeof(vis) );
    dfs2( root, 101 );

    // cout << "root " << root << '\n';
    // cout << "I " << I << '\n';
    // for( int i=0 ; i<n ; i++ ){
    //     cout << "\n" << i << ": ";
    //     for( int u : b[i] ) cout << u << ' ';
    // }
    // for( int i=0 ; i<n ; i++ ){
    //     cout << i << ' ' << pa[i] << '\n';
    // }

    cout << 600 << '\n';
    for( int r=0 ; r<600 ; r++ ){
        int cnt=0;
        if( r%3==0 ){ // odd
            for( int i=0 ; i<n ; i++ ){
                if( dep[i]%2==0 ) color[i]=cnt++;
            }
            for( int i=0 ; i<n ; i++ ){
                if( dep[i]%2==1 ) color[i]=color[pa[i]];
            }
            if( s!=-1 ) color[s]=cnt++;
        }
        else if( r%3==1 ){ // even
            for( int i=0 ; i<n ; i++ ){
                if( dep[i]%2==1 ) color[i]=cnt++;
            }
            for( int i=0 ; i<n ; i++ ){
                if( dep[i]%2==0 ) color[i]=color[pa[i]];
            }
            color[root]=color[I];
        }
        else if( r%3==2 ){ // bridge
            color[root]=n;
            if( s!=-1 ) color[s]=n;
            for( int i=0 ; i<n ; i++ ){
                if( color[i]!=n ) color[i]=cnt++;
            }
        }
        print();
    }

    return 0;
}