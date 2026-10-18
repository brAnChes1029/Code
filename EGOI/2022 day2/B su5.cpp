#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int q;
bool ok[26];
int di[8]={ 2, 2, 1, 1, -1, -1, -2, -2 };
int dj[8]={ -1, 1, -2, 2, -2, 2, -1, 1 };

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> q;
    while( q-- ){
        string s;
        cin >> s;
        for( int i=0 ; i<s.length() ; i++ ){
            ok[s[i]-'A']=true;
        }
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        c-=a;
        d-=b;
        bool f=false;
        if( c==0 && d==0 ){
            cout << "0\n";
            continue;
        } 
        else if( abs(c)==abs(d) ){
            cout << "1\n";
            continue;
        }

        if( ok['N'-'A'] ){
            for( int k=0 ; k<8 ; k++ ){
                if( c==di[k] && d==dj[k] ){
                    cout << "1\n";
                    f=true;
                    break;
                }
            }
        }
        if( ok['P'-'A'] ){
            if( c==1 && d==0 ){
                cout << "1\n";
                f=true;
            }
        }
        if( ok['K'-'A'] ){
            if( abs(a-c)<=1 && abs(b-d)<=1 ){
                cout << "1\n";
                f=true;
            }
        }

        if( !f ){
            if( ok['N'-'A'] || ok['P'-'A'] || ok['K'-'A'] ) cout << "3\n";
            else cout << "-1\n";
        }
    }

    return 0;
}