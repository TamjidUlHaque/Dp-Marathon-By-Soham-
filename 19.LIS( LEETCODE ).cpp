class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() , ans = 1 ;
        vector<int> lis(n,1) ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    lis[i] = max(lis[i],1+lis[j]) ;
                }
            }
            ans = max(ans,lis[i]) ;
        }

        return ans ;
    }
};