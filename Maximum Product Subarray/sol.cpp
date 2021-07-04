class Solution {
public:
    int maxProduct(vector<int>& nums) {
    
        int max_i = nums[0], min_i = nums[0], maxProduct = *max_element(nums.begin(), nums.end());
        
        for(int i=1; i<nums.size(); i++){
            
            if(nums[i] == 0){
                max_i = min_i = 1;
                continue;
            }
            
            int temp = max_i;
            max_i = max({nums[i], nums[i]*max_i, nums[i]*min_i});
            min_i = min({nums[i], nums[i]*temp, nums[i]*min_i});
            
            if(maxProduct < max_i)
                maxProduct = max_i;
        }
        return maxProduct;
    }
};
