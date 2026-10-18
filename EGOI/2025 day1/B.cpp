#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int x, y;
int q[30005];

int query(){
    cout << "? ";
    for( int i=0 ; i<n ; i++ ) cout << q[i];
    cout << endl;
    int re;
    cin >> re;
    return re;
}

int main(){

    cin >> n;

    for( int i=0 ; i<15 ; i++ ){
        for( int j=0 ; j<n ; j++ ) q[j]=0;
        for( int j=0 ; j<n ; j++ ){
            if( j&(1<<i) ) q[j]=1;
        }
        if( query()&1 ){
            x+=(1<<i);
            y=i;
        }
    }

    vector<int> st;
    for( int i=0 ; i<n ; i++ ){
        if( i&(1<<y) ) st.push_back(i);
    }
    int l=0, r=st.size(), mid, ans;
    while( l<r ){
        mid=(l+r)/2;
        for( int i=0 ; i<n ; i++ ) q[i]=0;
        for( int i=0 ; i<=mid ; i++ ) q[st[i]]=1;
        if( query()&1 ){
            ans=st[mid];
            r=mid;
        }
        else{
            l=mid+1;
        }
    }

    cout << "! ";
    cout << ans << ' ' << (ans^x) << endl;

    return 0;
}