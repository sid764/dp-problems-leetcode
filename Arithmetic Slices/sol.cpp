class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
    
        int n = nums.size();
        
        if(n < 3)
            return 0;
        
        int dp[n], ans = 0;
        dp[0] = dp[1] = 0;
        int d = nums[1] - nums[0];
        
        for(int i=2; i<n; i++){
            
            if(nums[i]-nums[i-1]==d)
                dp[i] = dp[i-1] + 1;
            else{
                dp[i] = 0;
                d = nums[i] - nums[i-1];
            }
            
            ans += dp[i];
        }
        return ans;
    }
};
