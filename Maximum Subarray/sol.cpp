class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
        int maxSum = nums[0], curr_max = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            
            curr_max = max(nums[i], nums[i]+curr_max);
            if(curr_max > maxSum)
                maxSum = curr_max;
        }
        
        return maxSum;
    }
};
