#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int o, n;

struct node{
    int l, r;
    int ls, rs;
    int c, dep;
};
node st[200005];
int cnt=1;

void build( int l, int r, int idx ){
    st[idx].l=l;
    st[idx].r=r;
    st[idx].c=0;
    if( l+1==r ) return;
    else{
        int mid=(l+r)/2;
        int ls=st[idx].ls=cnt++;
        int rs=st[idx].rs=cnt++;
        st[ls].dep=st[rs].dep=st[idx].dep+1;
        build( l, mid, ls );
        build( mid, r, rs );
    }
}

int layer;
void modify( int x, int idx ){
    if( st[idx].l==st[idx].r-1 ){
        st[idx].c++;
    }
    else{
        int mid=(st[idx].l+st[idx].r)/2;
        int ls=st[idx].ls;
        int rs=st[idx].rs;
        if( x<mid ) modify(x,ls);
        else modify(x,rs);
        st[idx].c=st[ls].c+st[rs].c;
    }
    if( st[idx].c==st[idx].r-st[idx].l ) layer=min( layer, st[idx].dep );
}

void Anna(){
    cout << 17 << endl;

    for( int i=1 ; i<n ; i++ ){
        int x;
        cin >> x;
        layer=1e9;
        modify( x, 0 );
        cout << layer << endl;
    }
}

int a;
vector<int> v[20];

void Bertil(){
    for( int i=0 ; i<n ; i++ ){
        cin >> a;
        v[a].push_back(i);
    }
    int idx=0;
    for( int i=1 ; i<=3 ; i++ ){
        int fi=lower_bound( v[i].begin(), v[i].end(), st[idx].l )-v[i].begin();
        int se=lower_bound( v[i].begin(), v[i].end(), v[i][fi]+1 )-v[i].begin();
        int ls=st[idx].ls;
        int rs=st[idx].rs;
        if( se==v[i].size() || v[i][se]>=st[idx].r ){
            if( st[ls].l<=v[i][fi] && v[i][fi]<st[ls].r ){
                idx=rs;
            }
            else{
                idx=ls;
            }
        }
        else{
            cout << v[i][fi] << ' ' << v[i][se] << endl;
            break; 
        }
    }
}

int main(){

    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> o >> n;
    st[0].dep=0;
    build( 0, n, 0 );
    if( o==1 ) Anna();
    else Bertil();

    return 0;
}