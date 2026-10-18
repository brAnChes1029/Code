#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
vector<int> a;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for( int i=0 ; i<n ; i++ ){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort( a.begin(), a.end(), greater<int>() );

    while( q-- ){
        int x, y;
        cin >> x >> y;
        for( int i=0 ; i<y ; i++ ) a[i]-=x;
        inplace_merge( a.begin(), a.begin()+y, a.end(), greater<int>() );
    }

    for( int i=0 ; i<n ; i++ ) cout << a[i] << ' ';

    return 0;
}