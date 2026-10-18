#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int d[1005];
int nei[1005];
vector<int> leaf[1005];
vector< pair<int,int> > A, B;
queue<int> q;

void process( int i ){
    for( int u : leaf[i] ){
        cout << u << '\n';
        nei[i]^=u;
        d[i]--, d[u]--;
    }
    if( d[i]==1 ){
        q.push(i);
        leaf[nei[i]].push_back(i);
    }
    leaf[i].clear();
}

void Ann(){
    cin >> n;
    for( int i=0 ; i<n-1 ; i++ ){
        int x, y;
        cin >> x >> y;
        d[x]++, d[y]++, nei[x]^=y, nei[y]^=x;
    }
    for( int i=0 ; i<n ; i++ ){
        if( d[i]==1 ) leaf[nei[i]].push_back(i);
    }
    for( int i=0 ; i<n ; i++ ){
        if( !leaf[i].empty() ){
            int u=leaf[i][0];
            if( i<u ) A.push_back({ i, u });
            else B.push_back({ u, i });
        }
    }
    sort( A.begin(), A.end() );
    sort( B.begin(), B.end() );

    bool A_first=( B.empty() || (!A.empty() && A.back()>B[0]) );
    cout << ( A_first ? "1\n" : "0\n" );
    if( A_first ){
        for( auto p : A ) process( p.first );
    }
    for( auto p : B ) process( p.second );
    if( !A_first ){
        for( auto p : A ) process( p.first );
    }
    while( !q.empty() ){
        int i=q.front();
        q.pop();
        if( d[i]!=0 ) process( nei[i] );
    }
}

string s;
int t=1;
int lst[1005];
pair<int,int> lst_edge={-1, -1};

void Kathrin(){
    cin >> n >> s;
    bool big=( s=="1" ? 1 : 0 );
    for( int i=0 ; i<n-1 ; i++ ){
        int x, y;
        cin >> x >> y;
        bool ans;
        if( lst[x]==t-1 || (lst[x]<lst[y] && lst[y]!=t-1) ) ans=true;
        else ans=false;
        if( !lst[x] && !lst[y] ){
            if( make_pair(x, y)<lst_edge ) big=!big;
            lst_edge=make_pair(x, y);
            ans=big;
        }
        lst[x]=lst[y]=t++;
        cout << ( ans ? y : x ) << endl;
    }
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int p;
    cin >> p;
    if( p==1 ) Ann();
    else Kathrin();

    return 0;
}