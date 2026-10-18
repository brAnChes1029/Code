#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int mp[5][5][5];
set< pair<int,int> > st;

int query( int i, int j, int k ){
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    int x;
    cin >> x;
    return x-1;
}

void solve(){
    cin >> n;
    memset( mp, 0, sizeof(mp) );
    st.clear();

    for( int i=0 ; i<5 ; i++ ){
        for( int j=i+1 ; j<5 ; j++ ){
            for( int k=j+1 ; k<5 ; k++ ){
                int x=query( i, j, k );
                mp[i][j][k]=mp[i][k][j]=mp[j][i][k]=mp[j][k][i]=mp[k][i][j]=mp[k][j][i]=x;
            }
        }
    }
    vector<int> v;
    for( int i=0 ; i<5 ; i++ ) v.push_back(i);
    do{
        if( mp[v[0]][v[1]][v[2]]<mp[v[0]][v[1]][v[3]] && mp[v[0]][v[1]][v[3]]<mp[v[0]][v[1]][v[4]] ){
            if( mp[v[4]][v[3]][v[2]]<mp[v[4]][v[3]][v[1]] && mp[v[4]][v[3]][v[1]]<mp[v[4]][v[3]][v[0]] ){
                st.insert({ 0, v[0] });
                st.insert({ mp[v[0]][v[1]][v[3]]-mp[v[1]][v[2]][v[3]], v[1] });
                st.insert({ mp[v[0]][v[1]][v[2]], v[2] });
                st.insert({ mp[v[0]][v[1]][v[3]], v[3] });
                st.insert({ mp[v[0]][v[1]][v[4]], v[4] });
                break;
            }
        }
    }while( next_permutation( v.begin(), v.end() ) );

    for( int i=5 ; i<n ; i++ ){
        auto it=st.begin();
        auto p0=*it;
        it++;
        auto p1=*it;
        auto it2=prev(st.end());
        auto p3=*it2;
        it2--;
        auto p2=*it2;

        int x1=query( p0.second, p1.second, i );
        int x2=query( p3.second, p2.second, i );
        int y;
        if( x1==p1.first-p0.first ){
            y=p3.first-x2;
        }
        else if( x2==p3.first-p2.first ){
            y=p0.first+x1;
        }
        else if( x2>p3.first-p0.first && x2>x1 ){
            y=p3.first-x2;
        }
        else if( x1>p3.first-p0.first && x1>x2 ){
            y=p0.first+x1;
        }
        else{
            y=p0.first+x1;
        }
        st.insert({y, i});
    }

    cout << "! ";
    for( auto u : st ) cout << u.second << ' ';
    cout << endl;
}

int main(){

    int t;
    cin >> t;
    while( t-- ){
        solve();
    }

    return 0;
}