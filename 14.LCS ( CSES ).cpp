#include<bits/stdc++.h>
using namespace std ;

using ll = long long ;
typedef vector<ll> vll ;
typedef pair<ll,ll> pii ;

#define gap ' '
#define infinity LLONG_MAX

 
void solve(){
    int n , m ; cin >> n >> m ;

    vector<int> vec(n+1,-1) , arr(m+1,-2) ;

    for(int i = 1 ; i <= n ; i++) cin >> vec[i] ;
    for(int i = 1 ; i <= m ; i++) cin >> arr[i] ;

    vector<vector<int>> lcs(n+1,vector<int> (m+1,0)) ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(vec[i] == arr[j]){
                lcs[i][j] = 1 + lcs[i-1][j-1] ;
            }else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]) ;
            }
        }
    }

    cout << lcs[n][m] << endl ;

    vector<int> ans ;

    int ptr1 = n , ptr2 = m ;

    while(ptr1 > 0 and ptr2 > 0){
        if(vec[ptr1] == arr[ptr2]){
            ans.push_back(vec[ptr1]) ;
            ptr1-- ; ptr2-- ;
        }else{
            if(lcs[ptr1-1][ptr2] > lcs[ptr1][ptr2-1]){
                ptr1-- ;
            }else{
                ptr2-- ;
            }
        }
    }

    reverse(ans.begin(),ans.end()) ;

    for(auto &elem:ans) cout << elem << ' ' ;

    cout << endl ;
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