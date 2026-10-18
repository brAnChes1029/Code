#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int q;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> q;
    while( q-- ){
        string s;
        cin >> s;
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if( b==d && a<=c ) cout << c-a << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}