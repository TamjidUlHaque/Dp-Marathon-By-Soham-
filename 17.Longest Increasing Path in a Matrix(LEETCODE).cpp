class Solution {
public:
    vector<vector<int>> dp ;
    int r , c ;

    int solve(int i , int j,vector<vector<int>>& matrix){
        if(dp[i][j] != -1) return dp[i][j] ;
        int ans = 1 ;

        if(i - 1 >= 0 and matrix[i][j] > matrix[i-1][j]){
            ans = max(ans,1 + solve(i-1,j,matrix)) ;
        }

        if(j - 1 >= 0 and matrix[i][j] > matrix[i][j-1]){
            ans = max(ans,1 + solve(i,j-1,matrix)) ;
        }

        if(i + 1 < r and matrix[i][j] > matrix[i+1][j]){
            ans = max(ans,1 + solve(i+1,j,matrix)) ;
        }

        if(j + 1 < c and matrix[i][j] > matrix[i][j+1]){
            ans = max(ans,1 + solve(i,j+1,matrix)) ;
        }

        return dp[i][j] = ans ;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r = matrix.size() , c = matrix[0].size() ;
        dp.assign(r+1,vector<int> (c+1,-1)) ;

        int ans = 1 ;

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                ans = max(ans,solve(i,j,matrix)) ;
            }
        }

        return ans ;
    }
};