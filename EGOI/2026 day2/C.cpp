#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int minL[100005];
int maxL[100005];
int minR[100005];
int maxR[100005];
set< pair<int,int> > st1, st2;

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i=0 ; i<n ; i++ ){
        int l, r;
        cin >> l >> r;
        minL[i]=maxL[i]=l, minR[i]=maxR[i]=r;

        while( 1 ){
            auto it=st1.upper_bound({l, n});
            if( it==st1.begin() ) break;
            it=prev(it);
            int j=it->second;
            if( (l<minL[j] && r<minR[j]) || (maxL[j]<l && maxR[j]<r) ) break;
            minL[i]=min( minL[i], minL[j] );
            maxL[i]=max( maxL[i], maxL[j] );
            minR[i]=min( minR[i], minR[j] );
            maxR[i]=max( maxR[i], maxR[j] );
            st2.erase({ minR[j], j });
            st1.erase(it);
        }
        
        while( 1 ){
            auto it=st2.upper_bound({r, n});
            if( it==st2.begin() ) break;
            it=prev(it);
            int j=it->second;
            if( (l<minL[j] && r<minR[j]) || (maxL[j]<l && maxR[j]<r) ) break;
            minL[i]=min( minL[i], minL[j] );
            maxL[i]=max( maxL[i], maxL[j] );
            minR[i]=min( minR[i], minR[j] );
            maxR[i]=max( maxR[i], maxR[j] );
            st1.erase({ minL[j], j });
            st2.erase(it);
        }

        st1.insert({ minL[i], i });
        st2.insert({ minR[i], i });
        cout << st1.size() << '\n';
    }

    return 0;
}