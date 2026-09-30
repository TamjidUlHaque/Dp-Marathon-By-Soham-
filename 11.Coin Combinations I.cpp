#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '
#define infinity LLONG_MAX

const ll maxVal = 1e6+5 ;
const ll mod = 1e9+7 ;
ll dp[maxVal] ;

ll number_of_ways(ll remain , vector<ll> &money){
    if(remain == 0) return 1 ;
    if(dp[remain] != -1) return dp[remain] ;

    ll answer = 0 ;
    for(auto &denom:money){
        if(denom <= remain)
            answer += number_of_ways(remain-denom,money) ;
        answer %= mod ;
    }

    return dp[remain] = answer ; 
}

void solve(){
    ll n , amount ; cin >> n >> amount ;

    memset(dp,-1,sizeof(dp)) ;

    vector<ll> money(n) ;
    for(int i = 0 ; i < n ; i++) cin >> money[i] ;

    ll ans = number_of_ways(amount,money) ;

    cout << ans << endl ;
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