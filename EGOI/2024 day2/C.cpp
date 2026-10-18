#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int ansi[105], ansj[105], a[105][105], q[105][105];
int pi[105], pj[105];
int cnt[160005];
bool vis[105][105];
vector< pair<int,int> > pos;
vector< bitset<405> > st;
vector<int> tryq;
bitset<405> bs;


bool cmp( bitset<405> b1, bitset<405> b2 ){
    for( int i=400 ; i>=0 ; i-- ){
        if( b1[i]!=b2[i] ) return b1[i]<b2[i];
    }
    return false;
}

bool check( pair<int,int> p ){
    return ( a[p.first][p.second] || (!ansi[p.first] && !ansj[p.second]) );
}

int try_query( vector< pair<int,int> > v, bitset<405> b ){
    memset( pi, 0, sizeof(pi) );
    memset( pj, 0, sizeof(pj) );
    for( int i=0 ; i<v.size() ; i++ ){
        if( !b[i] ) pi[v[i].first]=1;
        else pj[v[i].second]=1;
    }
    int cnti=0, cntj=0;
    for( int i=1 ; i<=n ; i++ ){
        cnti+=pi[i], cntj+=pj[i];
    }
    return (cnti+cntj)*n-(cnti*cntj);
}

int query(){
    cout << "?" << endl;
    for( int x=1 ; x<=n ; x++ ){
        for( int y=1 ; y<=n ; y++ ) cout << q[x][y];
        cout << endl;
    }
    int re;
    cin >> re;
    return re;
}

void ans( int x ){
    cout << "!" << endl;
    for( int i=1 ; i<=n ; i++ ){
        for( int j=1 ; j<=n ; j++ ){
            if( x==0 ) cout << ( j==ansi[i] );
            else cout << ( i==ansj[j] );
        }
        cout << endl;
    }
    exit(0);
}

int main(){

    cin >> n;
    st.push_back(bs);
    while( 1 ){
        // if there is an answer
        bool c1=true, c2=true;
        for( int i=1 ; i<=n ; i++ ) c1&=(bool)ansi[i], c2&=(bool)ansj[i];
        if( c1 ) ans( 0 );
        if( c2 ) ans( 1 );

        // try to add a light (random)
        while( st.size()*2<=1000 ){
            vector< pair<int,int> > p;
            memset( vis, 0, sizeof(vis) );
            for( auto [x, y] : pos ) vis[x][y]=true;
            for( int i=1 ; i<=n ; i++ ){
                for( int j=1 ; j<=n ; j++ ){
                    if( !vis[i][j] && !ansi[i] && !ansj[j] && !a[i][j] ) p.push_back({i, j});
                }
            }
            if( p.empty() ) break;
            int sz=st.size();
            for( int i=0 ; i<sz ; i++ ){
                bs=st[i];
                bs[pos.size()]=1, st.push_back(bs);
            }
            pos.push_back(p[ mt()%p.size() ]);
        }

        // try to find the best query
        int t=35, now=1e9;
        vector<int> best;
        while( t-- ){
            int mx=0; tryq.clear();
            queue<int> q;
            vector< pair<int,int> > v;
            for( auto u : pos ) tryq.push_back(mt()%2);
            for( int i=0 ; i<pos.size() ; i++ ){
                if( tryq[i] ) v.push_back(pos[i]);
            }
            for( bitset<405> b : st ){
                bitset<405> nxt;
                nxt.reset();
                int x=0;
                for( int i=0 ; i<pos.size() ; i++ ){
                    if( tryq[i] ) nxt[x]=b[i], x++;
                }
                int re=try_query( v, nxt );
                q.push(re);
                cnt[re]++;
                mx=max( mx, cnt[re] );
            }
            if( mx<now ) now=mx, best=tryq;
            while( !q.empty() ) cnt[q.front()]=0, q.pop();
        }

        // query
        memset( q, 0, sizeof(q) );
        for( int i=0 ; i<pos.size() ; i++ ){
            if( best[i] ) q[pos[i].first][pos[i].second]=1;
        }
        int sum=query();

        // erase the wrong states
        vector< pair<int,int> > v;
        vector<bitset<405>> st2;
        for( int i=0 ; i<pos.size() ; i++ ){
            if( best[i] ) v.push_back(pos[i]);
        }
        for( bitset<405> b : st ){
            bitset<405> nxt;
            nxt.reset();
            int x=0;
            for( int i=0 ; i<pos.size() ; i++ ){
                if( best[i] ) nxt[x]=b[i], x++;
            }
            int re=try_query( v, nxt );
            if( re==sum ) st2.push_back(b);
        }
        st=st2;

        // check if the derection of a light is known
        for( int i=0 ; i<pos.size() ; i++ ){
            int v=st[0][i];
            for( bitset<405> b : st ){
                if( b[i]!=v ) v=-1;
            }
            if( v!=-1 ){
                int x=pos[i].first, y=pos[i].second;
                a[x][y]=v;
                if( v==0 ) ansi[x]=y;
                else ansj[y]=x;
            }
        }

        // update the states
        st2.clear();
        for( bitset<405> b : st ){
            bs.reset();
            int x=0;
            for( int i=0 ; i<pos.size() ; i++ ){
                if( check(pos[i]) ) bs[x]=b[i], x++;
            }
            st2.push_back(bs);
        }
        sort( st2.begin(), st2.end(), cmp );
        st.clear();
        for( int i=0 ; i<st2.size() ; i++ ){
            if( i==0 || (st2[i]!=st2[i-1]) ) st.push_back(st2[i]);
        }

        // update the unknown lights
        vector< pair<int,int> > pos2;
        for( auto u : pos ){
            if( check(u) ) pos2.push_back(u);
        }
        pos=pos2;
    }

    return 0;
}
