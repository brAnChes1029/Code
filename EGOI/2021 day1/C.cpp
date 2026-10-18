#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[105];
map<ll,bool> mp;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> dis( 1, 5e15 );

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    
    for( int s=0 ; s<100 ; s++ ){
        cout << '?';
        for( int i=1 ; i<=n ; i++ ){
            while( 1 ){
                ll x=dis(mt);
                if( !mp[x] ){
                    mp[x]=true;
                    cout << ' ' << x;
                    break;
                }
            }
        }
        cout << endl;
        cin >> a[s];
    }

    cout << '?';
    int cnt=0;
    for( int i=0 ; i<100 ; i++ ){
        for( int j=0 ; j<i ; j++ ){
            if( cnt<n && !mp[a[i]+a[j]] ){
                cnt++;
                mp[a[i]+a[j]]=true;
                cout << ' ' << a[i]+a[j];
            }
            if( cnt<n && !mp[abs(a[i]-a[j])] ){
                cnt++;
                mp[abs(a[i]-a[j])]=true;
                cout << ' ' << abs(a[i]-a[j]);
            }
        }
    }
    cout << endl;
    cin >> a[100];

    cout << "! 1 2\n";
    for( int i=0 ; i<101 ; i++ ){
        for( int j=0 ; j<101 ; j++ ){
            for( int k=0 ; k<101 ; k++ ){
                if( i!=j && j!=k && i!=k ){
                    if( a[i]==a[j]+a[k] ){
                        cout << a[i] << '\n' << a[j] << ' ' << a[k] << endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}