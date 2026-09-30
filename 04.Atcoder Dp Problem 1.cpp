#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '
#define infinity LLONG_MAX

vector<ll> dp , vec;
ll n , k = 2 ;

ll mincost_to_reach(ll idx){
    if(idx == 0) return 0 ;
    if(dp[idx] != -1) return dp[idx] ;

    ll min_cost = infinity ;

    for(ll i = 1 ; i <= k ; i++){
        if(idx>=i){
            min_cost = min(min_cost,mincost_to_reach(idx-i)+abs(vec[idx]-vec[idx-i])) ;
        }
    }

    return dp[idx] = min_cost ;
}

void IcpcDhakaRegionalist2025(){

    cin >> n ; vec.assign(n+1,0) ;

    dp.assign(n+1,-1) ;

    for(int i = 0 ; i < n ; i++) cin >> vec[i] ;
        
    ll ans = mincost_to_reach(n-1) ;

    cout << ans << endl ;

}

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int testcase = 1 ;

    //cin >> testcase ;

    for(int test = 1 ; test <= testcase ; test++){
        IcpcDhakaRegionalist2025() ;
    }    

    return 0 ;
}