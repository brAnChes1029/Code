#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll id, m, cnt=1, idx;
mt19937 mt(1029000129);

void write( ll x, ll y ){
    cout << "w " << x << ' ' << y << endl;
}

ll read( ll x ){
    ll re;
    cout << "r " << x << endl;
    cin >> re;
    return re;
}

int main(){

    cin >> id >> m;
    m=(1<<17);
    vector<int> v(m);
    iota( v.begin(), v.end(), 0 );
    shuffle( v.begin(), v.end(), mt );
    id=v[id];

    for( ll i=0 ; i<17 ; i++ ){
        vector<ll> bits;
        for( ll j=0 ; j<7 ; j++ ){
            if( cnt&(1<<j) ) bits.push_back(j);
        }
        if( idx<bits.size() ) write( (id|(bits[idx]<<17)|(i<<21)), 1 );
        else read(0);

        ll add=0;
        ll read_bit=1+(i>6)+(i>9)+(i>12)+(i>13)+(i>14);
        for( int j=0 ; j<read_bit ; j++ ){
            if( read( ((id^1)|(j<<17)|(i<<21)) ) ) add+=(1<<j);
        }
        if( add>0 && id&1 ) idx+=add;
        cnt+=add;
        id/=2;
    }

    cout << "! " << cnt << endl;

    return 0;
}