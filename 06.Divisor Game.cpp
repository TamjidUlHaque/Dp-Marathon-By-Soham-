class Solution {
public:
    const int N = 1005 ;
    int dp[1005][2] ;

    bool calculate_for(int n , int cur){

        if(n == 1) return dp[n][cur] = false ;
        if(dp[n][cur] != -1) return dp[n][cur] ;

        for(int i = 1 ; i < n ; i++){
            if(n%i == 0){
                if(calculate_for(n-i,cur^1) == false){
                    return dp[n][cur] = true ;
                }
            }
        }

        return dp[n][cur] = false ;
    }

    bool divisorGame(int n) {
        memset(dp,-1,sizeof(dp)) ;
        return calculate_for(n,0) ;
    }
};