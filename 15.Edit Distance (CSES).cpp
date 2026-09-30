#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '
#define infinity LLONG_MAX

 
void solve(){
    string s , t ; cin >> s >> t ;
    int n = s.size() , m = t.size() ;

    vector<char> vec(n+1,'?') , arr(m+1,'?') ;

    for(int i = 1 ; i <= n ; i++) vec[i] = s[i-1] ;
    for(int i = 1 ; i <= m ; i++) arr[i] = t[i-1] ;

    vector<vector<int>> distance(n+1,vector<int> (m+1,0)) ;

    for(int i = 1 ; i <= n ; i++) distance[i][0] = i ;
    for(int i = 1 ; i <= m ; i++) distance[0][i] = i ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(vec[i] == arr[j]){
                distance[i][j] = distance[i-1][j-1] ;
            }else{
                distance[i][j] = 1 + min({distance[i-1][j],distance[i][j-1],distance[i-1][j-1]}) ;
            }
        }
    }

    cout << distance[n][m] << endl ;
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