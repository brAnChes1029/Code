#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int o, n;
int vis[100005];
int zkw[100];
int a[100005];
vector<int> v;

void Anna(){
    int sum=0;
    for( int i=0 ; i<n-32 ; i++ ){
        int x;
        cin >> x;
        sum+=x;
        sum%=(n/2);
        vis[x]=1e5;
        cout << 7 << endl;
    }

    int cnt=0;
    for( int i=0 ; i<n ; i++ ){
        if( !vis[i] ){
            vis[i]=cnt++;
        }
    }
    for( int i=0 ; i<31 ; i++ ){
        int x;
        cin >> x;
        int y=vis[x]+32, layer;
        while( y>0 ){
            zkw[y]++;
            y/=2;
        }
        y=vis[x]+32;
        for( int j=5 ; j>0 ; j-- ){
            if( zkw[y]!=(1<<(5-j)) ){
                break;
            }
            layer=j;
            y/=2;
        }
        if( layer==5 ){
            if( sum&((1<<vis[x]/2)) ) cout << 6 << endl;
            else cout << 5 << endl;
        }
        else{
            cout << layer << endl;
        }
    }
}

void Bertil(){
    int sum=0, cnt=0;
    for( int i=0 ; i<n ; i++ ){
        cin >> a[i];
        if( a[i]!=7 ){
            v.push_back(i);
            sum+=i;
            sum%=(n/2);
        }
    }

    if( v.size()==32 ){
        int l=0, r=32, mid;
        for( int i=5 ; i>0 ; i-- ){
            mid=(l+r)/2;
            int min1=10, min2=10, idx1, idx2;
            for( int j=l ; j<mid ; j++ ){
                if( a[v[j]]<min1 ) min1=a[v[j]], idx1=v[j];
            }
            for( int j=mid ; j<r ; j++ ){
                if( a[v[j]]<min2 ) min2=a[v[j]], idx2=v[j];
            }
            if( min1==min2 || i==1 ){
                cout << idx1 << ' ' << idx2 << endl;
                return;
            }
            else if( min1<min2 ) l=mid;
            else r=mid;
        }
    }
    else{
        int x=0;
        for( int i=0 ; i<31 ; i++ ){
            if( a[v[i]]==5 || a[v[i]]==6 ){
                if( a[v[i]]==6 ) cnt+=(1<<x);
                x++;
            }
        }

        sum+=cnt;
        sum%=(n/2);
        if( sum==0 ) cout << n/2 << ' ' << 0 << endl;
        else cout << (n/2)-sum << ' ' << n-sum << endl;
    }
}

int main(){

    cin >> o >> n;
    if( o==1 ){
        cout << 7 << endl;
        Anna();
    }
    else{
        Bertil();
    }

    return 0;
}