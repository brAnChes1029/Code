#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int sz[6]={1,2,3,4,6,12};
int dp[55];
int from[55];
tuple<int,int,int,int> fst[55];
vector< tuple<int,int,int,int> > v, ans;

int C( int i, int j ){
    ll re=1;
    for( int x=1 ; x<=j ; x++ ) re=re*(i-x+1)/x;
    return (int)re;
}

int main(){

    cin >> n;

    for( int x=0 ; x<6 ; x++ ){
        int d=sz[x];
        for( int i=0 ; 12+i*d<=50 ; i++ ){
            if( C( 12/d+i, 12/d )>50 ) break;
            v.push_back({ d, i, C( 12/d+i, 12/d ), 12+i*d });
        }
    }

    dp[0]=0;
    for( int i=1 ; i<=n ; i++ ){
        dp[i]=1e9;
        for( auto u : v ){
            int d, j, c, m;
            tie( d, j, c, m )=u;
            if( i-c>=0 && dp[i-c]+m<=50 ){
                if( dp[i-c]+m<dp[i] ){
                    dp[i]=dp[i-c]+m;
                    from[i]=i-c;
                    fst[i]=u;
                }
            }
        }
    }

    while( n>0 ){
        ans.push_back( fst[n] );
        n=from[n];
    }
    int cnt=0;
    for( auto u : ans ){
        int d, j, c, m;
        tie( d, j, c, m )=u;
        for( int i=0 ; i<(1<<(12/d+j)) ; i++ ){
            if( __builtin_popcount(i)==12/d ){
                for( int l=0 ; l<(12/d+j) ; l++ ){
                    if( i&(1<<l) ){
                        for( int x=0 ; x<d ; x++ ) cout << x+l*d+cnt << ' ';
                    }
                }
                cout << '\n';
            }
        }
        cnt+=m;
    }

    return 0;
}