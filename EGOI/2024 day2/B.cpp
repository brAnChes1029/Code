#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int ans;
int x[300005];
int y[300005];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i=0 ; i<n ; i++ ) cin >> x[i];
    for( int i=0 ; i<n ; i++ ) cin >> y[i];

    stack<int> st;
    for( int i=0 ; i<n ; i++ ){
        while( y[i]>0 && !st.empty() ){
            int j=st.top();
            st.pop();
            int add=min( x[j], y[i] );
            y[i]-=add;
            x[j]-=add;
            ans+=add;
            if( x[j]>0 ) st.push(j);
        }
        if( x[i]>0 ) st.push(i);
    }
    for( int i=0 ; i<n ; i++ ){
        if( y[i] ) ans-=max( 0, y[i]-x[i] );
    }

    cout << ans;
    
    return 0;
}