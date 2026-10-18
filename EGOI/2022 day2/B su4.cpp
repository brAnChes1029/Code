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
        c-=a;
        d-=b;
        if( c==0 && d==0 ) cout << "0\n";
        else if( abs(c)==abs(d) ) cout << "1\n";
        else if( abs(c)%2==abs(d)%2 ) cout << "2\n";
        else cout << "-1\n";
    }

    return 0;
}