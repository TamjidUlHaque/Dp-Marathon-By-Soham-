#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '
#define infinity LLONG_MAX

const int mod = 1e9+7 ;
 
void solve(){
    ll n , amount ; cin >> n >> amount ;
 
    vector<ll> money(n) , no_of_ways(amount+2,0) ;
    for(int i = 0 ; i < n ; i++) cin >> money[i] ;

    no_of_ways[0] = 1 ;
 
    for(auto &coin:money){
        for(int cur = coin ; cur <= amount ; cur++){
            no_of_ways[cur] += no_of_ways[cur-coin] ;
            no_of_ways[cur] %= mod ;
        }
    }
 
    cout << no_of_ways[amount] << endl ;
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