#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
bool vis[300005];
vector<int> a[300005];
vector<int> ans;
set< tuple<int,int,int> > st;
set<int> table;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i=0 ; i<m ; i++ ){
        int sz;
        cin >> sz;
        for( int j=0 ; j<sz ; j++ ){
            int x;
            cin >> x;
            vis[x]=true;
            a[i].push_back(x);
            if( j==0 ){
                ans.push_back(x);
                table.insert(x);
            }
            if( j==1 ) st.insert({ x, i, j });
        }
    }
    for( int i=0 ; i<n ; i++ ){
        if( !vis[i] ) st.insert({ i, -1, -1 });
    }

    bool f=true;
    for( int r=0 ; r<n-m ; r++ ){
        bool ok=false;
        int mn=*table.begin();
        for( auto [i, x, y] : st ){
            if( x==-1 ){
                if( mn>i ){
                    ans.push_back(i);
                    ok=true;
                    st.erase({ i, x, y });
                    break;
                }
            }
            else{
                auto it=table.lower_bound(i);
                if( it==table.begin() ) continue;
                it--;
                if( *it==a[x][y-1] ){
                    ans.push_back(i);
                    table.erase(it);
                    table.insert(i);
                    ok=true;
                    st.erase({ i, x, y });
                    if( y+1<a[x].size() ) st.insert({ a[x][y+1], x, y+1 });
                    break;
                }
            }
        }
        if( !ok ){
            f=false;
            break;
        }
    }

    if( !f ) cout << "NO\n";
    else{
        cout << "YES\n";
        for( int u : ans ) cout << u << ' ';
    }

    return 0;
}