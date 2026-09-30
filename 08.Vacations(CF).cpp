#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '
#define infinity LLONG_MAX

void solve(){

    int n ; cin >> n ; vector<int> activity(n+1,0) ;
    for(int i = 1 ; i <= n ; i++) cin >> activity[i] ;

    vector<vector<int>> dp(n+1,vector<int> (3,INT_MAX/2)) ;

    dp[0][0] = 0 ;

    for(int i = 1 ; i <= n ; i++){

        dp[i][0] = 1 + min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) ;

        if(activity[i] == 1 or activity[i] == 3){
            dp[i][1] = min(dp[i-1][2],dp[i-1][0]) ;
        }

        if(activity[i] == 2 or activity[i] == 3){
            dp[i][2] = min(dp[i-1][1],dp[i-1][0]) ;
        }
    }

    cout << *min_element(dp[n].begin(),dp[n].end()) << endl ;
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