#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '

const int garbage = 1e8+7 ;
const int sz = 1e7+3 ;
ll dp[sz] ;

int min_moves_to_reach(int n){

    if(n == 1) return dp[n] = 0 ;
    if(dp[n] != -1) return dp[n] ;
    int min_moves = garbage ;

    if(n > 1) min_moves = min(min_moves,1 + min_moves_to_reach(n-1)) ;
    if(n%2 == 0) min_moves = min(min_moves,1 + min_moves_to_reach(n/2)) ;
    if(n%3 == 0) min_moves = min(min_moves,1 + min_moves_to_reach(n/3)) ;

    return dp[n] = min_moves ;
}
void solve(){
    int n ; cin >> n ; memset(dp,-1,sizeof(dp)) ;
    cout << min_moves_to_reach(n) << endl ;
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