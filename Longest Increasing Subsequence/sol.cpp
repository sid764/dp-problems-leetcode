class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     
        int n = nums.size();
        int dp[n], ans=1;
        
        for(int i=n-1; i>=0; i--){
            dp[i] = 1;
            for(int j=i+1; j<n; j++){
                if(nums[i] < nums[j] && dp[i] < 1 + dp[j])
                    dp[i] = 1 + dp[j];
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
