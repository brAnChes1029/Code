#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
int t[200005];
int a[200005];
int ans[200005];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for( int i=0 ; i<n ; i++ ){
        cin >> a[i];
        if( i!=0 && a[i]<a[i-1] ){
            t[i]=0;
        }
        else t[i]=-1;
    }

    for( int j=1 ; j<=q ; j++ ){
        char c;
        cin >> c;
        if( c=='!' ){
            int i, x;
            cin >> i >> x;
            if( i!=0 && a[i]<a[i-1] && !(x<a[i-1]) ){
                ans[i]+=j-t[i];
                t[i]=-1;
            }
            if( i+1!=n && a[i+1]<a[i] && !(a[i+1]<x) ){
                ans[i+1]+=j-t[i+1];
                t[i+1]=-1;
            }
            if( i!=0 && !(a[i]<a[i-1]) && x<a[i-1] ){
                t[i]=j;
            }
            if( i+1!=n && !(a[i+1]<a[i]) && a[i+1]<x ){
                t[i+1]=j;
            }
        
            a[i]=x;
        }
        else{
            int i;
            cin >> i;
            int re=ans[i];
            if( t[i]!=-1 ) re+=j-t[i];
            cout << re << '\n';
        }
    }

    return 0;
}