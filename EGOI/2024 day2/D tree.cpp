#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int root;
int c[105];
int dep[105];
vector<int> a[105], d[105];

void dfs( int i, int p ){
    d[dep[i]].push_back(i);
    for( int u : a[i] ){
        if( u==p ) continue;
        dep[u]=dep[i]+1;
        dfs( u, i );
    }
}

void print(){
    for( int i=0 ; i<n ; i++ ) cout << c[i] << ' ';
    cout << '\n';
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i=0 ; i<m ; i++ ){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for( int i=0 ; i<n ; i++ ){
        if( a[i].size()==1 ){
            root=i;
            break;
        }
    }
    dfs( root, -1 );

    cout << 600 << '\n';
    for( int r=0 ; r<600 ; r++ ){
        int cnt=0;
        if( r&1 ){
            c[root]=0;
            for( int i=1 ; i<n ; i+=2 ){
                for( int u : d[i] ) c[u]=cnt;
                for( int u : d[i+1] ) c[u]=cnt;
                cnt++;
            }
        }
        else{
            for( int i=0 ; i<n ; i+=2 ){
                for( int u : d[i] ) c[u]=cnt;
                for( int u : d[i+1] ) c[u]=cnt;
                cnt++;
            }
        }
        print();
    }

    return 0;
}