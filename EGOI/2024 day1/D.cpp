#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int w, n;
int a[505], c[505];
int b[4][505];
int pre[505];
int nxt[505];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> w >> n;
    for( int i=1 ; i<=n ; i++ ){
        cin >> a[i];
        a[i]++;
        c[a[i]]=i;
    }
    for( int i=1 ; i<=n ; i++ ){
        int j=a[i];
        while( j!=i ){
            if( j<i ){
                nxt[i]=j;
                break;
            }
            j=a[j];
        }
        j=c[i];
        while( j!=i ){
            if( j<i ){
                pre[i]=j;
                break;
            }
            j=c[j];
        }
    }

    if( w==0 ){
        cout << 3 << endl;
    }
    else if( w==1 ){
        for( int i=1 ; i<=n ; i++ ){
            cin >> b[w-1][i]; b[w][i]=b[w-1][i];
            cout << (b[w][i]^b[w][nxt[i]]) << endl;
        }
    }
    else if( w==2 ){
        for( int i=n ; i>=1 ; i-- ){
            cin >> b[w-1][i]; b[w][i]=b[w-1][i];
            if( nxt[i] ){
                for( int j=a[i] ; j!=nxt[i] ; j=nxt[j] ) b[w][i]^=b[w-1][j];
                for( int j=c[i] ; j!=pre[i] ; j=pre[j] ) b[w][i]^=b[w][j];
            }
            else{
                for( int j=a[i] ; j!=i ; j=nxt[j] ) b[w][i]^=b[w-1][j];
            }
            cout << b[w][i] << endl;
        }
    }
    else{
        for( int i=1 ; i<=n ; i++ ){
            cin >> b[w-1][i]; b[w][i]=b[w-1][i];
            b[w][i]^=b[w][pre[i]];
            cout << b[w][i] << endl;
        }
    }

    return 0;
}