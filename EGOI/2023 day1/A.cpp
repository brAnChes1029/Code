#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
ll sum;
ll add;
map<ll,int> mp;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i=0 ; i<n ; i++ ){
        ll x;
        cin >> x;
        mp[x]++;
        sum+=x;
    }

    cin >> q;
    while( q-- ){
        string s;
        cin >> s;
        if( s=="SET" ){
            ll x, y;
            cin >> x >> y;
            if( x!=y ){
                mp[y-add]+=mp[x-add];
                sum+=(y-x)*mp[x-add];
                mp[x-add]=0;
            }
        }
        else{
            ll x;
            cin >> x;
            add+=x;
        }
        cout << sum+add*n << '\n';
    }
    
    return 0;
}