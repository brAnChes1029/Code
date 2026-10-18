#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int q;
int di[8]={ 2, 2, 1, 1, -1, -1, -2, -2 };
int dj[8]={ -1, 1, -2, 2, -2, 2, -1, 1 };

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
        if( c==0 || d==0 || abs(c)==abs(d) ) cout << "1\n";
        else{
            bool ok=false;
            for( int k=0 ; k<8 ; k++ ){
                if( c==di[k] && d==dj[k] ){
                    cout << "1\n";
                    ok=true;
                    break;
                }
            }
            if( !ok ) cout << "2\n";
        }
    }

    return 0;
}