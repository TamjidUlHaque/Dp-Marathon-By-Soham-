#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '
#define infinity LLONG_MAX


void solve(){
    ll n ; cin >> n ; 

    vector<pair<ll,ll>> vec(n+2) ;
    for(int i = 1 ; i <= n ; i++) 
        cin >> vec[i].first >> vec[i].second ;

    vec[0].first = vec[0].second = LLONG_MIN/2 ;
    vec[n+1].first = vec[n+1].second = LLONG_MAX/2 ;

    vector<vector<ll>> dp(n+5,vector<ll> (3,0)) ;

    for(int i = 1 ; i <= n ; i++){
        dp[i][0] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) ;
       
        ll posn = vec[i].first ;
        ll len  = vec[i].second ;

        ll prev_posn = vec[i-1].first ;
        ll prev_len  = vec[i-1].second ;

        if(posn - len > prev_posn){
            dp[i][1] = 1 + max(dp[i-1][0],dp[i-1][1]) ;
        }
        if(posn-len > prev_len + prev_posn){
            dp[i][1] = max(dp[i][1],1 + dp[i-1][2]) ;
        }

        ll next_posn = vec[i+1].first ;
        ll next_len = vec[i+1].second ;

        dp[i][2] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) ;

        if(posn + len < next_posn){
            dp[i][2]++ ;
        }
    }

    cout << *max_element(dp[n].begin(),dp[n].end()) << endl ;
}

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int testcase = 1 ;

    //cin >> testcase ;

    for(int test = 1 ; test <= testcase ; test++){
        solve() ;
    }    

    return 0 ;
}