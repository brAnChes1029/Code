#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
bool no[1005];
int a[1005][1005];
vector<int> ans;

void ac( int idx, int i ){
    ans.push_back(i);
    for( int j=ans.size()-1 ; j>idx ; j-- ) swap( ans[j], ans[j-1] );
}

int main(){

    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i=1 ; i<n ; i++ ){
        for( int j=0 ; j<i ; j++ ){
            cin >> a[i][j];
        }
    }

    ans.push_back(0);
    ans.push_back(1);
    for( int i=2 ; i<n ; i++ ){
        for( int j=0 ; j<n ; j++ ) no[j]=false;
        for( int j=0 ; j<i ; j++ ){
            if( j>=(i+1)/2 ) no[a[i][j]]=true;
        }
        bool f=false;
        if( !no[ans[0]] ){
            ac( 0, i );
            continue;
        }
        for( int j=1 ; j<ans.size() ; j++ ){
            if( !no[ans[j-1]] && !no[ans[j]] ){
                ac( j, i );
                f=true;
                break;
            }
        }
        if( !f && !no[ans[ans.size()-1]] ){
            ans.push_back(i);
        }
    }

    for( int u : ans ){
        cout << u << ' ';
    }

    return 0;
}