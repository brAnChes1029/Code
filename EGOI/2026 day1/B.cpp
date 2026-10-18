#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
priority_queue<int> pq;
vector<int> a[300005];
vector<int> ans;
deque<int> no;
int idx[300005];
bool vis[300005];

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i=0 ; i<m ; i++ ){
        int sz;
        cin >> sz;
        for( int j=0 ; j<sz ; j++ ){
            int x;
            cin >> x;
            vis[x]=true;
            a[i].push_back(x);
            if( j==0 ) ans.push_back(x);
        }
    }
    for( int i=0 ; i<n ; i++ ){
        if( !vis[i] ) no.push_back(i);
    }
    sort( a+0, a+m );

    for( int i=0 ; i<m ; i++ ){
        if( a[i].size()==1 ) continue;
        if( a[i][0]<a[i][1] ){
            if( i==m-1 || a[i][1]<a[i+1][0] ) pq.push(-i);
        }
    }

    while( !pq.empty() ){
        while( !no.empty() && no.front()<a[0][idx[0]] ){
            ans.push_back(no.front());
            no.pop_front();
        }

        int i=pq.top();
        pq.pop();
        i*=-1;
        idx[i]++;
        ans.push_back(a[i][idx[i]]);
        if( idx[i]+1<a[i].size() ){
            if( a[i][idx[i]]<a[i][idx[i]+1] ){
                if( i==m-1 || a[i][idx[i]+1]<a[i+1][idx[i+1]] ) pq.push(-i);
            }
        }

        if( i==0 ) continue;
        i--;
        if( idx[i]+1<a[i].size() ){
            if( a[i][idx[i]]<a[i][idx[i]+1] ){
                if( i==m-1 || a[i][idx[i]+1]<a[i+1][idx[i+1]] ) pq.push(-i);
            }
        }
    }
    while( !no.empty() && no.front()<a[0][idx[0]] ){
        ans.push_back(no.front());
        no.pop_front();
    }

    if( ans.size()!=n ){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for( int u : ans ) cout << u << ' ';

    return 0;
}