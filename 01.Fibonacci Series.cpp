#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '

const ll mod = 1e9+7 ;
const int sz = 2e5+3 ;
ll dp[sz] ;

ll fibonacci(ll n){
    if(n == 0) return dp[n] = 0 ;
    if(n == 1) return dp[n] = 1 ;
    if(dp[n] != -1) return dp[n] ;
    return dp[n] = (fibonacci(n-1) + fibonacci(n-2)) % mod ;
}

void solve(){
    int n ; cin >> n ; memset(dp,-1,sizeof(dp)) ;
    cout << fibonacci(n) << endl ;
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