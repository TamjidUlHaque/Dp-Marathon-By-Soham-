#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '

const ll mod = 1e9+7 ;
const int sz = 2010 ;
ll dp[sz][sz] ;

ll nCr(ll n , ll r){
    if(r > n) return 0 ;
    if(r == 0 or r == n) return dp[n][r] = 1 ;
    if(r == 1) return dp[n][r] = n ;
    if(dp[n][r] != -1) return dp[n][r] ;

    ll pick = nCr(n-1,r-1) % mod ;
    ll skip = nCr(n-1,r) % mod ;

    return dp[n][r] = (pick + skip) % mod ;
}

void solve(){
    int n , r ; cin >> n >> r ;
    memset(dp,-1,sizeof(dp)) ;

    cout << nCr(n,r) << endl ;
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