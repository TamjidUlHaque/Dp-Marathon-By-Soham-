#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '
#define infinity LLONG_MAX

const ll maxVal = 1e6+5 ;
ll dp[maxVal] ;

ll min_coins_to_make(ll remain , vector<ll> &money){
    if(remain == 0) return 0 ;
    if(dp[remain] != -1) return dp[remain] ;

    ll answer = maxVal ;

    for(auto &denom:money){
        if(denom <= remain)
            answer = min(answer, 1 + min_coins_to_make(remain-denom,money)) ;
    }

    return dp[remain] = answer ; 
}

void solve(){
    ll n , amount ; cin >> n >> amount ;

    memset(dp,-1,sizeof(dp)) ;

    vector<ll> money(n) ;
    for(int i = 0 ; i < n ; i++) cin >> money[i] ;

    ll ans = min_coins_to_make(amount,money) ;
    if(ans > amount) ans = -1 ;

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