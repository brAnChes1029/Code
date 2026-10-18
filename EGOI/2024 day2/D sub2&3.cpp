#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int c[105];
vector< pair<int,int> > v;

void print(){
    for( int i=0 ; i<n ; i++ ) cout << c[i] << ' ';
    cout << '\n';
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i=0 ; i<m ; i++ ){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    cout << 600 << '\n';
    for( int r=0 ; r<600 ; r++ ){
        memset( c, 0, sizeof(c) );
        int cnt=1;
        if( r&1 ){
            for( int i=1 ; i<n ; i+=2 ){
                c[i]=c[i+1]=cnt++;
            }
        }
        else{
            for( int i=0 ; i<n ; i+=2 ){
                c[i]=c[i+1]=cnt++;
            }
        }
        print();
    }

    return 0;
}