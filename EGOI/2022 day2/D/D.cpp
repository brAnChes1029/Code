#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll=pair<ll,ll>;
using ppll=pair<pll,pll>;

ppll ok( ppll p ){
    return {min(p.first, p.second), max(p.first, p.second)};
}
pll rotate_point( pll p ){
    return {p.second, 2-p.first};
}
ppll rotate( ppll p ){
    return ok({rotate_point(p.first), rotate_point(p.second)});
}

ll dp[7];
vector<ll> dir={1,3,7}, no={0,5,10,15};
vector<ppll> group[7];
map<ppll, pll> id;
int g=-1;
bool vis=false;

void init(){
    if( vis ) return;
    vis=true;
    for( int x1=0 ; x1<=2 ; x1++ ){
        for( int x2=0 ; x2<=2 ; x2++ ){
            for( int y1=0 ; y1<=2 ; y1++ ){
                for( int y2=0 ; y2<=2 ; y2++ ){
                    if( pll{x1,y1}<pll{x2,y2} && __gcd(abs(x1-x2), abs(y1-y2))==1 ){
                        ppll seg={{x1,y1}, {x2,y2}};
                        if( id.count(seg) ) continue;
                        g++;
                        for( int i=0 ; i<4 ; i++ ){
                            group[g].push_back(seg);
                            id[seg]={g, i};
                            seg=rotate(seg);
                        }
                    }
                }
            }
        }
    }
    for( int i=0 ; i<7 ; i++ ){
        dp[i]=(1LL<<(4*i))*3*(1LL<<(12-2*i));
    }
}

vector<pair<pair<int,int>,pair<int,int>>> BuildPattern( int n ){
    init(); n--;
    int g_id=-1;
    ll ans[7]={0};
    vector<pair<pair<int,int>,pair<int,int>>> re;
    for( int i=0 ; i<7 ; i++ ){
        if( n<dp[i] ){
            g_id=i;
            break;
        }
        else{
            n-=dp[i];
        }
    }
    ll x=n%(1LL<<(4*g_id)); n/=(1LL<<(4*g_id));
    ans[g_id]=dir[n%3]; n/=3;
    for( int i=0 ; i<g_id ; i++ ) ans[i]=x%16, x/=16;
    for( int i=g_id+1 ; i<7 ; i++ ) ans[i]=no[n%4], n/=4;
    for( int i=0 ; i<7 ; i++ ){
        for( int j=0 ; j<4 ; j++ ){
            if( ans[i]&(1LL<<j) ) re.push_back(group[i][j]);
        }
    }
    return re;
}

int GetCardNumber( vector<pair< pair<int,int>, pair<int,int> >> v ){
    init();
    ll check[7]={0};
    map<ll,ll> no_mp={{0,0},{5,1},{10,2},{15,3}};
    for( auto u : v ){
        u=ok(u);
        if( id.count(u) ) check[id[u].first]+=(1LL<<id[u].second);
    }
    ll g_id=-1, a=-1, b=-1;
    for( int i=6 ; i>=0 ; i-- ){
        if( !no_mp.count(check[i]) ){
            g_id=i;
            for( int j=0 ; j<3 && a==-1 ; j++ ){
                for( int k=0 ; k<4 ; k++ ){
                    if( (((dir[j]<<k)|(dir[j]>>(4-k)))&15)==check[i] ){
                        a=j, b=k;
                        break;
                    }
                }
            }
            break;
        }
    }

    ll re=0;
    ll ans[7]={0};
    for( int i=0 ; i<7 ; i++ ) ans[i]=(((check[i]>>b)|(check[i]<<(4-b)))&15);
    ll x=0, y=0;
    for( int i=0 ; i<g_id ; i++ ) x+=ans[i]*(1LL<<(4*i));
    for( int i=g_id+1 ; i<7 ; i++ ) y+=no_mp[ans[i]]*(1LL<<(2*(i-g_id-1)));
    re+=x+(1LL<<(4*g_id))*(a+3*y);
    for( int i=0 ; i<g_id ; i++ ) re+=dp[i];
    return re+1;
}