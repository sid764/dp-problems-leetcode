class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        int dp[m][n];
        
        for(int i=m-1; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                
                if(i==m-1)
                    dp[i][j] = triangle[i][j];
                else
                    dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
};
