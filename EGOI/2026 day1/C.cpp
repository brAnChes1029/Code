#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
int sum, cnt=1;
int a[100005];

struct node{
    int l, r;
    int ls, rs;
    int bis[55];
};
node st[200005];

void build( int l, int r, int idx ){
    st[idx].l=l, st[idx].r=r;
    if( l+1==r ){
        for( int i=0 ; i<=50 ; i++ ){
            st[idx].bis[i]=abs(i-a[l]);
        }
    }
    else{
        int mid=(l+r)/2;
        int ls=st[idx].ls=cnt++;
        int rs=st[idx].rs=cnt++;
        build( l, mid, ls );
        build( mid, r, rs );
        for( int i=0 ; i<=50 ; i++ ){
            st[idx].bis[i]=st[ls].bis[st[rs].bis[i]];
        }
    }
}

void modify( int j, int k, int idx ){
    if( st[idx].l+1==st[idx].r ){
        for( int i=0 ; i<=50 ; i++ ){
            st[idx].bis[i]=abs(i-k);
        }
    }
    else{
        int mid=(st[idx].l+st[idx].r)/2;
        int ls=st[idx].ls;
        int rs=st[idx].rs;
        if( j<mid ) modify( j, k, ls );
        else modify( j, k, rs );
        for( int i=0 ; i<=50 ; i++ ){
            st[idx].bis[i]=st[ls].bis[st[rs].bis[i]];
        }
    }
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for( int i=0 ; i<n ; i++ ){
        cin >> a[i];
        sum+=a[i];
    }
    build( 0, n, 0 );
    cout << (sum-st[0].bis[0])/2 << '\n';

    while( q-- ){
        int j, k;
        cin >> j >> k;
        sum-=a[j], a[j]=k, sum+=a[j];
        modify( j, k, 0 );
        cout << (sum-st[0].bis[0])/2 << '\n';
    }

    return 0;
}