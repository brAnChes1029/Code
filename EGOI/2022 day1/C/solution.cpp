#include <bits/stdc++.h>
#include "socialengineering.h"
using namespace std;
typedef long long ll;

int n, m;
vector<int> a[200005];
vector<int> r[200005];
bool spe[200005];
bool vis[200005];

int dfs( int i ){
    vis[i]=true;
    vector<int> p;
    if( spe[i] ){
        p.push_back(i);
        r[i].push_back(i);
    }
    for( int u : a[i] ){
        if( !vis[u] ){
            int x=dfs( u );
            if( x!=0 ){
                p.push_back(x);
                r[x].push_back(i);
            }
        }
    }
    while( p.size()>=2 ){
        int x=p.back();
        p.pop_back();
        int y=p.back();
        p.pop_back();
        r[x].pop_back();
        while( !r[x].empty() ){
            r[y].push_back(r[x].back());
            r[x].pop_back();
        }
        r[x]=r[y];
        reverse( r[x].begin(), r[x].end() );
    }
    if( p.empty() ) return 0;
    else return p[0];
}

void SocialEngineering( int N, int M, vector<pair<int,int>> A ){
    n=N;
    m=M;
    for( int i=0 ; i<m ; i++ ){
        int x, y;
        tie(x, y)=A[i];
        if( x==1 ) spe[y]=true;
        if( y==1 ) spe[x]=true;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    vis[1]=true;
    for( int i=2 ; i<=n ; i++ ){
        if( vis[i] ) continue;
        if( dfs( i )!=0 ){
            return;
        }
    }

    while( 1 ){
        int st=GetMove();
        if( !st ) break;
        //cout << "st=" << st << ' ';
        for( int i=1 ; i<r[st].size() ; i++ ){
            //cout << r[st][i] << ' ';
            MakeMove( r[st][i] );
        }
        //cout << '\n';
        MakeMove( 1 );
    }

    return;
}