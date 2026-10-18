#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[200005][2];
int f[200005];
int cnt[200005];
vector<tuple<int,int,int>> v;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i=0 ; i<n ; i++ ){
        cin >> a[i][0] >> a[i][1];
        f[a[i][0]]=f[a[i][1]]=i;
        cnt[(a[i][0]+a[i][1])%(2*n)]++;
    }

    int ans=1e9, idx=0;
    for( int i=1 ; i<2*n ; i+=2 ){
        if( n-cnt[i]<ans ){
            ans=n-cnt[i];
            idx=i;
        }
    }

    for( int i=0 ; i<n ; i++ ){
        if( (a[i][0]+a[i][1])%(2*n)!=idx ){
            int x=0, j=i;
            while( 1 ){
                int des=(idx-a[j][x]+2*n)%(2*n);
                int nxt=f[des];
                int ori=a[j][x^1];
                v.push_back({ j, a[j][x^1], des });
                a[j][x^1]=des;
                f[des]=j;
                f[ori]=-1;
                j=nxt;
                if( j==-1 ) break;
                x=( des==a[nxt][0] ? 1 : 0 );
            }
        }
    }

    cout << ans << '\n';
    for( int i=0 ; i<v.size() ; i++ ){
        int x, y, z;
        tie( x, y, z )=v[i];
        cout << x << ' ' << y << ' ' << z << '\n';
    }

    return 0;
}