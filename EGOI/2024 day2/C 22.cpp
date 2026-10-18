#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int light[105];
int c[105][105];
int a[105][105];

int print( int i, int j, int k, int l ){
    memset( c, 0, sizeof(c) );
    c[i][j]=c[k][l]=1;
    cout << "?\n";
    for( int x=0 ; x<n ; x++ ){
        for( int y=0 ; y<n ; y++ ) cout << c[x][y];
        cout << '\n';
    }
    cout << endl;
    int re;
    cin >> re;
    return re;
}

bool check( int i, int j ){
    return ( i>=0 && j>=0 && i<n && j<n );
}

int main(){

    cin >> n;
    
    bool f=false;
    for( int i=0 ; i<n && !f ; i++ ){
        for( int j=0 ; j<n && !f ; j++ ){
            for( int k=0 ; k<j && !f ; k++ ){
                if( print( i, j, i, k )==n ){
                    a[i][j]=a[i][k]=1;
                    f=true;
                }
            }
        }
    }
    for( int i=0 ; i<n && !f ; i++ ){
        for( int j=0 ; j<n && !f ; j++ ){
            for( int k=0 ; k<j && !f ; k++ ){
                if( print( j, i, k, i )==n ){
                    a[j][i]=a[k][i]=2;
                }
            }
        }
    }

    queue< pair<int,int> > q;
    int di[4]={0, 0, -1, 1};
    int dj[4]={1, -1, 0, 0};
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            if( a[i][j]!=0 ){
                q.push({i, j});
            }
        }
    }
    while( !q.empty() ){
        int i, j;
        tie( i, j )=q.front();
        q.pop();
        for( int k=0 ; k<4 ; k++ ){
            int ni=i+di[k];
            int nj=j+dj[k];
            if( check( ni, nj ) && !a[ni][nj] ){
                if( k<2 ){
                    if( a[i][j]==2 ){
                        if( print( i, j, ni, nj )==2*n ) a[ni][nj]=2;
                        else a[ni][nj]=1;
                    }
                    else{
                        if( print( i, j, ni, nj )==n ) a[ni][nj]=1;
                        else a[ni][nj]=2;
                    }
                }
                else{
                    if( a[i][j]==2 ){
                        if( print( i, j, ni, nj )==n ) a[ni][nj]=2;
                        else a[ni][nj]=1;
                    }
                    else{
                        if( print( i, j, ni, nj )==2*n ) a[ni][nj]=1;
                        else a[ni][nj]=2;
                    }
                }
                q.push({ ni, nj });
            }
        }
    }

    cout << "!\n";
    for( int i=0 ; i<n ; i++ ){
        light[i]=-1;
        for( int j=0 ; j<n ; j++ ){
            if( a[i][j]==1 ){
                light[i]=j;
                break;
            }
        }
        if( light[i]==-1 ){
            for( int x=0 ; x<n ; x++ ){
                for( int y=0 ; y<n ; y++ ){
                    cout << ( x==i ? 1 : 0 );
                }
                cout << '\n';
            }
            return 0;
        }
    }
    for( int i=0 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ){
            cout << ( light[i]==j ? 1 : 0 );
        }
        cout << '\n';
    }

    return 0;
}