#include <bits/stdc++.h>
#include "toydesign.h"
using namespace std;

int cnt=2;
int ver[205];
int idx[205];
int small[205];
vector< pair<int,int> > ans;

void ToyDesign( int n, int max_ops ){
    ver[1]=0;
    small[1]=1;
    idx[1]=1;
    for( int i=2 ; i<=n ; i++ ){
        ver[i]=Connected( ver[i-1], i, i-1 );
        if( ver[i]==ver[i-1] ){
            int l=1, r=cnt, mid, x=cnt-1;
            while( l<r ){
                mid=(l+r)/2;
                if( Connected( ver[idx[mid]], i, idx[mid] )==ver[idx[mid]] ){
                    x=mid;
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            small[i]=idx[x];
        }
        else{
            small[i]=i;
            idx[cnt++]=i;
        }
    }

    for( int i=1 ; i<=n ; i++ ){
        if( small[i]!=i ) ans.push_back({ i, small[i] });
    }

    DescribeDesign( ans );
}
