#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '
#define infinity LLONG_MAX

const int N = 1e5 ;

void solve(){
    int n ; cin >> n ; 

    vector<ll> vec(N+7,0) ;

    for(int i = 0 ; i < n ; i++){
        ll val ; cin >> val ;
        vec[val] += val ;
    }

    vector<ll> dp = vec ;

    for(int i = 2 ; i <= N ; i++){
        dp[i] += dp[i-2] ;
        dp[i] = max(dp[i],dp[i-1]) ;
    }

    cout << dp[N] << endl ;
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