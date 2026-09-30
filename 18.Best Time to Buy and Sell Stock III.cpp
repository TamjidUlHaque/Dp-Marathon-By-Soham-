class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;
        int dp[n+2][2][3] ;

        for(int i = 0 ; i < 3 ; i++) dp[n][0][i] = dp[n][1][i] = 0 ;
        for(int i = 0 ; i <= n ; i++) dp[i][0][0] = dp[i][1][0] = 0 ;

        for(int i = n-1 ; i >= 0 ; i--){
            for(int k = 1 ; k < 3 ; k++){
                // Buying Time
                dp[i][0][k] = max(dp[i+1][1][k]-prices[i],dp[i+1][0][k]) ;

                // Selling Time
                dp[i][1][k] = max(dp[i+1][0][k-1]+prices[i],dp[i+1][1][k]) ;
            }
        }

        return dp[0][0][2] ;
    }
};
