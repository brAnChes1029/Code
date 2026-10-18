#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;
vector<int> v;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> s;
    if( s[0]=='-' || s[n-1]=='+' ){
        cout << "NO\n";
        return 0;
    }

    for( int i=0 ; i<n ; i++ ){
        if( s[i]=='-' ) v.push_back(i);
    }
    for( int i=n-1 ; i>=0 ; i-- ){
        if( s[i]=='+' ) v.push_back(i);
    }

    reverse( v.begin(), v.end() );
    cout << "YES\n";
    for( auto u : v ) cout << u << ' ';

    return 0;
}